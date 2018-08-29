// 

#include "../token/ERC20/ERC20.hpp";
#include "../crowdsale/emission/AllowanceCrowdsale.hpp";


class AllowanceCrowdsaleImpl :public AllowanceCrowdsale {

  AllowanceCrowdsaleImpl (
    uint64_t _rate,
    account_name _wallet,
    ERC20 _token,
    account_name _tokenWallet
  ):
    Crowdsale(_rate, _wallet, _token),
    AllowanceCrowdsale(_tokenWallet)
  {
  }

}
