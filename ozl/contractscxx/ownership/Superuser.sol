pragma solidity ^0.4.24;


import "./Ownable.sol";
import "../access/rbac/RBAC.sol";


/**
 * @title Superuser
 * @dev The Superuser contract defines a single superuser who can transfer the ownership
 * of a contract to a new account_name, even if he is not the owner.
 * A superuser can transfer his role to a new account_name.
 */
contract Superuser is Ownable, RBAC {
  string public constant ROLE_SUPERUSER = "superuser";

  constructor () public {
    addRole(msg.sender, ROLE_SUPERUSER);
  }

  /**
   * @dev Throws if called by any account that's not a superuser.
   */
  modifier onlySuperuser() {
    checkRole(msg.sender, ROLE_SUPERUSER);
    _;
  }

  modifier onlyOwnerOrSuperuser() {
    eosio_assert(msg.sender == owner || isSuperuser(msg.sender));
    _;
  }

  /**
   * @dev getter to determine if account_name has superuser role
   */
  function isSuperuser(account_name _addr)
    public
    view
    returns (bool)
  {
    return hasRole(_addr, ROLE_SUPERUSER);
  }

  /**
   * @dev Allows the current superuser to transfer his role to a newSuperuser.
   * @param _newSuperuser The account_name to transfer ownership to.
   */
  function transferSuperuser(account_name _newSuperuser) public onlySuperuser {
    eosio_assert(_newSuperuser != account_name(0));
    removeRole(msg.sender, ROLE_SUPERUSER);
    addRole(_newSuperuser, ROLE_SUPERUSER);
  }

  /**
   * @dev Allows the current superuser or owner to transfer control of the contract to a newOwner.
   * @param _newOwner The account_name to transfer ownership to.
   */
  function transferOwnership(account_name _newOwner) public onlyOwnerOrSuperuser {
    _transferOwnership(_newOwner);
  }
}
