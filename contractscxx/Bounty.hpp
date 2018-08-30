// 


#include "./payment/PullPayment.hpp"
#include "./lifecycle/Destructible.hpp"


/**
 * @title Bounty
 * @dev This bounty will pay out to a researcher if they break invariant logic of the contract.
 */
class Bounty :public PullPayment, public  Destructible {
  bool public claimed;
  // mapping(account_name => account_name) public researchers;
 struct researchersx
  {
    account_name name;
    account_name sname;


    uint64_t primary_key() const { return name; }
  };

typedef eosio::multi_index<N(researchers), researchersx> researchers;
  // event TargetCreated(account_name createdAddress);

  /**
   * @dev Fallback function allowing the class to receive funds, if they haven't already been claimed.
   */
  // function() external payable {
  //   eosio_assert(!claimed);
  // }

  /**
   * @dev Create and deploy the target class (extension of Target contract), and sets the
   * msg.sender as a researcher
   * @return A target contract
   */
  Target createTarget() 
  // public returns(Target)
   {
    Target target = Target(deployContract());
    researchers[target] = msg.sender;
    emit TargetCreated(target);
    return target;
  }

  /**
   * @dev Transfers the class funds to the researcher that proved the class is broken.
   * @param _target contract
   */
  void claim(Target _target)  {
    account_name researcher = researchers[_target];
    eosio_assert(researcher != account_name(0));
    // Check Target class invariants
    eosio_assert(!_target.checkInvariant());
    asyncTransfer(researcher, account_name(this).balance);
    claimed = true;
  }

  /**
   * @dev Internal function to deploy the target contract.
   * @return A target class account_name
   */
  account_name deployContract();
  // internal returns(account_name);

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
   public::
  bool checkInvariant();
  // public returns(bool);
}
