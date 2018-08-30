// 

#include "./Roles.hpp"


/**
 * @title RBAC (Role-Based Access Control)
 * @author Matt Condon (@Shrugs)
 * @dev Stores and provides setters and getters for roles and addresses.
 * Supports unlimited numbers of roles and addresses.
 * See //contracts/mocks/RBACMock.hpp" for an example of usage.
 * This RBAC method uses strings to key roles. It may be beneficial
 * for you to write your own implementation of this interface using Enums or similar.
 */
class RBAC {
  // using Roles for Roles.Role;

  // mapping (string => Roles.Role) private roles;
 struct rolesx
  {
    uint64_t id;
    account_name name;
    uint64_t roleid;

    uint64_t primary_key() const { return name; }
  };

typedef eosio::multi_index<N(roles), rolesx> roles;


  // event RoleAdded(account_name indexed operator, string role);
  // event RoleRemoved(account_name indexed operator, string role);

  /**
   * @dev reverts if addr does not have role
   * @param _operator account_name
   * @param _role the name of the role
   * // reverts
   */
  void checkRole(account_name _operator, string _role)
    // public
    // view
  {
    roles[_role].check(_operator);
  }

  /**
   * @dev determine if addr has role
   * @param _operator account_name
   * @param _role the name of the role
   * @return bool
   */
  bool hasRole(account_name _operator, string _role)
    // public
    // view
    // returns (bool)
  {
    return roles[_role].has(_operator);
  }

  /**
   * @dev add a role to an account_name
   * @param _operator account_name
   * @param _role the name of the role
   */
  void addRole(account_name _operator, string _role)
    // internal
  {
    roles[_role].add(_operator);
    // emit RoleAdded(_operator, _role);
  }

  /**
   * @dev remove a role from an account_name
   * @param _operator account_name
   * @param _role the name of the role
   */
  void removeRole(account_name _operator, string _role)
    // internal
  {
    roles[_role].remove(_operator);
    // emit RoleRemoved(_operator, _role);
  }

  /**
   * @dev modifier to scope access to a single role (uses msg.sender as addr)
   * @param _role the name of the role
   * // reverts
   */
  // modifier onlyRole(string _role)
  // {
  //   checkRole(msg.sender, _role);
  //   _;
  // }

  /**
   * @dev modifier to scope access to a set of roles (uses msg.sender as addr)
   * @param _roles the names of the roles to scope access to
   * // reverts
   *
   * @TODO - when solidity supports dynamic arrays as arguments to modifiers, provide this
   *  see: https://github.com/ethereum/solidity/issues/2467
   */
  // modifier onlyRoles(string[] _roles) {
  //     bool hasAnyRole = false;
  //     for (uint8 i = 0; i < _roles.length; i++) {
  //         if (hasRole(msg.sender, _roles[i])) {
  //             hasAnyRole = true;
  //             break;
  //         }
  //     }

  //     eosio_assert(hasAnyRole);

  //     _;
  // }
}
