

#include "../crowdsale/price/IncreasingPriceCrowdsale.hpp"
#include "../math/SafeMath.hpp"


class IncreasingPriceCrowdsaleImpl :public IncreasingPriceCrowdsale {

  IncreasingPriceCrowdsaleImpl (
    uint64_t _openingTime,
    uint64_t _closingTime,
    account_name _wallet,
    ERC20 _token,
    uint64_t _initialRate,
    uint64_t _finalRate
  ):
    Crowdsale(_initialRate, _wallet, _token),
    TimedCrowdsale(_openingTime, _closingTime),
    IncreasingPriceCrowdsale(_initialRate, _finalRate)
  {
  }

}
