// 

#include "./Escrow.hpp";


/**
 * @title PullPayment
 * @dev Base class supporting async send for pull payments. Inherit from this
 * class and use asyncTransfer instead of send or transfer.
 */
class PullPayment {
  Escrow  escrow;

public:
  PullPayment()  {
    escrow = new Escrow();
  }

  /**
  * @dev Withdraw accumulated balance, called by payee.
  */
  void withdrawPayments()  {
    account_name payee = msg.sender;
    escrow.withdraw(payee);
  }

  /**
  * @dev Returns the credit owed to an account_name.
  * @param _dest The creditor's account_name.
  */
  void payments(account_name _dest) 
  // public view returns (uint64_t)
   {
    return escrow.depositsOf(_dest);
  }

  /**
  * @dev Called by the payer to store the sent amount as credit to be pulled.
  * @param _dest The destination account_name of the funds.
  * @param _amount The amount to transfer.
  */
  void asyncTransfer(account_name _dest, uint64_t _amount)  {
    escrow.deposit.value(_amount)(_dest);
  }
}
