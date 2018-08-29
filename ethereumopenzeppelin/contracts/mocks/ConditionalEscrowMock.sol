


#include "../payment/ConditionalEscrow.hpp"


// mock class using ConditionalEscrow
class ConditionalEscrowMock is ConditionalEscrow {
  mapping(address => bool) public allowed;

  function setAllowed(address _payee, bool _allowed) public {
    allowed[_payee] = _allowed;
  }

  function withdrawalAllowed(address _payee) public view returns (bool) {
    return allowed[_payee];
  }
}
