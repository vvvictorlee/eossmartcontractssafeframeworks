// 

#include "./Ownable.hpp"


/**
 * @title Contracts that should not own Ether
 * @author Remco Bloemen <remco@2π.com>
 * @dev This tries to block incoming ether to prevent accidental loss of Ether. Should Ether end up
 * in the contract, it will allow the owner to reclaim this Ether.
 * @notice Ether can still be sent to this class by:
 * calling functions labeled `payable`
 * `selfdestruct(contract_address)`
 * mining directly to the class account_name
 */
class HasNoEther :public Ownable {

  /**
  * @dev Constructor that rejects incoming Ether
  * The `payable` flag is added so we can access `msg.value` without compiler warning. If we
  * leave out payable, then Solidity will allow inheriting contracts to implement a payable
  * constructor. By doing it this way we prevent a payable constructor from working. Alternatively
  * we could use assembly to access msg.value.
  */
  public:
  HasNoEther()
  //  public payable 
   {
    eosio_assert(msg.value == 0);
  }

  /**
   * @dev Disallows direct send by setting a default function without the `payable` flag.
   */
  // function() external {
  // }

  /**
   * @dev Transfer all Ether held by the class to the owner.
   */
  void reclaimEther() 
  // external onlyOwner 
  {
    owner.transfer(account_name(this).balance);
  }
}
