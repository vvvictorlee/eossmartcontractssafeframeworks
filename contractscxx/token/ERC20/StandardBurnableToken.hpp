#include <eosiolib/eosio.hpp>

#include "./BurnableToken.hpp"
#include "./StandardToken.hpp"


/**
 * @title Standard Burnable Token
 * @dev Adds burnFrom method to ERC20 implementations
 */
class StandardBurnableToken : BurnableToken, StandardToken {

  /**
   * @dev Burns a specific amount of tokens from the target account_name and decrements allowance
   * @param _from account_name The account_name which you want to send tokens from
   * @param _value uint256_t The amount of token to be burned
   */
  void burnFrom(account_name _from, uint256_t _value) 
  // public 
  {
    eosio_assert(_value <= allowed[_from][msg.sender]);
    // Should https://github.com/OpenZeppelin/zeppelin-solidity/issues/707 be accepted,
    // this function needs to emit an event with the updated approval.
    allowed[_from][msg.sender] = allowed[_from][msg.sender].sub(_value);
    _burn(_from, _value);
  }
}
