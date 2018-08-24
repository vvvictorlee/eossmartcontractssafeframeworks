#include <eosiolib/eosio.hpp>


#include "../ownership/Ownable.hpp";


/**
 * @title Pausable
 * @dev Base contract which allows children to implement an emergency stop mechanism.
 */
class Pausable : Ownable {
  // event Pause();
  // event Unpause();

  bool  paused = false;


  /**
   * @dev Modifier to make a function callable only when the contract is not paused.
   */
  // modifier whenNotPaused() {
  //   eosio_assert(!paused);
  //   _;
  // }

  // /**
  //  * @dev Modifier to make a function callable only when the contract is paused.
  //  */
  // modifier whenPaused() {
  //   eosio_assert(paused);
  //   _;
  // }

  /**
   * @dev called by the owner to pause, triggers stopped state
   */
  void pause()
  //  public onlyOwner whenNotPaused 
  {
    paused = true;
    // emit Pause();
  }

  /**
   * @dev called by the owner to unpause, returns to normal state
   */
  void unpause() 
  // public onlyOwner whenPaused
   {
    paused = false;
    // emit Unpause();
  }
}
