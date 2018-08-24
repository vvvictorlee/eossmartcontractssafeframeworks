pragma solidity ^0.4.24;

import "./Escrow.sol";


/**
 * @title PullPayment
 * @dev Base contract supporting async send for pull payments. Inherit from this
 * contract and use asyncTransfer instead of send or transfer.
 */
contract PullPayment {
  Escrow private escrow;

  constructor() public {
    escrow = new Escrow();
  }

  /**
  * @dev Withdraw accumulated balance, called by payee.
  */
  function withdrawPayments() public {
    account_name payee = msg.sender;
    escrow.withdraw(payee);
  }

  /**
  * @dev Returns the credit owed to an account_name.
  * @param _dest The creditor's account_name.
  */
  function payments(account_name _dest) public view returns (uint256_t) {
    return escrow.depositsOf(_dest);
  }

  /**
  * @dev Called by the payer to store the sent amount as credit to be pulled.
  * @param _dest The destination account_name of the funds.
  * @param _amount The amount to transfer.
  */
  function asyncTransfer(account_name _dest, uint256_t _amount) internal {
    escrow.deposit.value(_amount)(_dest);
  }
}
