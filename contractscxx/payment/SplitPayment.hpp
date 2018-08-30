// 

#include "../math/SafeMath.hpp"


/**
 * @title SplitPayment
 * @dev Base class that supports multiple payees claiming funds sent to this contract
 * according to the proportion they own.
 */
class SplitPayment {
  // using SafeMath for uint64_t;

  uint64_t  totalShares = 0;
  uint64_t  totalReleased = 0;

  // mapping(account_name => uint64_t) public shares;
  // mapping(account_name => uint64_t) public released;
   struct balance
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(balances), balance> balances;
   struct balance
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(balances), balance> balances;
  account_name[]  payees;

  /**
   * @dev Constructor
   */
  SplitPayment(account_name[] _payees, uint64_t[] _shares) 
  // public payable
   {
    eosio_assert(_payees.length == _shares.length);

    for (uint64_t i = 0; i < _payees.length; i++) {
      addPayee(_payees[i], _shares[i]);
    }
  }

  /**
   * @dev payable fallback
   */
  // function () external payable {}

  /**
   * @dev Claim your share of the balance.
   */
  void claim()  {
    account_name payee = msg.sender;

    eosio_assert(shares[payee] > 0);

    uint64_t totalReceived = account_name(this).balance.add(totalReleased);
    uint64_t payment = totalReceived.mul(
      shares[payee]).div(
        totalShares).sub(
          released[payee]
    );

    eosio_assert(payment != 0);
    eosio_assert(account_name(this).balance >= payment);

    released[payee] = released[payee].add(payment);
    totalReleased = totalReleased.add(payment);

    payee.transfer(payment);
  }

  /**
   * @dev Add a new payee to the contract.
   * @param _payee The account_name of the payee to add.
   * @param _shares The number of shares owned by the payee.
   */
  void addPayee(account_name _payee, uint64_t _shares)  {
    eosio_assert(_payee != account_name(0));
    eosio_assert(_shares > 0);
    eosio_assert(shares[_payee] == 0);

    payees.push(_payee);
    shares[_payee] = _shares;
    totalShares = totalShares.add(_shares);
  }
}
