

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/IndividuallyCappedCrowdsale.hpp"


class IndividuallyCappedCrowdsaleImpl is IndividuallyCappedCrowdsale {

  constructor (
    uint256 _rate,
    address _wallet,
    ERC20 _token
  )
    public
    Crowdsale(_rate, _wallet, _token)
  {
  }

}
