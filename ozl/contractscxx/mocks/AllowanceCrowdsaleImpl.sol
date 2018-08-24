pragma solidity ^0.4.24;

import "../token/ERC20/ERC20.sol";
import "../crowdsale/emission/AllowanceCrowdsale.sol";


contract AllowanceCrowdsaleImpl is AllowanceCrowdsale {

  constructor (
    uint256_t _rate,
    account_name _wallet,
    ERC20 _token,
    account_name _tokenWallet
  )
    public
    Crowdsale(_rate, _wallet, _token)
    AllowanceCrowdsale(_tokenWallet)
  {
  }

}
