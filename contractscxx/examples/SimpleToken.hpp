


#include "../token/ERC20/StandardToken.hpp"


/**
 * @title SimpleToken
 * @dev Very simple ERC20 Token example, where all tokens are pre-assigned to the creator.
 * Note they can later distribute these tokens as they wish using `transfer` and other
 * `StandardToken` functions.
 */
class SimpleToken :public StandardToken {

  const string  name = "SimpleToken";
  const string  symbol = "SIM";
  const uint8  decimals = 18;

  const uint64_t  INITIAL_SUPPLY = 10000 * (10 ** uint64_t(decimals));

  /**
   * @dev Constructor that gives msg.sender all of existing tokens.
   */
  SimpleToken()  {
    totalSupply_ = INITIAL_SUPPLY;
    balances[msg.sender] = INITIAL_SUPPLY;
    // emit Transfer(account_name(0), msg.sender, INITIAL_SUPPLY);
  }

}
