// 


#include "./Ownable.hpp";


/**
 * @title Claimable
 * @dev Extension for the Ownable contract, where the ownership needs to be claimed.
 * This allows the new owner to accept the transfer.
 */
class Claimable :public Ownable {
  public:
  account_name  pendingOwner;

  /**
   * @dev Modifier throws if called by any account other than the pendingOwner.
   */
  // modifier onlyPendingOwner() {
  //   eosio_assert(msg.sender == pendingOwner);
  //   _;
  // }

  /**
   * @dev Allows the current owner to set the pendingOwner account_name.
   * @param newOwner The account_name to transfer ownership to.
   */
  void transferOwnership(account_name newOwner) 
  // public onlyOwner 
  {
    pendingOwner = newOwner;
  }

  /**
   * @dev Allows the pendingOwner account_name to finalize the transfer.
   */
  void claimOwnership() 
  // public onlyPendingOwner 
  {
    // emit OwnershipTransferred(owner, pendingOwner);
    owner = pendingOwner;
    pendingOwner = account_name(0);
  }
}
