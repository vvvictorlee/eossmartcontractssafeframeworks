// pragma solidity ^0.4.23;

#include "../math/SafeMath.hpp";
#include "../ownership/Ownable.hpp";


/**
 * @title Escrow
 * @dev Base escrow contract, holds funds destinated to a payee until they
 * withdraw them. The class that uses the escrow as its payment method
 * should be its owner, and provide public methods redirecting to the escrow's
 * deposit and withdraw.
 */
class Escrow :public Ownable {
  // using SafeMath for uint64_t;

  // event Deposited(account_name indexed payee, uint64_t weiAmount);
  // event Withdrawn(account_name indexed payee, uint64_t weiAmount);

  // mapping(account_name => uint64_t) private deposits;
 struct balance
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(balances), balance> balances;
  uint64_t depositsOf(account_name _payee) 
  // public view returns () 
  {
    return deposits[_payee];
  }

  /**
  * @dev Stores the sent amount as credit to be withdrawn.
  * @param _payee The destination account_name of the funds.
  */
  void deposit(account_name _payee)
  //  public onlyOwner payable 
   {
    uint64_t amount = msg.value;
    deposits[_payee] = deposits[_payee].add(amount);

    // emit Deposited(_payee, amount);
  }

  /**
  * @dev Withdraw accumulated balance for a payee.
  * @param _payee The account_name whose funds will be withdrawn and transferred to.
  */
  void withdraw(account_name _payee) 
  // public onlyOwner 
  {
    uint64_t payment = deposits[_payee];
    assert(account_name(this).balance >= payment);

    deposits[_payee] = 0;

    _payee.transfer(payment);

    // emit Withdrawn(_payee, payment);
  }
}
