// 


/**
 * @title Roles
 * @author Francisco Giordano (@frangio)
 * @dev Library for managing addresses assigned to a Role.
 * See RBAC.hpp" for example usage.
 */
class Roles {
  struct Role {
    // mapping (account_name => bool) bearer;
    
  }
 struct Rolex
  {
    account_name name;
    uint64_t roleid;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(Role), Rolex> Role;
  /**
   * @dev give an account_name access to this role
   */
  void add(Role storage _role, account_name _addr)
    // internal
  {
    _role.bearer[_addr] = true;
  }

  /**
   * @dev remove an account_name' access to this role
   */
  void remove(Role storage _role, account_name _addr)
    // internal
  {
    _role.bearer[_addr] = false;
  }

  /**
   * @dev check if an account_name has this role
   * // reverts
   */
  void check(Role storage _role, account_name _addr)
    // internal
    // view
  {
    eosio_assert(has(_role, _addr));
  }

  /**
   * @dev check if an account_name has this role
   * @return bool
   */
  bool has(Role storage _role, account_name _addr)
    // internal
    // view
    // returns (bool)
  {
    return _role.bearer[_addr];
  }
}
