// pragma solidity ^0.4.24;

#include "./MintableToken.hpp";


/**
 * @title Capped token
 * @dev Mintable token with a token cap.
 */
class CappedToken : MintableToken {

  uint256_t  cap;

  CappedToken(uint256_t _cap) public {
    require(_cap > 0);
    cap = _cap;
  }

  /**
   * @dev Function to mint tokens
   * @param _to The address that will receive the minted tokens.
   * @param _amount The amount of tokens to mint.
   * @return A boolean that indicates if the operation was successful.
   */
  function mint(
    address _to,
    uint256_t _amount
  )
    public
    returns (bool)
  {
    require(totalSupply_.add(_amount) <= cap);

    return super.mint(_to, _amount);
  }

}
