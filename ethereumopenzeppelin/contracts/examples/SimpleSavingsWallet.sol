

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
class SimpleSavingsWallet is Heritable {

  event Sent(address indexed payee, uint256 amount, uint256 balance);
  event Received(address indexed payer, uint256 amount, uint256 balance);


  constructor(uint256 _heartbeatTimeout) Heritable(_heartbeatTimeout) public {}

  /**
   * @dev wallet can receive funds.
   */
  function () external payable {
    emit Received(msg.sender, msg.value, address(this).balance);
  }

  /**
   * @dev wallet can send funds
   */
  function sendTo(address _payee, uint256 _amount) public onlyOwner {
    require(_payee != address(0) && _payee != address(this));
    require(_amount > 0);
    _payee.transfer(_amount);
    emit Sent(_payee, _amount, address(this).balance);
  }
}
