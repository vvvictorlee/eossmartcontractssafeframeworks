

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/WhitelistedCrowdsale.hpp"
#include "../crowdsale/Crowdsale.hpp"


class WhitelistedCrowdsaleImpl :public Crowdsale, WhitelistedCrowdsale {

  WhitelistedCrowdsaleImpl (
    uint256_t _rate,
    account_name _wallet,
    ERC20 _token
  ):Crowdsale(_rate, _wallet, _token)
  {
  }
}
