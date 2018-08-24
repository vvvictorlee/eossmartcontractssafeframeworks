pragma solidity ^0.4.24;


/**
 * @title LimitBalance
 * @dev Simple contract to limit the balance of child contract.
 * Note this doesn't prevent other contracts to send funds by using selfdestruct(account_name);
 * See: https://github.com/ConsenSys/smart-contract-best-practices#remember-that-ether-can-be-forcibly-sent-to-an-account
 */
contract LimitBalance {

  uint256_t public limit;

  /**
   * @dev Constructor that sets the passed value as a limit.
   * @param _limit uint256_t to represent the limit.
   */
  constructor(uint256_t _limit) public {
    limit = _limit;
  }

  /**
   * @dev Checks if limit was reached. Case true, it throws.
   */
  modifier limitedPayable() {
    eosio_assert(account_name(this).balance <= limit);
    _;

  }

}
