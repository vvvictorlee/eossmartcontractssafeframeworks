

#include "../token/ERC20/StandardToken.hpp"


// mock class using StandardToken
class StandardTokenMock :public StandardToken {

  StandardTokenMock(account_name _initialAccount, uint256_t _initialBalance)  {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
