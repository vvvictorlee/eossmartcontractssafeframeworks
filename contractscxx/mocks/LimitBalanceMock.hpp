


#include "../LimitBalance.hpp"


// mock class using LimitBalance
class LimitBalanceMock :public LimitBalance(1000) {

  void limitedDeposit()
  //  public payable limitedPayable
    {
  }

}
