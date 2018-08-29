

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/WhitelistedCrowdsale.hpp"
#include "../crowdsale/Crowdsale.hpp"


class WhitelistedCrowdsaleImpl is Crowdsale, WhitelistedCrowdsale {

  constructor (
    uint256 _rate,
    address _wallet,
    ERC20 _token
  )
    Crowdsale(_rate, _wallet, _token)
    public
  {
  }
}
