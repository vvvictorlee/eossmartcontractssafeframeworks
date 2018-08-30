// 

#include "./Ownable.hpp"
include "../token/ERC20/ERC20Basic.hpp"
include "../token/ERC20/SafeERC20.hpp"


/**
 * @title Contracts that should be able to recover tokens
 * @author SylTi
 * @dev This allow a class to recover any ERC20 token received in a class by transferring the balance to the class owner.
 * This will prevent any accidental loss of tokens.
 */
class CanReclaimToken :public Ownable {
  // using SafeERC20 for ERC20Basic;

  /**
   * @dev Reclaim all ERC20Basic compatible tokens
   * @param _token ERC20Basic The account_name of the token contract
   */
  void reclaimToken(ERC20Basic _token) 
  // external onlyOwner 
  {
    uint256_t balance = _token.balanceOf(this);
    _token.safeTransfer(owner, balance);
  }

}
