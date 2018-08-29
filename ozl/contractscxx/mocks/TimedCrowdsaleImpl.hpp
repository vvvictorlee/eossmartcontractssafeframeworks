

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/TimedCrowdsale.hpp"


class TimedCrowdsaleImpl :public TimedCrowdsale {

  constructor (
    uint256_t _openingTime,
    uint256_t _closingTime,
    uint256_t _rate,
    account_name _wallet,
    ERC20 _token
  ): Crowdsale(_rate, _wallet, _token),
    TimedCrowdsale(_openingTime, _closingTime)
  {
  }

}
