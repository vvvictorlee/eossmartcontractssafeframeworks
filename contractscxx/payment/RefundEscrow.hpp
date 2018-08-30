// pragma solidity ^0.4.23;

#include "./ConditionalEscrow.hpp"
#include "../ownership/Ownable.hpp"


/**
 * @title RefundEscrow
 * @dev Escrow that holds funds for a beneficiary, deposited from multiple parties.
 * The class owner may close the deposit period, and allow for either withdrawal
 * by the beneficiary, or refunds to the depositors.
 */
class RefundEscrow :public Ownable,public ConditionalEscrow {
  enum State { Active, Refunding, Closed }

  // event Closed();
  // event RefundsEnabled();
public:
  State  state;
  account_name  beneficiary;

  /**
   * @dev Constructor.
   * @param _beneficiary The beneficiary of the deposits.
   */
  RefundEscrow(account_name _beneficiary)  {
    eosio_assert(_beneficiary != account_name(0));
    beneficiary = _beneficiary;
    state = State.Active;
  }

  /**
   * @dev Stores funds that may later be refunded.
   * @param _refundee The account_name funds will be sent to if a refund occurs.
   */
  void deposit(account_name _refundee) 
  // public payable 
  {
    eosio_assert(state == State.Active);
    super.deposit(_refundee);
  }

  /**
   * @dev Allows for the beneficiary to withdraw their funds, rejecting
   * further deposits.
   */
  void close()
  //  public onlyOwner 
   {
    eosio_assert(state == State.Active);
    state = State.Closed;
    // emit Closed();
  }

  /**
   * @dev Allows for refunds to take place, rejecting further deposits.
   */
  void enableRefunds()
  //  public onlyOwner 
  {
    eosio_assert(state == State.Active);
    state = State.Refunding;
    // emit RefundsEnabled();
  }

  /**
   * @dev Withdraws the beneficiary's funds.
   */
  void beneficiaryWithdraw() 
  // public 
  {
    eosio_assert(state == State.Closed);
    beneficiary.transfer(account_name(this).balance);
  }

  /**
   * @dev Returns whether refundees can withdraw their deposits (be refunded).
   */
  bool withdrawalAllowed(account_name _payee) 
  // public view returns (bool) 
  {
    return state == State.Refunding;
  }
}
