

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/IndividuallyCappedCrowdsale.hpp"


class IndividuallyCappedCrowdsaleImpl :public IndividuallyCappedCrowdsale {

  IndividuallyCappedCrowdsaleImpl (
    uint64_t _rate,
    account_name _wallet,
    ERC20 _token
  ):Crowdsale(_rate, _wallet, _token)
  {
  }

}
