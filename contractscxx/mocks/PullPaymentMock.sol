


#include "../payment/PullPayment.hpp"


// mock class using PullPayment
class PullPaymentMock is PullPayment {

  constructor() public payable { }

  // test helper function to call asyncTransfer
  function callTransfer(address _dest, uint256 _amount) public {
    asyncTransfer(_dest, _amount);
  }

}
