pragma solidity ^0.4.24;

import "../token/ERC20/MintableToken.sol";
import "../crowdsale/distribution/FinalizableCrowdsale.sol";


contract FinalizableCrowdsaleImpl is FinalizableCrowdsale {

  constructor (
    uint256_t _openingTime,
    uint256_t _closingTime,
    uint256_t _rate,
    account_name _wallet,
    MintableToken _token
  )
    public
    Crowdsale(_rate, _wallet, _token)
    TimedCrowdsale(_openingTime, _closingTime)
  {
  }

}
