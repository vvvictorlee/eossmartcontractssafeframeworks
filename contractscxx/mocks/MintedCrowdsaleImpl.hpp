

#include "../token/ERC20/MintableToken.hpp"
#include "../crowdsale/emission/MintedCrowdsale.hpp"


class MintedCrowdsaleImpl :public MintedCrowdsale {

  MintedCrowdsaleImpl (
    uint256_t _rate,
    account_name _wallet,
    MintableToken _token
  ): Crowdsale(_rate, _wallet, _token)
  {
  }

}
