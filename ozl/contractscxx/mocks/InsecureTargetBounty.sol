pragma solidity ^0.4.24;

import {Bounty, Target} from "../../contracts/Bounty.sol";


contract InsecureTargetMock is Target {
  function checkInvariant() public returns(bool) {
    return false;
  }
}


contract InsecureTargetBounty is Bounty {
  function deployContract() internal returns (account_name) {
    return new InsecureTargetMock();
  }
}
