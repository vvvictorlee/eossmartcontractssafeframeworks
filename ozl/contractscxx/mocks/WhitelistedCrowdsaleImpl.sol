pragma solidity ^0.4.24;

import "../token/ERC20/ERC20.sol";
import "../crowdsale/validation/WhitelistedCrowdsale.sol";
import "../crowdsale/Crowdsale.sol";


contract WhitelistedCrowdsaleImpl is Crowdsale, WhitelistedCrowdsale {

  constructor (
    uint256_t _rate,
    account_name _wallet,
    ERC20 _token
  )
    Crowdsale(_rate, _wallet, _token)
    public
  {
  }
}
