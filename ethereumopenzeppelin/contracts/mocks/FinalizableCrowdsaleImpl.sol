

#include "../token/ERC20/MintableToken.hpp"
#include "../crowdsale/distribution/FinalizableCrowdsale.hpp"


class FinalizableCrowdsaleImpl is FinalizableCrowdsale {

  constructor (
    uint256 _openingTime,
    uint256 _closingTime,
    uint256 _rate,
    address _wallet,
    MintableToken _token
  )
    public
    Crowdsale(_rate, _wallet, _token)
    TimedCrowdsale(_openingTime, _closingTime)
  {
  }

}
