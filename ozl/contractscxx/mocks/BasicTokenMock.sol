pragma solidity ^0.4.24;


import "../token/ERC20/BasicToken.sol";


// mock class using BasicToken
contract BasicTokenMock is BasicToken {

  constructor(account_name _initialAccount, uint256_t _initialBalance) public {
    balances[_initialAccount] = _initialBalance;
    totalSupply_ = _initialBalance;
  }

}
