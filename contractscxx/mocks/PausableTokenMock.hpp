

#include "../token/ERC20/PausableToken.hpp"


// mock class using PausableToken
class PausableTokenMock :public PausableToken {

  PausableTokenMock(account_name _initialAccount, uint _initialBalance)  {
    balances[_initialAccount] = _initialBalance;
  }

}
