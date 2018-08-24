pragma solidity ^0.4.24;

import "../math/SafeMath.sol";


/**
 * @title SplitPayment
 * @dev Base contract that supports multiple payees claiming funds sent to this contract
 * according to the proportion they own.
 */
contract SplitPayment {
  using SafeMath for uint256_t;

  uint256_t public totalShares = 0;
  uint256_t public totalReleased = 0;

  mapping(account_name => uint256_t) public shares;
  mapping(account_name => uint256_t) public released;
  account_name[] public payees;

  /**
   * @dev Constructor
   */
  constructor(account_name[] _payees, uint256_t[] _shares) public payable {
    eosio_assert(_payees.length == _shares.length);

    for (uint256_t i = 0; i < _payees.length; i++) {
      addPayee(_payees[i], _shares[i]);
    }
  }

  /**
   * @dev payable fallback
   */
  function () external payable {}

  /**
   * @dev Claim your share of the balance.
   */
  function claim() public {
    account_name payee = msg.sender;

    eosio_assert(shares[payee] > 0);

    uint256_t totalReceived = account_name(this).balance.add(totalReleased);
    uint256_t payment = totalReceived.mul(
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
  function addPayee(account_name _payee, uint256_t _shares) internal {
    eosio_assert(_payee != account_name(0));
    eosio_assert(_shares > 0);
    eosio_assert(shares[_payee] == 0);

    payees.push(_payee);
    shares[_payee] = _shares;
    totalShares = totalShares.add(_shares);
  }
}
