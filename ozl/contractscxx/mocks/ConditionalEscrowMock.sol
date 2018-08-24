pragma solidity ^0.4.24;


import "../payment/ConditionalEscrow.sol";


// mock class using ConditionalEscrow
contract ConditionalEscrowMock is ConditionalEscrow {
  mapping(account_name => bool) public allowed;

  function setAllowed(account_name _payee, bool _allowed) public {
    allowed[_payee] = _allowed;
  }

  function withdrawalAllowed(account_name _payee) public view returns (bool) {
    return allowed[_payee];
  }
}
