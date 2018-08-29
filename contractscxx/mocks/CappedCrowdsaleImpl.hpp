

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/CappedCrowdsale.hpp"


class CappedCrowdsaleImpl :public CappedCrowdsale {

  CappedCrowdsaleImpl (
    uint64_t _rate,
    account_name _wallet,
    ERC20 _token,
    uint64_t _cap
  ):Crowdsale(_rate, _wallet, _token),
    CappedCrowdsale(_cap)
  {
  }

}
