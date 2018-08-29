

import {Bounty, Target} from "../../contracts/Bounty.hpp"


class SecureTargetMock is Target {
  function checkInvariant() public returns(bool) {
    return true;
  }
}


class SecureTargetBounty is Bounty {
  function deployContract() internal returns (address) {
    return new SecureTargetMock();
  }
}
