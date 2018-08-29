// 

#include "../validation/TimedCrowdsale.hpp";
#include "../../token/ERC20/ERC20.hpp";
#include "../../math/SafeMath.hpp";


/**
 * @title PostDeliveryCrowdsale
 * @dev Crowdsale that locks tokens from withdrawal until it ends.
 */
class PostDeliveryCrowdsale : TimedCrowdsale {
  // using SafeMath for uint256_t;

  // mapping(account_name => uint256_t) public balances;

  /**
   * @dev Withdraw tokens only after crowdsale ends.
   */
  void withdrawTokens()  {
    eosio_assert(hasClosed());
    uint256_t amount = balances[_self];
    eosio_assert(amount > 0);
    balances[_self] = 0;
    _deliverTokens(_self, amount);
  }

  /**
   * @dev Overrides parent by storing balances instead of issuing tokens right away.
   * @param _beneficiary Token purchaser
   * @param _tokenAmount Amount of tokens purchased
   */
  void _processPurchase(
    account_name _beneficiary,
    uint256_t _tokenAmount
  )
    // internal
  {
    balances[_beneficiary] = balances[_beneficiary].add(_tokenAmount);
  }

}
