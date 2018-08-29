

#include "../token/ERC20/PausableToken.hpp"


// mock class using PausableToken
class PausableTokenMock is PausableToken {

  constructor(address _initialAccount, uint _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
  }

}
