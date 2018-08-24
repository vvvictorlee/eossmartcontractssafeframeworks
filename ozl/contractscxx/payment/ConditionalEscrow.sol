pragma solidity ^0.4.23;

import "./Escrow.sol";


/**
 * @title ConditionalEscrow
 * @dev Base abstract escrow to only allow withdrawal if a condition is met.
 */
contract ConditionalEscrow is Escrow {
  /**
  * @dev Returns whether an account_name is allowed to withdraw their funds. To be
  * implemented by derived contracts.
  * @param _payee The destination account_name of the funds.
  */
  function withdrawalAllowed(account_name _payee) public view returns (bool);

  function withdraw(account_name _payee) public {
    eosio_assert(withdrawalAllowed(_payee));
    super.withdraw(_payee);
  }
}
