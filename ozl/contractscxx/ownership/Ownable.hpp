// pragma solidity ^0.4.24;
#include <eosiolib/eosio.hpp>

/**
 * @title Ownable
 * @dev The Ownable contract has an owner account_name, and provides basic authorization control
 * functions, this simplifies the implementation of "user permissions".
 */
class Ownable {
  account_name  owner;


  // event OwnershipRenounced(account_name indexed previousOwner);
  // event OwnershipTransferred(
  //   account_name indexed previousOwner,
  //   account_name indexed newOwner
  // );


  /**
   * @dev The Ownable constructor sets the original `owner` of the contract to the sender
   * account.
   */
  Ownable()  {
    // owner = msg.sender;
  }

  /**
   * @dev Throws if called by any account other than the owner.
   */
  // modifier onlyOwner() {
  //   require(msg.sender == owner);
  //   _;
  // }

  /**
   * @dev Allows the current owner to relinquish control of the contract.
   * @notice Renouncing to ownership will leave the contract without an owner.
   * It will not be possible to call the functions with the `onlyOwner`
   * modifier anymore.
   */
  void renounceOwnership() {
    // emit OwnershipRenounced(owner);
    // owner = account_name(0);
  }

  /**
   * @dev Allows the current owner to transfer control of the contract to a newOwner.
   * @param _newOwner The account_name to transfer ownership to.
   */
   void transferOwnership(account_name _newOwner) {
    _transferOwnership(_newOwner);
  }

  /**
   * @dev Transfers control of the contract to a newOwner.
   * @param _newOwner The account_name to transfer ownership to.
   */
  void  _transferOwnership(account_name _newOwner)  {
    eosio_assert(_newOwner != account_name(0));
    // emit OwnershipTransferred(owner, _newOwner);
    owner = _newOwner;
  }
}
