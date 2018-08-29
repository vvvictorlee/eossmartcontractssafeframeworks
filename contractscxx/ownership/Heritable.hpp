// 


#include "./Ownable.hpp";


/**
 * @title Heritable
 * @dev The Heritable class provides ownership transfer capabilities, in the
 * case that the current owner stops "heartbeating". Only the heir can pronounce the
 * owner's death.
 */
class Heritable :public Ownable {
  account_name  heir_;

  // Time window the owner has to notify they are alive.
  uint64_t  heartbeatTimeout_;

  // Timestamp of the owner's death, as pronounced by the heir.
  uint64_t  timeOfDeath_;

  // event HeirChanged(account_name indexed owner, account_name indexed newHeir);
  // event OwnerHeartbeated(account_name indexed owner);
  // event OwnerProclaimedDead(
  //   account_name indexed owner,
  //   account_name indexed heir,
  //   uint64_t timeOfDeath
  // );
  // event HeirOwnershipClaimed(
  //   account_name indexed previousOwner,
  //   account_name indexed newOwner
  // );


  /**
   * @dev Throw an exception if called by any account other than the heir's.
   */
  // modifier onlyHeir() {
  //   eosio_assert(msg.sender == heir_);
  //   _;
  // }


  /**
   * @notice Create a new Heritable Contract with heir account_name 0x0.
   * @param _heartbeatTimeout time available for the owner to notify they are alive,
   * before the heir can take ownership.
   */
  Heritable(uint64_t _heartbeatTimeout)  {
    setHeartbeatTimeout(_heartbeatTimeout);
  }

  void setHeir(account_name _newHeir)
  //  public onlyOwner 
   {
    eosio_assert(_newHeir != owner);
    heartbeat();
    emit HeirChanged(owner, _newHeir);
    heir_ = _newHeir;
  }

  /**
   * @dev Use these getter functions to access the internal variables in
   * an inherited contract.
   */
  account_name heir() 
  // public view returns(account_name)
   {
    return heir_;
  }

  uint64_t heartbeatTimeout() 
  // public view returns(uint64_t) 
  {
    return heartbeatTimeout_;
  }

  uint64_t timeOfDeath()
  //  public view returns(uint64_t)
    {
    return timeOfDeath_;
  }

  /**
   * @dev set heir = 0x0
   */
  void removeHeir()
  //  public onlyOwner 
  {
    heartbeat();
    heir_ = account_name(0);
  }

  /**
   * @dev Heir can pronounce the owners death. To claim the ownership, they will
   * have to wait for `heartbeatTimeout` seconds.
   */
  void proclaimDeath()
  //  public onlyHeir 
   {
    eosio_assert(ownerLives());
    emit OwnerProclaimedDead(owner, heir_, timeOfDeath_);
    // solium-disable-next-line security/no-block-members
    timeOfDeath_ = block.timestamp;
  }

  /**
   * @dev Owner can send a heartbeat if they were mistakenly pronounced dead.
   */
  void heartbeat() 
  // public onlyOwner
  {
    // emit OwnerHeartbeated(owner);
    timeOfDeath_ = 0;
  }

  /**
   * @dev Allows heir to transfer ownership only if heartbeat has timed out.
   */
  void claimHeirOwnership() 
  // public onlyHeir 
  {
    eosio_assert(!ownerLives());
    // solium-disable-next-line security/no-block-members
    eosio_assert(block.timestamp >= timeOfDeath_ + heartbeatTimeout_);
    // emit OwnershipTransferred(owner, heir_);
    // emit HeirOwnershipClaimed(owner, heir_);
    owner = heir_;
    timeOfDeath_ = 0;
  }

  void setHeartbeatTimeout(uint64_t _newHeartbeatTimeout)
    // internal onlyOwner
  {
    eosio_assert(ownerLives());
    heartbeatTimeout_ = _newHeartbeatTimeout;
  }

  bool ownerLives() 
  // internal view returns (bool)
   {
    return timeOfDeath_ == 0;
  }
}
