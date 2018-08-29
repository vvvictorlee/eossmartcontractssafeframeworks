

#include "../token/ERC20/MintableToken.hpp"
#include "../crowdsale/distribution/FinalizableCrowdsale.hpp"


class FinalizableCrowdsaleImpl :public FinalizableCrowdsale {

  FinalizableCrowdsaleImpl (
    uint64_t _openingTime,
    uint64_t _closingTime,
    uint64_t _rate,
    account_name _wallet,
    MintableToken _token
  ):Crowdsale(_rate, _wallet, _token),
    TimedCrowdsale(_openingTime, _closingTime)
  {
  }

}
