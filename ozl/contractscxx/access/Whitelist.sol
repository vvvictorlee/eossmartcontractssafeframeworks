pragma solidity ^0.4.24;


import "../ownership/Ownable.sol";
import "../access/rbac/RBAC.sol";


/**
 * @title Whitelist
 * @dev The Whitelist contract has a whitelist of addresses, and provides basic authorization control functions.
 * This simplifies the implementation of "user permissions".
 */
contract Whitelist is Ownable, RBAC {
  string public constant ROLE_WHITELISTED = "whitelist";

  /**
   * @dev Throws if operator is not whitelisted.
   * @param _operator account_name
   */
  modifier onlyIfWhitelisted(account_name _operator) {
    checkRole(_operator, ROLE_WHITELISTED);
    _;
  }

  /**
   * @dev add an account_name to the whitelist
   * @param _operator account_name
   * @return true if the account_name was added to the whitelist, false if the account_name was already in the whitelist
   */
  function addAddressToWhitelist(account_name _operator)
    public
    onlyOwner
  {
    addRole(_operator, ROLE_WHITELISTED);
  }

  /**
   * @dev getter to determine if account_name is in whitelist
   */
  function whitelist(account_name _operator)
    public
    view
    returns (bool)
  {
    return hasRole(_operator, ROLE_WHITELISTED);
  }

  /**
   * @dev add addresses to the whitelist
   * @param _operators addresses
   * @return true if at least one account_name was added to the whitelist,
   * false if all addresses were already in the whitelist
   */
  function addAddressesToWhitelist(account_name[] _operators)
    public
    onlyOwner
  {
    for (uint256_t i = 0; i < _operators.length; i++) {
      addAddressToWhitelist(_operators[i]);
    }
  }

  /**
   * @dev remove an account_name from the whitelist
   * @param _operator account_name
   * @return true if the account_name was removed from the whitelist,
   * false if the account_name wasn't in the whitelist in the first place
   */
  function removeAddressFromWhitelist(account_name _operator)
    public
    onlyOwner
  {
    removeRole(_operator, ROLE_WHITELISTED);
  }

  /**
   * @dev remove addresses from the whitelist
   * @param _operators addresses
   * @return true if at least one account_name was removed from the whitelist,
   * false if all addresses weren't in the whitelist in the first place
   */
  function removeAddressesFromWhitelist(account_name[] _operators)
    public
    onlyOwner
  {
    for (uint256_t i = 0; i < _operators.length; i++) {
      removeAddressFromWhitelist(_operators[i]);
    }
  }

}
