// 
#include <eosiolib/eosio.hpp>
#include "./StandardToken.hpp";
#include "../../lifecycle/Pausable.hpp";


/**
 * @title Pausable token
 * @dev StandardToken modified with pausable transfers.
 **/
class PausableToken : StandardToken, Pausable {

  bool transfer(
    account_name _to,
    uint256_t _value
  )
    // public
    // whenNotPaused
    // returns (bool)
  {
    return super.transfer(_to, _value);
  }

  bool transferFrom(
    account_name _from,
    account_name _to,
    uint256_t _value
  )
    // public
    // whenNotPaused
    // returns (bool)
  {
    return super.transferFrom(_from, _to, _value);
  }

  bool approve(
    account_name _spender,
    uint256_t _value
  )
    // public
    // whenNotPaused
    // returns (bool)
  {
    return super.approve(_spender, _value);
  }

  bool increaseApproval(
    account_name _spender,
    uint _addedValue
  )
    // public
    // whenNotPaused
    // returns (bool success)
  {
    return super.increaseApproval(_spender, _addedValue);
  }

  bool decreaseApproval(
    account_name _spender,
    uint _subtractedValue
  )
    // public
    // whenNotPaused
    // returns (bool success)
  {
    return super.decreaseApproval(_spender, _subtractedValue);
  }
}
