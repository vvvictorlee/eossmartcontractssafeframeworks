

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/TimedCrowdsale.hpp"


class TimedCrowdsaleImpl is TimedCrowdsale {

  constructor (
    uint256 _openingTime,
    uint256 _closingTime,
    uint256 _rate,
    address _wallet,
    ERC20 _token
  )
    public
    Crowdsale(_rate, _wallet, _token)
    TimedCrowdsale(_openingTime, _closingTime)
  {
  }

}
