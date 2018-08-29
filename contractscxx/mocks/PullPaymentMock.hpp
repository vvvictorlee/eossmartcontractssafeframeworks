


#include "../payment/PullPayment.hpp"


// mock class using PullPayment
class PullPaymentMock :public PullPayment {

  PullPaymentMock() 
  // public payable 
  { }

  // test helper function to call asyncTransfer
  void callTransfer(account_name _dest, uint256_t _amount)  {
    asyncTransfer(_dest, _amount);
  }

}
