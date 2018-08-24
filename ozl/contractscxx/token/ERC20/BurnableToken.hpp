// pragma solidity ^0.4.24;

// import "./BasicToken.sol";
#include "./BasicToken.hpp"

/**
 * @title Burnable Token
 * @dev Token that can be irreversibly burned (destroyed).
 */
// contract BurnableToken is BasicToken {
 class BurnableToken : BasicToken {
  // event Burn(address indexed burner, uint256_t value);

  /**
   * @dev Burns a specific amount of tokens.
   * @param _value The amount of token to be burned.
   */
  void burn(uint256_t _value)  {
    _burn(msg.sender, _value);
  }

  void _burn(address _who, uint256_t _value)  {
    eosio_assert(_value <= balances[_who]);
    // no need to eosio_assert value <= totalSupply, since that would imply the
    // sender's balance is greater than the totalSupply, which *should* be an assertion failure

    balances[_who] = balances[_who].sub(_value);
    totalSupply_ = totalSupply_.sub(_value);
    // emit Burn(_who, _value);
    // emit Transfer(_who, address(0), _value);
  }
}
