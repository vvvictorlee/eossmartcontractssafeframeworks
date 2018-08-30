#include <eosiolib/eosio.hpp>

#include "./ERC20Basic.hpp"
#include "./ERC20.hpp"


/**
 * @title SafeERC20
 * @dev Wrappers around ERC20 operations that throw on failure.
 * To use this library you can add a `using SafeERC20 for ERC20;` statement to your class,
 * which allows you to call the safe operations as `token.safeTransfer(...)`, etc.
 */
class SafeERC20 {
  void safeTransfer(
    ERC20Basic _token,
    account_name _to,
    uint256_t _value
  )
    // internal
  {
    eosio_assert(_token.transfer(_to, _value));
  }

  void safeTransferFrom(
    ERC20 _token,
    account_name _from,
    account_name _to,
    uint256_t _value
  )
    // internal
  {
    eosio_assert(_token.transferFrom(_from, _to, _value));
  }

  void safeApprove(
    ERC20 _token,
    account_name _spender,
    uint256_t _value
  )
    // internal
  {
    eosio_assert(_token.approve(_spender, _value));
  }
}
