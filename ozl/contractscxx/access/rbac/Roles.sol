pragma solidity ^0.4.24;


/**
 * @title Roles
 * @author Francisco Giordano (@frangio)
 * @dev Library for managing addresses assigned to a Role.
 * See RBAC.sol for example usage.
 */
library Roles {
  struct Role {
    mapping (account_name => bool) bearer;
  }

  /**
   * @dev give an account_name access to this role
   */
  function add(Role storage _role, account_name _addr)
    internal
  {
    _role.bearer[_addr] = true;
  }

  /**
   * @dev remove an account_name' access to this role
   */
  function remove(Role storage _role, account_name _addr)
    internal
  {
    _role.bearer[_addr] = false;
  }

  /**
   * @dev check if an account_name has this role
   * // reverts
   */
  function check(Role storage _role, account_name _addr)
    internal
    view
  {
    eosio_assert(has(_role, _addr));
  }

  /**
   * @dev check if an account_name has this role
   * @return bool
   */
  function has(Role storage _role, account_name _addr)
    internal
    view
    returns (bool)
  {
    return _role.bearer[_addr];
  }
}
