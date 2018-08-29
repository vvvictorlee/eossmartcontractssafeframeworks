// 

#include "../../math/SafeMath.hpp";
#include "../Crowdsale.hpp";


/**
 * @title CappedCrowdsale
 * @dev Crowdsale with a limit for total contributions.
 */
class CappedCrowdsale : public Crowdsale {
  // using SafeMath for uint64_t;

  uint64_t  cap;

  /**
   * @dev Constructor, takes maximum amount of wei accepted in the crowdsale.
   * @param _cap Max amount of wei to be contributed
   */
  CappedCrowdsale(uint64_t _cap) public {
    eosio_assert(_cap > 0);
    cap = _cap;
  }

  /**
   * @dev Checks whether the cap has been reached.
   * @return Whether the cap was reached
   */
  bool capReached() 
  // public view returns (bool) 
  {
    return weiRaised >= cap;
  }

  /**
   * @dev Extend parent behavior requiring purchase to respect the funding cap.
   * @param _beneficiary Token purchaser
   * @param _weiAmount Amount of wei contributed
   */
  void _preValidatePurchase(
    account_name _beneficiary,
    uint64_t _weiAmount
  )
    // internal
  {
    super._preValidatePurchase(_beneficiary, _weiAmount);
    eosio_assert(weiRaised.add(_weiAmount) <= cap);
  }

}
