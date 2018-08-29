

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/distribution/PostDeliveryCrowdsale.hpp"


class PostDeliveryCrowdsaleImpl is PostDeliveryCrowdsale {

  constructor (
    uint256 _openingTime,
    uint256 _closingTime,
    uint256 _rate,
    address _wallet,
    ERC20 _token
  )
    public
    TimedCrowdsale(_openingTime, _closingTime)
    Crowdsale(_rate, _wallet, _token)
  {
  }

}
