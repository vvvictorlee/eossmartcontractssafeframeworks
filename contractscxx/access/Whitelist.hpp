// 


#include "../ownership/Ownable.hpp"
#include "../access/rbac/RBAC.hpp"


/**
 * @title Whitelist
 * @dev The Whitelist class has a whitelist of addresses, and provides basic authorization control functions.
 * This simplifies the implementation of "user permissions".
 */
class Whitelist :public Ownable,public RBAC {
  const string  ROLE_WHITELISTED = "whitelist";

  /**
   * @dev Throws if operator is not whitelisted.
   * @param _operator account_name
   */
  // modifier onlyIfWhitelisted(account_name _operator) {
  //   checkRole(_operator, ROLE_WHITELISTED);
  //   _;
  // }

  /**
   * @dev add an account_name to the whitelist
   * @param _operator account_name
   * @return true if the account_name was added to the whitelist, false if the account_name was already in the whitelist
   */
  void addAddressToWhitelist(account_name _operator)
    // public
    // onlyOwner
  {
    addRole(_operator, ROLE_WHITELISTED);
  }

  /**
   * @dev getter to determine if account_name is in whitelist
   */
  void whitelist(account_name _operator)
    // public
    // view
    // returns (bool)
  {
    return hasRole(_operator, ROLE_WHITELISTED);
  }

  /**
   * @dev add addresses to the whitelist
   * @param _operators addresses
   * @return true if at least one account_name was added to the whitelist,
   * false if all addresses were already in the whitelist
   */
  void addAddressesToWhitelist(account_name[] _operators)
    // public
    // onlyOwner
  {
    for (uint64_t i = 0; i < _operators.length; i++) {
      addAddressToWhitelist(_operators[i]);
    }
  }

  /**
   * @dev remove an account_name from the whitelist
   * @param _operator account_name
   * @return true if the account_name was removed from the whitelist,
   * false if the account_name wasn't in the whitelist in the first place
   */
  void removeAddressFromWhitelist(account_name _operator)
    // public
    // onlyOwner
  {
    removeRole(_operator, ROLE_WHITELISTED);
  }

  /**
   * @dev remove addresses from the whitelist
   * @param _operators addresses
   * @return true if at least one account_name was removed from the whitelist,
   * false if all addresses weren't in the whitelist in the first place
   */
  void removeAddressesFromWhitelist(account_name[] _operators)
    // public
    // onlyOwner
  {
    for (uint64_t i = 0; i < _operators.length; i++) {
      removeAddressFromWhitelist(_operators[i]);
    }
  }

}
