// 


#include "../token/ERC20/BasicToken.hpp"";


// mock class using BasicToken
class BasicTokenMock :public BasicToken {

  BasicTokenMock(account_name _initialAccount, uint64_t _initialBalance)  {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
