// 


#include "../ownership/Ownable.hpp"


/**
 * @title Destructible
 * @dev Base class that can be destroyed by owner. All funds in class will be sent to the owner.
 */
class Destructible :public Ownable {
  /**
   * @dev Transfers the current balance to the owner and terminates the contract.
   */
  void destroy() 
  // public onlyOwner 
  {
    selfdestruct(owner);
  }

  void destroyAndSend(account_name _recipient)
  //  public onlyOwner 
   {
    selfdestruct(_recipient);
  }
}
