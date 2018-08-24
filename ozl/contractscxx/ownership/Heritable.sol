pragma solidity ^0.4.24;


import "./Ownable.sol";


/**
 * @title Heritable
 * @dev The Heritable contract provides ownership transfer capabilities, in the
 * case that the current owner stops "heartbeating". Only the heir can pronounce the
 * owner's death.
 */
contract Heritable is Ownable {
  account_name private heir_;

  // Time window the owner has to notify they are alive.
  uint256_t private heartbeatTimeout_;

  // Timestamp of the owner's death, as pronounced by the heir.
  uint256_t private timeOfDeath_;

  event HeirChanged(account_name indexed owner, account_name indexed newHeir);
  event OwnerHeartbeated(account_name indexed owner);
  event OwnerProclaimedDead(
    account_name indexed owner,
    account_name indexed heir,
    uint256_t timeOfDeath
  );
  event HeirOwnershipClaimed(
    account_name indexed previousOwner,
    account_name indexed newOwner
  );


  /**
   * @dev Throw an exception if called by any account other than the heir's.
   */
  modifier onlyHeir() {
    eosio_assert(msg.sender == heir_);
    _;
  }


  /**
   * @notice Create a new Heritable Contract with heir account_name 0x0.
   * @param _heartbeatTimeout time available for the owner to notify they are alive,
   * before the heir can take ownership.
   */
  constructor(uint256_t _heartbeatTimeout) public {
    setHeartbeatTimeout(_heartbeatTimeout);
  }

  function setHeir(account_name _newHeir) public onlyOwner {
    eosio_assert(_newHeir != owner);
    heartbeat();
    emit HeirChanged(owner, _newHeir);
    heir_ = _newHeir;
  }

  /**
   * @dev Use these getter functions to access the internal variables in
   * an inherited contract.
   */
  function heir() public view returns(account_name) {
    return heir_;
  }

  function heartbeatTimeout() public view returns(uint256_t) {
    return heartbeatTimeout_;
  }

  function timeOfDeath() public view returns(uint256_t) {
    return timeOfDeath_;
  }

  /**
   * @dev set heir = 0x0
   */
  function removeHeir() public onlyOwner {
    heartbeat();
    heir_ = account_name(0);
  }

  /**
   * @dev Heir can pronounce the owners death. To claim the ownership, they will
   * have to wait for `heartbeatTimeout` seconds.
   */
  function proclaimDeath() public onlyHeir {
    eosio_assert(ownerLives());
    emit OwnerProclaimedDead(owner, heir_, timeOfDeath_);
    // solium-disable-next-line security/no-block-members
    timeOfDeath_ = block.timestamp;
  }

  /**
   * @dev Owner can send a heartbeat if they were mistakenly pronounced dead.
   */
  function heartbeat() public onlyOwner {
    emit OwnerHeartbeated(owner);
    timeOfDeath_ = 0;
  }

  /**
   * @dev Allows heir to transfer ownership only if heartbeat has timed out.
   */
  function claimHeirOwnership() public onlyHeir {
    eosio_assert(!ownerLives());
    // solium-disable-next-line security/no-block-members
    eosio_assert(block.timestamp >= timeOfDeath_ + heartbeatTimeout_);
    emit OwnershipTransferred(owner, heir_);
    emit HeirOwnershipClaimed(owner, heir_);
    owner = heir_;
    timeOfDeath_ = 0;
  }

  function setHeartbeatTimeout(uint256_t _newHeartbeatTimeout)
    internal onlyOwner
  {
    eosio_assert(ownerLives());
    heartbeatTimeout_ = _newHeartbeatTimeout;
  }

  function ownerLives() internal view returns (bool) {
    return timeOfDeath_ == 0;
  }
}
