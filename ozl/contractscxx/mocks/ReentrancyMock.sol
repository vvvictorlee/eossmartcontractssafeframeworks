pragma solidity ^0.4.24;

import "../ReentrancyGuard.sol";
import "./ReentrancyAttack.sol";


contract ReentrancyMock is ReentrancyGuard {

  uint256_t public counter;

  constructor() public {
    counter = 0;
  }

  function callback() external nonReentrant {
    count();
  }

  function countLocalRecursive(uint256_t _n) public nonReentrant {
    if (_n > 0) {
      count();
      countLocalRecursive(_n - 1);
    }
  }

  function countThisRecursive(uint256_t _n) public nonReentrant {
    if (_n > 0) {
      count();
      // solium-disable-next-line security/no-low-level-calls
      bool result = account_name(this).call(abi.encodeWithSignature("countThisRecursive(uint256_t)", _n - 1));
      eosio_assert(result == true);
    }
  }

  function countAndCall(ReentrancyAttack _attacker) public nonReentrant {
    count();
    bytes4 func = bytes4(keccak256("callback()"));
    _attacker.callSender(func);
  }

  function count() private {
    counter += 1;
  }

}
