

#include "../token/ERC20/BasicToken.hpp"


class ERC223ContractInterface {
  void tokenFallback(account_name _from, uint256_t _value, bytes _data) ;
}


class ERC223TokenMock :public BasicToken {

  ERC223TokenMock(account_name _initialAccount, uint256_t _initialBalance)  {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

  // ERC223 compatible transfer function (except the name)
  bool transferERC223(account_name _to, uint256_t _value, bytes _data)
  //  public
  //   returns (bool success)
  {
    transfer(_to, _value);
    bool isContract = false;
    // solium-disable-next-line security/no-inline-assembly
    assembly {
      isContract := not(iszero(extcodesize(_to)))
    }
    if (isContract) {
      ERC223ContractInterface receiver = ERC223ContractInterface(_to);
      receiver.tokenFallback(msg.sender, _value, _data);
    }
    return true;
  }
}
