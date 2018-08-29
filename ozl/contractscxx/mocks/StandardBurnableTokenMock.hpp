

#include "../token/ERC20/StandardBurnableToken.hpp"


class StandardBurnableTokenMock :public StandardBurnableToken {

  StandardBurnableTokenMock(account_name _initialAccount, uint _initialBalance)  {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
