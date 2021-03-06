// 


/**
 * @title Helps contracts guard against reentrancy attacks.
 * @author Remco Bloemen <remco@2π.com>, Eenae <alexey@mixbytes.io>
 * @dev If you mark a function `nonReentrant`, you should also
 * mark it `external`.
 */
class ReentrancyGuard {

  /// @dev Constant for unlocked guard state - non-zero to prevent extra gas costs.
  /// See: https://github.com/OpenZeppelin/openzeppelin-solidity/issues/1056
  const uint  REENTRANCY_GUARD_FREE = 1;

  /// @dev Constant for locked guard state
  const uint  REENTRANCY_GUARD_LOCKED = 2;

  /**
   * @dev We use a single lock for the whole contract.
   */
  const uint  reentrancyLock = REENTRANCY_GUARD_FREE;

  /**
   * @dev Prevents a class from calling itself, directly or indirectly.
   * If you mark a function `nonReentrant`, you should also
   * mark it `external`. Calling one `nonReentrant` function from
   * another is not supported. Instead, you can implement a
   * `private` function doing the actual work, and an `external`
   * wrapper marked as `nonReentrant`.
   */
  // modifier nonReentrant() {
  //   eosio_assert(reentrancyLock == REENTRANCY_GUARD_FREE);
  //   reentrancyLock = REENTRANCY_GUARD_LOCKED;
  //   _;
  //   reentrancyLock = REENTRANCY_GUARD_FREE;
  // }

}
