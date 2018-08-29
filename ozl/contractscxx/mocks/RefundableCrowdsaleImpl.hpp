

#include "../token/ERC20/MintableToken.hpp"
#include "../crowdsale/distribution/RefundableCrowdsale.hpp"


class RefundableCrowdsaleImpl :public RefundableCrowdsale {

  RefundableCrowdsaleImpl (
    uint256_t _openingTime,
    uint256_t _closingTime,
    uint256_t _rate,
    account_name _wallet,
    MintableToken _token,
    uint256_t _goal
  ):Crowdsale(_rate, _wallet, _token),
    TimedCrowdsale(_openingTime, _closingTime),
    RefundableCrowdsale(_goal)
  {
  }

}
