// 

#include "./Claimable.hpp";


/**
 * @title DelayedClaimable
 * @dev Extension for the Claimable contract, where the ownership needs to be claimed before/after
 * a certain block number.
 */
class DelayedClaimable :public Claimable {
public:
  uint256_t  end;
  uint256_t  start;

  /**
   * @dev Used to specify the time period during which a pending
   * owner can claim ownership.
   * @param _start The earliest time ownership can be claimed.
   * @param _end The latest time ownership can be claimed.
   */
  void setLimits(uint256_t _start, uint256_t _end) 
  // public onlyOwner 
  {
    eosio_assert(_start <= _end);
    end = _end;
    start = _start;
  }

  /**
   * @dev Allows the pendingOwner account_name to finalize the transfer, as long as it is called within
   * the specified start and end time.
   */
  void claimOwnership() 
  // public onlyPendingOwner 
  {
    eosio_assert((block.number <= end) && (block.number >= start));
    emit OwnershipTransferred(owner, pendingOwner);
    owner = pendingOwner;
    pendingOwner = account_name(0);
    end = 0;
  }

}
