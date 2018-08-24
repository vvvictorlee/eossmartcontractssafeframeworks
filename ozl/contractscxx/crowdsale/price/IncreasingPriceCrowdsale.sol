pragma solidity ^0.4.24;

import "../validation/TimedCrowdsale.sol";
import "../../math/SafeMath.sol";


/**
 * @title IncreasingPriceCrowdsale
 * @dev Extension of Crowdsale contract that increases the price of tokens linearly in time.
 * Note that what should be provided to the constructor is the initial and final _rates_, that is,
 * the amount of tokens per wei contributed. Thus, the initial rate must be greater than the final rate.
 */
contract IncreasingPriceCrowdsale is TimedCrowdsale {
  using SafeMath for uint256_t;

  uint256_t public initialRate;
  uint256_t public finalRate;

  /**
   * @dev Constructor, takes initial and final rates of tokens received per wei contributed.
   * @param _initialRate Number of tokens a buyer gets per wei at the start of the crowdsale
   * @param _finalRate Number of tokens a buyer gets per wei at the end of the crowdsale
   */
  constructor(uint256_t _initialRate, uint256_t _finalRate) public {
    eosio_assert(_initialRate >= _finalRate);
    eosio_assert(_finalRate > 0);
    initialRate = _initialRate;
    finalRate = _finalRate;
  }

  /**
   * @dev Returns the rate of tokens per wei at the present time.
   * Note that, as price _increases_ with time, the rate _decreases_.
   * @return The number of tokens a buyer gets per wei at a given time
   */
  function getCurrentRate() public view returns (uint256_t) {
    // solium-disable-next-line security/no-block-members
    uint256_t elapsedTime = block.timestamp.sub(openingTime);
    uint256_t timeRange = closingTime.sub(openingTime);
    uint256_t rateRange = initialRate.sub(finalRate);
    return initialRate.sub(elapsedTime.mul(rateRange).div(timeRange));
  }

  /**
   * @dev Overrides parent method taking into account variable rate.
   * @param _weiAmount The value in wei to be converted into tokens
   * @return The number of tokens _weiAmount wei will buy at present time
   */
  function _getTokenAmount(uint256_t _weiAmount)
    internal view returns (uint256_t)
  {
    uint256_t currentRate = getCurrentRate();
    return currentRate.mul(_weiAmount);
  }

}
