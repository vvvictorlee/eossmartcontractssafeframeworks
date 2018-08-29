

#include "../token/ERC20/BurnableToken.hpp"


class BurnableTokenMock is BurnableToken {

  constructor(address _initialAccount, uint _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
