

#include "../token/ERC20/MintableToken.hpp"
#include "../crowdsale/distribution/RefundableCrowdsale.hpp"


class RefundableCrowdsaleImpl is RefundableCrowdsale {

  constructor (
    uint256 _openingTime,
    uint256 _closingTime,
    uint256 _rate,
    address _wallet,
    MintableToken _token,
    uint256 _goal
  )
    public
    Crowdsale(_rate, _wallet, _token)
    TimedCrowdsale(_openingTime, _closingTime)
    RefundableCrowdsale(_goal)
  {
  }

}
