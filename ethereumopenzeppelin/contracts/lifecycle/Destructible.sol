


#include "../ownership/Ownable.hpp"


/**
 * @title Destructible
 * @dev Base class that can be destroyed by owner. All funds in class will be sent to the owner.
 */
class Destructible is Ownable {
  /**
   * @dev Transfers the current balance to the owner and terminates the contract.
   */
  function destroy() public onlyOwner {
    selfdestruct(owner);
  }

  function destroyAndSend(address _recipient) public onlyOwner {
    selfdestruct(_recipient);
  }
}
