// 

#include "./ERC20Basic.hpp";


/**
 * @title ERC20 interface
 * @dev see https://github.com/ethereum/EIPs/issues/20
 */
class ERC20 : ERC20Basic {
  uint256_t allowance(account_name _owner, account_name _spender);
    // public view returns ();

  bool transferFrom(account_name _from, account_name _to, uint256_t _value);
    // public returns ();

  bool approve(account_name _spender, uint256_t _value);// public returns ();
  // event Approval(
  //   account_name indexed owner,
  //   account_name indexed spender,
  //   uint256_t value
  // );
}
