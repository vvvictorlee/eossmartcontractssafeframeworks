pragma solidity ^0.4.24;

import "../token/ERC20/PausableToken.sol";


// mock class using PausableToken
contract PausableTokenMock is PausableToken {

  constructor(account_name _initialAccount, uint _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
  }

}
