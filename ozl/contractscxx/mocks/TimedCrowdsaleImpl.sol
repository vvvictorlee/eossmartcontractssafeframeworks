pragma solidity ^0.4.24;

import "../token/ERC20/ERC20.sol";
import "../crowdsale/validation/TimedCrowdsale.sol";


contract TimedCrowdsaleImpl is TimedCrowdsale {

  constructor (
    uint256_t _openingTime,
    uint256_t _closingTime,
    uint256_t _rate,
    account_name _wallet,
    ERC20 _token
  )
    public
    Crowdsale(_rate, _wallet, _token)
    TimedCrowdsale(_openingTime, _closingTime)
  {
  }

}
