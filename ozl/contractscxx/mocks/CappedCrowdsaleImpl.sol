pragma solidity ^0.4.24;

import "../token/ERC20/ERC20.sol";
import "../crowdsale/validation/CappedCrowdsale.sol";


contract CappedCrowdsaleImpl is CappedCrowdsale {

  constructor (
    uint256_t _rate,
    account_name _wallet,
    ERC20 _token,
    uint256_t _cap
  )
    public
    Crowdsale(_rate, _wallet, _token)
    CappedCrowdsale(_cap)
  {
  }

}
