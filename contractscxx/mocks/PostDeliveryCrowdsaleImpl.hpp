

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/distribution/PostDeliveryCrowdsale.hpp"


class PostDeliveryCrowdsaleImpl :public PostDeliveryCrowdsale {

  PostDeliveryCrowdsaleImpl (
    uint256_t _openingTime,
    uint256_t _closingTime,
    uint256_t _rate,
    account_name _wallet,
    ERC20 _token
  ):TimedCrowdsale(_openingTime, _closingTime),
    Crowdsale(_rate, _wallet, _token)
  {
  }

}
