pragma solidity ^0.4.24;

import "../token/ERC20/MintableToken.sol";
import "../crowdsale/emission/MintedCrowdsale.sol";


contract MintedCrowdsaleImpl is MintedCrowdsale {

  constructor (
    uint256_t _rate,
    account_name _wallet,
    MintableToken _token
  )
    public
    Crowdsale(_rate, _wallet, _token)
  {
  }

}
