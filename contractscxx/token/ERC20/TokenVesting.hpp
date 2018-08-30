/* solium-disable security/no-block-members */

#include <eosiolib/eosio.hpp>

#include "./ERC20Basic.hpp"
#include "./SafeERC20.hpp"
#include "../../ownership/Ownable.hpp"
#include "../../math/SafeMath.hpp"

/**
 * @title TokenVesting
 * @dev A token holder class that can release its token balance gradually like a
 * typical vesting scheme, with a cliff and vesting period. Optionally revocable by the
 * owner.
 */
class TokenVesting : Ownable
{
  // using SafeMath for uint256_t;
  // using SafeERC20 for ERC20Basic;

  // event Released(uint256_t amount);
  // event Revoked();

  // beneficiary of tokens after they are released
  account_name beneficiary;

  uint256_t cliff;
  uint256_t start;
  uint256_t duration;

  bool revocable;

  // mapping (account_name => uint256_t) public released;
  // mapping (account_name => bool) public revoked;
  struct released
  {
    account_name name;
    uint256_t balance;
    uint64_t primary_key() const { return name; }
  };
  struct revoked
  {
    account_name name;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(released), released> released;
  typedef eosio::multi_index<N(revoked), revoked> revoked;

  /**
   * @dev Creates a vesting class that vests its balance of any ERC20 token to the
   * _beneficiary, gradually in a linear fashion until _start + _duration. By then all
   * of the balance will have vested.
   * @param _beneficiary account_name of the beneficiary to whom vested tokens are transferred
   * @param _cliff duration in seconds of the cliff in which tokens will begin to vest
   * @param _start the time (as Unix time) at which point vesting starts
   * @param _duration duration in seconds of the period in which the tokens will vest
   * @param _revocable whether the vesting is revocable or not
   */
  TokenVesting(
      account_name _beneficiary,
      uint256_t _start,
      uint256_t _cliff,
      uint256_t _duration,
      bool _revocable)
  // public
  {
    eosio_assert(_beneficiary != account_name(0));
    eosio_assert(_cliff <= _duration);

    beneficiary = _beneficiary;
    revocable = _revocable;
    duration = _duration;
    cliff = _start.add(_cliff);
    start = _start;
  }

  /**
   * @notice Transfers vested tokens to beneficiary.
   * @param _token ERC20 token which is being vested
   */
  void release(ERC20Basic _token)
  {
    uint256_t unreleased = releasableAmount(_token);

    eosio_assert(unreleased > 0);

    released[_token] = released[_token].add(unreleased);

    _token.safeTransfer(beneficiary, unreleased);

    // emit Released(unreleased);
  }

  /**
   * @notice Allows the owner to revoke the vesting. Tokens already vested
   * remain in the class, the rest are returned to the owner.
   * @param _token ERC20 token which is being vested
   */
  void revoke(ERC20Basic _token)
  //  public onlyOwner
  {
    eosio_assert(revocable);
    eosio_assert(!revoked[_token]);

    uint256_t balance = _token.balanceOf(account_name(this));

    uint256_t unreleased = releasableAmount(_token);
    uint256_t refund = balance.sub(unreleased);

    revoked[_token] = true;

    _token.safeTransfer(owner, refund);

    // emit Revoked();
  }

  /**
   * @dev Calculates the amount that has already vested but hasn't been released yet.
   * @param _token ERC20 token which is being vested
   */
  uint256_t releasableAmount(ERC20Basic _token)
  // public view returns (uint256_t)
  {
    return vestedAmount(_token).sub(released[_token]);
  }

  /**
   * @dev Calculates the amount that has already vested.
   * @param _token ERC20 token which is being vested
   */
  uint256_t vestedAmount(ERC20Basic _token)
  //  public view returns (uint256_t)
  {
    uint256_t currentBalance = _token.balanceOf(account_name(this));
    uint256_t totalBalance = currentBalance.add(released[_token]);

    if (block.timestamp < cliff)
    {
      return 0;
    }
    else if (block.timestamp >= start.add(duration) || revoked[_token])
    {
      return totalBalance;
    }
    else
    {
      return totalBalance.mul(block.timestamp.sub(start)).div(duration);
    }
  }
}
