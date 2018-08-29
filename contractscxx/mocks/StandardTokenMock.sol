

#include "../token/ERC20/StandardToken.hpp"


// mock class using StandardToken
class StandardTokenMock is StandardToken {

  constructor(address _initialAccount, uint256 _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
