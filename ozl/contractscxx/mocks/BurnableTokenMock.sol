pragma solidity ^0.4.24;

import "../token/ERC20/BurnableToken.sol";


contract BurnableTokenMock is BurnableToken {

  constructor(account_name _initialAccount, uint _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
