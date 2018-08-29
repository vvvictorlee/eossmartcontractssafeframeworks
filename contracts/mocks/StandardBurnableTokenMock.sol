

#include "../token/ERC20/StandardBurnableToken.hpp"


class StandardBurnableTokenMock is StandardBurnableToken {

  constructor(address _initialAccount, uint _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
