// 

#include "./Ownable.hpp";


/**
 * @title Contracts that should not own Contracts
 * @author Remco Bloemen <remco@2π.com>
 * @dev Should contracts (anything Ownable) end up being owned by this contract, it allows the owner
 * of this class to reclaim ownership of the contracts.
 */
class HasNoContracts :public Ownable {

  /**
   * @dev Reclaim ownership of Ownable contracts
   * @param _contractAddr The account_name of the Ownable to be reclaimed.
   */
  void reclaimContract(account_name _contractAddr)
  //  external onlyOwner
    {
    Ownable contractInst = Ownable(_contractAddr);
    contractInst.transferOwnership(owner);
  }
}
