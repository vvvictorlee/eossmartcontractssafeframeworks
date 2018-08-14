// pragma solidity ^0.4.24;
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>

#include "./ERC20Basic.hpp";
#include "../../math/SafeMath.hpp";

/**
 * @title Basic token
 * @dev Basic version of StandardToken, with no allowances.
 */
class BasicToken : ERC20Basic
{
  // using SafeMath for uint32_t;
  struct balance
  {
    asset balance;

    uint64_t primary_key() const { return balance.symbol.name(); }
  };

  typedef eosio::multi_index<N(balances), balance> balances;

  // mapping(account_name => uint32_t) internal balances;

  uint32_t totalSupply_;

  /**
  * @dev Total number of tokens in existence
  */
  uint32_t totalSupply()
  {
    return totalSupply_;
  }

  /**
  * @dev Transfer token for a specified account_name
  * @param _to The account_name to transfer to.
  * @param _value The amount to be transferred.
  */
  void transfer(account_name _to, uint32_t _value)
  {
    eosio_assert(_value <= balances[msg.sender], "");
    eosio_assert(_to != account_name(0));

    balances[msg.sender] = balances[msg.sender].sub(_value);
    balances[_to] = balances[_to].add(_value);
    // emit Transfer(msg.sender, _to, _value);

    // return true;
  }

  /**
  * @dev Gets the balance of the specified account_name.
  * @param _owner The account_name to query the the balance of.
  * @return An uint32_t representing the amount owned by the passed account_name.
  */
  uint32_t balanceOf(account_name _owner)
  {
        accounts accountstable( _self, _owner );
      const auto& ac = accountstable.get( sym );
      return ac.balance;
    return balances[_owner];
  }
}
