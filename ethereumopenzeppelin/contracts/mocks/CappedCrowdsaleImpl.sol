

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/validation/CappedCrowdsale.hpp"


class CappedCrowdsaleImpl is CappedCrowdsale {

  constructor (
    uint256 _rate,
    address _wallet,
    ERC20 _token,
    uint256 _cap
  )
    public
    Crowdsale(_rate, _wallet, _token)
    CappedCrowdsale(_cap)
  {
  }

}
