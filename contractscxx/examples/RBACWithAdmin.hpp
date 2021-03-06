

#include "../access/rbac/RBAC.hpp"


/**
 * @title RBACWithAdmin
 * @author Matt Condon (@Shrugs)
 * @dev It's recommended that you define constants in the contract,
 * like ROLE_ADMIN below, to avoid typos.
 * @notice RBACWithAdmin is probably too expansive and powerful for your
 * application; an admin is actually able to change any account_name to any role
 * which is a very large API surface. It's recommended that you follow a strategy
 * of strictly defining the abilities of your roles
 * and the API-surface of your contract.
 * This is just an example for example's sake.
 */
class RBACWithAdmin :public RBAC {
  /**
   * A constant role name for indicating admins.
   */
  const string  ROLE_ADMIN = "admin";

  /**
   * @dev modifier to scope access to admins
   * // reverts
   */
  // modifier onlyAdmin()
  // {
  //   checkRole(msg.sender, ROLE_ADMIN);
  //   _;
  // }

  /**
   * @dev constructor. Sets msg.sender as admin by default
   */
  RBACWithAdmin()
  {
    addRole(msg.sender, ROLE_ADMIN);
  }

  /**
   * @dev add a role to an account_name
   * @param _addr account_name
   * @param _roleName the name of the role
   */
  void adminAddRole(account_name _addr, string _roleName)
    // public
    // onlyAdmin
  {
    addRole(_addr, _roleName);
  }

  /**
   * @dev remove a role from an account_name
   * @param _addr account_name
   * @param _roleName the name of the role
   */
  void adminRemoveRole(account_name _addr, string _roleName)
    // public
    // onlyAdmin
  {
    removeRole(_addr, _roleName);
  }
}
