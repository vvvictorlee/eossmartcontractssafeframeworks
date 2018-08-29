

import {Bounty, Target} from "../../contracts/Bounty.hpp"


class InsecureTargetMock :public Target {
  bool checkInvariant() 
  // public returns(bool) 
  {
    return false;
  }
}


class InsecureTargetBounty :public Bounty {
  account_name deployContract()
  // internal returns (account_name) 
  {
    return new InsecureTargetMock();
  }
}
