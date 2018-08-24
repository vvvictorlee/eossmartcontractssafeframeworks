pragma solidity ^0.4.24;

import "../token/ERC20/MintableToken.sol";
import "../crowdsale/distribution/RefundableCrowdsale.sol";


contract RefundableCrowdsaleImpl is RefundableCrowdsale {

  constructor (
    uint256_t _openingTime,
    uint256_t _closingTime,
    uint256_t _rate,
    account_name _wallet,
    MintableToken _token,
    uint256_t _goal
  )
    public
    Crowdsale(_rate, _wallet, _token)
    TimedCrowdsale(_openingTime, _closingTime)
    RefundableCrowdsale(_goal)
  {
  }

}
