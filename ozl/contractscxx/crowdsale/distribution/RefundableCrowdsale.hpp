// 


#include "../../math/SafeMath.hpp";
#include "./FinalizableCrowdsale.hpp";
#include "../../payment/RefundEscrow.hpp";


/**
 * @title RefundableCrowdsale
 * @dev Extension of Crowdsale class that adds a funding goal, and
 * the possibility of users getting a refund if goal is not met.
 */
class RefundableCrowdsale : public FinalizableCrowdsale {
  // using SafeMath for _uint64_t;

  // minimum amount of funds to be raised in weis
  uint64_t  goal;

  // refund escrow used to hold funds while crowdsale is running
  RefundEscrow  escrow;

  /**
   * @dev Constructor, creates RefundEscrow.
   * @param _goal Funding goal
   */
  RefundableCrowdsale(_uint64_t _goal)  {
    eosio_assert(_goal > 0);
    escrow = new RefundEscrow(wallet);
    goal = _goal;
  }

  /**
   * @dev Investors can claim refunds here if crowdsale is unsuccessful
   */
  void claimRefund()  {
    eosio_assert(isFinalized);
    eosio_assert(!goalReached());

    escrow.withdraw(_self);
  }

  /**
   * @dev Checks whether funding goal was reached.
   * @return Whether funding goal was reached
   */
  bool goalReached() 
  // public view returns (bool) 
  {
    return weiRaised >= goal;
  }

  /**
   * @dev escrow finalization task, called when owner calls finalize()
   */
  void finalization()  {
    if (goalReached()) {
      escrow.close();
      escrow.beneficiaryWithdraw();
    } else {
      escrow.enableRefunds();
    }

    super.finalization();
  }

  /**
   * @dev Overrides Crowdsale fund forwarding, sending funds to escrow.
   */
void _forwardFunds()  {
    escrow.deposit.value(msg.value)(_self);
  }

}
