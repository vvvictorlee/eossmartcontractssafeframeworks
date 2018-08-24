// pragma solidity ^0.4.24;
#include <eosiolib/eosio.hpp>
#include "./MintableToken.hpp";
#include "../../access/rbac/RBAC.hpp";


/**
 * @title RBACMintableToken
 * @author Vittorio Minacori (@vittominacori)
 * @dev Mintable Token, with RBAC minter permissions
 */
class RBACMintableToken : MintableToken, RBAC {
  /**
   * A constant role name for indicating minters.
   */
  const string   ROLE_MINTER = "minter";

  /**
   * @dev override the Mintable token modifier to add role based logic
   */
  // modifier hasMintPermission() {
  //   checkRole(msg.sender, ROLE_MINTER);
  //   _;
  // }

  /**
   * @dev add a minter role to an account_name
   * @param _minter account_name
   */
  voids addMinter(account_name _minter) 
  // public onlyOwner 
  {
    addRole(_minter, ROLE_MINTER);
  }

  /**
   * @dev remove a minter role from an account_name
   * @param _minter account_name
   */
  void removeMinter(account_name _minter) 
  // public onlyOwner 
  {
    removeRole(_minter, ROLE_MINTER);
  }
}
