

#include "../token/ERC20/MintableToken.hpp"
#include "../crowdsale/emission/MintedCrowdsale.hpp"


class MintedCrowdsaleImpl is MintedCrowdsale {

  constructor (
    uint256 _rate,
    address _wallet,
    MintableToken _token
  )
    public
    Crowdsale(_rate, _wallet, _token)
  {
  }

}
