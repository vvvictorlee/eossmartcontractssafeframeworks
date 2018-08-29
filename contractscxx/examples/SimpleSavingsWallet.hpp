

#include "../ownership/Heritable.hpp"


/**
 * @title SimpleSavingsWallet
 * @dev Simplest form of savings wallet whose ownership can be claimed by a heir
 * if owner dies.
 * In this example, we take a very simple savings wallet providing two operations
 * (to send and receive funds) and extend its capabilities by making it Heritable.
 * The account that creates the class is set as owner, who has the authority to
 * choose an heir account. Heir account can reclaim the class ownership in the
 * case that the owner dies.
 */
class SimpleSavingsWallet :public Heritable {

  // event Sent(account_name indexed payee, uint64_t amount, uint64_t balance);
  // event Received(account_name indexed payer, uint64_t amount, uint64_t balance);


  SimpleSavingsWallet(uint64_t _heartbeatTimeout):Heritable(_heartbeatTimeout)  {}

  /**
   * @dev wallet can receive funds.
   */
  // function () external payable {
  //   emit Received(msg.sender, msg.value, account_name(this).balance);
  // }

  /**
   * @dev wallet can send funds
   */
  void sendTo(account_name _payee, uint64_t _amount)
  //  public onlyOwner
   {
    eosio_assert(_payee != account_name(0) && _payee != account_name(this),"");
    eosio_assert(_amount > 0,"");
    _payee.transfer(_amount);
    // emit Sent(_payee, _amount, account_name(this).balance);
  }
}
