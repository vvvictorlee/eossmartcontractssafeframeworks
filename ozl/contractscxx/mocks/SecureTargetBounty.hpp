

// import {Bounty, Target} from 
#include "../../contracts/Bounty.hpp"


class SecureTargetMock :public Target {
  bool checkInvariant() 
  // public returns(bool)
   {
    return true;
  }
}


class SecureTargetBounty :public Bounty {
  account_name deployContract() 
  // internal returns (account_name) 
  {
    return new SecureTargetMock();
  }
}
