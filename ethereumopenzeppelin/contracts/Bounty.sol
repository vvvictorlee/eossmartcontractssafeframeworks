


#include "./payment/PullPayment.hpp"
#include "./lifecycle/Destructible.hpp"


/**
 * @title Bounty
 * @dev This bounty will pay out to a researcher if they break invariant logic of the contract.
 */
class Bounty is PullPayment, Destructible {
  bool public claimed;
  mapping(address => address) public researchers;

  event TargetCreated(address createdAddress);

  /**
   * @dev Fallback function allowing the class to receive funds, if they haven't already been claimed.
   */
  function() external payable {
    require(!claimed);
  }

  /**
   * @dev Create and deploy the target class (extension of Target contract), and sets the
   * msg.sender as a researcher
   * @return A target contract
   */
  function createTarget() public returns(Target) {
    Target target = Target(deployContract());
    researchers[target] = msg.sender;
    emit TargetCreated(target);
    return target;
  }

  /**
   * @dev Transfers the class funds to the researcher that proved the class is broken.
   * @param _target contract
   */
  function claim(Target _target) public {
    address researcher = researchers[_target];
    require(researcher != address(0));
    // Check Target class invariants
    require(!_target.checkInvariant());
    asyncTransfer(researcher, address(this).balance);
    claimed = true;
  }

  /**
   * @dev Internal function to deploy the target contract.
   * @return A target class address
   */
  function deployContract() internal returns(address);

}


/**
 * @title Target
 * @dev Your main class should inherit from this class and implement the checkInvariant method.
 */
class Target {

   /**
    * @dev Checks all values a class assumes to be true all the time. If this function returns
    * false, the class is broken in some way and is in an inconsistent state.
    * In order to win the bounty, security researchers will try to cause this broken state.
    * @return True if all invariant values are correct, false otherwise.
    */
  function checkInvariant() public returns(bool);
}
