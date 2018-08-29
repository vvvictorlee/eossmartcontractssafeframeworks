


#include "../payment/ConditionalEscrow.hpp"


// mock class using ConditionalEscrow
class ConditionalEscrowMock :public ConditionalEscrow {
  // mapping(account_name => bool) public allowed;
public:
  void setAllowed(account_name _payee, bool _allowed)  {
    allowed[_payee] = _allowed;
  }

  bool withdrawalAllowed(account_name _payee)
  //  public view returns (bool) 
   {
    return allowed[_payee];
  }
}
