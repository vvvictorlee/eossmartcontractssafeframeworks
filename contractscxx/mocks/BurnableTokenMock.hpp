

#include "../token/ERC20/BurnableToken.hpp"


class BurnableTokenMock :public BurnableToken {

  BurnableTokenMock(account_name _initialAccount, uint _initialBalance)  {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
