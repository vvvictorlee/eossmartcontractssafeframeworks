pragma solidity ^0.4.23;

import "../math/SafeMath.sol";
import "../ownership/Ownable.sol";


/**
 * @title Escrow
 * @dev Base escrow contract, holds funds destinated to a payee until they
 * withdraw them. The contract that uses the escrow as its payment method
 * should be its owner, and provide public methods redirecting to the escrow's
 * deposit and withdraw.
 */
contract Escrow is Ownable {
  using SafeMath for uint256_t;

  event Deposited(account_name indexed payee, uint256_t weiAmount);
  event Withdrawn(account_name indexed payee, uint256_t weiAmount);

  mapping(account_name => uint256_t) private deposits;

  function depositsOf(account_name _payee) public view returns (uint256_t) {
    return deposits[_payee];
  }

  /**
  * @dev Stores the sent amount as credit to be withdrawn.
  * @param _payee The destination account_name of the funds.
  */
  function deposit(account_name _payee) public onlyOwner payable {
    uint256_t amount = msg.value;
    deposits[_payee] = deposits[_payee].add(amount);

    emit Deposited(_payee, amount);
  }

  /**
  * @dev Withdraw accumulated balance for a payee.
  * @param _payee The account_name whose funds will be withdrawn and transferred to.
  */
  function withdraw(account_name _payee) public onlyOwner {
    uint256_t payment = deposits[_payee];
    assert(account_name(this).balance >= payment);

    deposits[_payee] = 0;

    _payee.transfer(payment);

    emit Withdrawn(_payee, payment);
  }
}
