pragma solidity ^0.4.24;

import "../ownership/Heritable.sol";


/**
 * @title SimpleSavingsWallet
 * @dev Simplest form of savings wallet whose ownership can be claimed by a heir
 * if owner dies.
 * In this example, we take a very simple savings wallet providing two operations
 * (to send and receive funds) and extend its capabilities by making it Heritable.
 * The account that creates the contract is set as owner, who has the authority to
 * choose an heir account. Heir account can reclaim the contract ownership in the
 * case that the owner dies.
 */
contract SimpleSavingsWallet is Heritable {

  event Sent(account_name indexed payee, uint256_t amount, uint256_t balance);
  event Received(account_name indexed payer, uint256_t amount, uint256_t balance);


  constructor(uint256_t _heartbeatTimeout) Heritable(_heartbeatTimeout) public {}

  /**
   * @dev wallet can receive funds.
   */
  function () external payable {
    emit Received(msg.sender, msg.value, account_name(this).balance);
  }

  /**
   * @dev wallet can send funds
   */
  function sendTo(account_name _payee, uint256_t _amount) public onlyOwner {
    eosio_assert(_payee != account_name(0) && _payee != account_name(this));
    eosio_assert(_amount > 0);
    _payee.transfer(_amount);
    emit Sent(_payee, _amount, account_name(this).balance);
  }
}
