


#include "../LimitBalance.hpp"


// mock class using LimitBalance
class LimitBalanceMock is LimitBalance(1000) {

  function limitedDeposit() public payable limitedPayable {
  }

}
