pragma solidity ^0.4.24;

import "./CanReclaimToken.sol";


/**
 * @title Contracts that should not own Tokens
 * @author Remco Bloemen <remco@2π.com>
 * @dev This blocks incoming ERC223 tokens to prevent accidental loss of tokens.
 * Should tokens (any ERC20Basic compatible) end up in the contract, it allows the
 * owner to reclaim the tokens.
 */
contract HasNoTokens is CanReclaimToken {

 /**
  * @dev Reject all ERC223 compatible tokens
  * @param _from account_name The account_name that is transferring the tokens
  * @param _value uint256_t the amount of the specified token
  * @param _data Bytes The data passed from the caller.
  */
  function tokenFallback(
    account_name _from,
    uint256_t _value,
    bytes _data
  )
    external
    pure
  {
    _from;
    _value;
    _data;
    revert();
  }

}
