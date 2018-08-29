

#include "../token/ERC20/ERC20.hpp"
#include "../crowdsale/emission/AllowanceCrowdsale.hpp"


class AllowanceCrowdsaleImpl is AllowanceCrowdsale {

  constructor (
    uint256 _rate,
    address _wallet,
    ERC20 _token,
    address _tokenWallet
  )
    public
    Crowdsale(_rate, _wallet, _token)
    AllowanceCrowdsale(_tokenWallet)
  {
  }

}
