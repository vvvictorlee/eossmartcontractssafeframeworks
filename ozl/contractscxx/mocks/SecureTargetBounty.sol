pragma solidity ^0.4.24;

import {Bounty, Target} from "../../contracts/Bounty.sol";


contract SecureTargetMock is Target {
  function checkInvariant() public returns(bool) {
    return true;
  }
}


contract SecureTargetBounty is Bounty {
  function deployContract() internal returns (account_name) {
    return new SecureTargetMock();
  }
}
