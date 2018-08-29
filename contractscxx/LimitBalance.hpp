// 


/**
 * @title LimitBalance
 * @dev Simple class to limit the balance of child contract.
 * Note this doesn't prevent other contracts to send funds by using selfdestruct(account_name);
 * See: https://github.com/ConsenSys/smart-contract-best-practices#remember-that-ether-can-be-forcibly-sent-to-an-account
 */
class LimitBalance {


  uint64_t  limit;
public:
  /**
   * @dev Constructor that sets the passed value as a limit.
   * @param _limit uint64_t to represent the limit.
   */
  LimitBalance(uint64_t _limit)  {
    limit = _limit;
  }

  /**
   * @dev Checks if limit was reached. Case true, it throws.
   */
  // modifier limitedPayable() {
  //   eosio_assert(account_name(this).balance <= limit);
  //   _;

  // }

}
