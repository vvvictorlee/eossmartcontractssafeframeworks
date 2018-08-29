

import {Bounty, Target} from "../../contracts/Bounty.hpp"


class InsecureTargetMock is Target {
  function checkInvariant() public returns(bool) {
    return false;
  }
}


class InsecureTargetBounty is Bounty {
  function deployContract() internal returns (address) {
    return new InsecureTargetMock();
  }
}
