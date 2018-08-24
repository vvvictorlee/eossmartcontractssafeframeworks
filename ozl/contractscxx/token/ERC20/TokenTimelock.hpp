#include <eosiolib/eosio.hpp>

#include "./SafeERC20.hpp";


/**
 * @title TokenTimelock
 * @dev TokenTimelock is a token holder class that will allow a
 * beneficiary to extract the tokens after a given release time
 */
class TokenTimelock {
  // using SafeERC20 for ERC20Basic;

  // ERC20 basic token class being held
  ERC20Basic  token;

  // beneficiary of tokens after they are released
  account_name  beneficiary;

  // timestamp when token release is enabled
  uint256_t  releaseTime;

  TokenTimelock(
    ERC20Basic _token,
    account_name _beneficiary,
    uint256_t _releaseTime
  )
    // public
  {
    // solium-disable-next-line security/no-block-members
    eosio_assert(_releaseTime > block.timestamp);
    token = _token;
    beneficiary = _beneficiary;
    releaseTime = _releaseTime;
  }

  /**
   * @notice Transfers tokens held by timelock to beneficiary.
   */
  void release()  {
    // solium-disable-next-line security/no-block-members
    eosio_assert(block.timestamp >= releaseTime);

    uint256_t amount = token.balanceOf(account_name(this));
    eosio_assert(amount > 0);

    token.safeTransfer(beneficiary, amount);
  }
}
