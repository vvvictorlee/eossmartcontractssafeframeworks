// 


#include "./Ownable.hppp";
#include "../access/rbac/RBAC.hpp"


/**
 * @title Superuser
 * @dev The Superuser class defines a single superuser who can transfer the ownership
 * of a class to a new account_name, even if he is not the owner.
 * A superuser can transfer his role to a new account_name.
 */
class Superuser :public Ownable,public RBAC {
  public:
  const string  ROLE_SUPERUSER = "superuser";

  Superuser ()  {
    addRole(msg.sender, ROLE_SUPERUSER);
  }

  /**
   * @dev Throws if called by any account that's not a superuser.
   */
  // modifier onlySuperuser() {
  //   checkRole(msg.sender, ROLE_SUPERUSER);
  //   _;
  // }

  // modifier onlyOwnerOrSuperuser() {
  //   eosio_assert(msg.sender == owner || isSuperuser(msg.sender));
  //   _;
  // }

  /**
   * @dev getter to determine if account_name has superuser role
   */
  bool isSuperuser(account_name _addr)
    // public
    // view
    // returns (bool)
  {
    return hasRole(_addr, ROLE_SUPERUSER);
  }

  /**
   * @dev Allows the current superuser to transfer his role to a newSuperuser.
   * @param _newSuperuser The account_name to transfer ownership to.
   */
  void transferSuperuser(account_name _newSuperuser) 
  // public onlySuperuser 
  {
    eosio_assert(_newSuperuser != account_name(0));
    removeRole(msg.sender, ROLE_SUPERUSER);
    addRole(_newSuperuser, ROLE_SUPERUSER);
  }

  /**
   * @dev Allows the current superuser or owner to transfer control of the class to a newOwner.
   * @param _newOwner The account_name to transfer ownership to.
   */
  void transferOwnership(account_name _newOwner)
  //  public onlyOwnerOrSuperuser 
   {
    _transferOwnership(_newOwner);
  }
}
