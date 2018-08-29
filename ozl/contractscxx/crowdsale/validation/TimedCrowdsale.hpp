// 

#include "../../math/SafeMath.hpp";
#include "../Crowdsale.hpp";


/**
 * @title TimedCrowdsale
 * @dev Crowdsale accepting contributions only within a time frame.
 */
class TimedCrowdsale : public Crowdsale {
  // using SafeMath for uint64_t;
public:
  uint64_t  openingTime;
  uint64_t  closingTime;

  // /**
  //  * @dev Reverts if not in crowdsale time range.
  //  */
  // modifier onlyWhileOpen {
  //   // solium-disable-next-line security/no-block-members
  //   eosio_assert(block.timestamp >= openingTime && block.timestamp <= closingTime);
  //   _;
  // }

  /**
   * @dev Constructor, takes crowdsale opening and closing times.
   * @param _openingTime Crowdsale opening time
   * @param _closingTime Crowdsale closing time
   */
  TimedCrowdsale(uint64_t _openingTime, uint64_t _closingTime)  {
    // solium-disable-next-line security/no-block-members
    eosio_assert(_openingTime >= block.timestamp);
    eosio_assert(_closingTime >= _openingTime);

    openingTime = _openingTime;
    closingTime = _closingTime;
  }

  /**
   * @dev Checks whether the period in which the crowdsale is open has already elapsed.
   * @return Whether crowdsale period has elapsed
   */
  void hasClosed()
  //  public view returns (bool) 
  {
    // solium-disable-next-line security/no-block-members
    return block.timestamp > closingTime;
  }

  /**
   * @dev Extend parent behavior requiring to be within contributing period
   * @param _beneficiary Token purchaser
   * @param _weiAmount Amount of wei contributed
   */
  void _preValidatePurchase(
    account_name _beneficiary,
    uint64_t _weiAmount
  )
    // internal
    // onlyWhileOpen
  {
    super._preValidatePurchase(_beneficiary, _weiAmount);
  }

}
