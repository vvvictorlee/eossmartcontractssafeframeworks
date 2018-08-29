


#include "../token/ERC20/BasicToken.hpp"


// mock class using BasicToken
class BasicTokenMock is BasicToken {

  constructor(address _initialAccount, uint256 _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
