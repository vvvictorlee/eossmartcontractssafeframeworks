// 
#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include "./BasicToken.hpp"
#include "./ERC20.hpp"


/**
 * @title Standard ERC20 token
 *
 * @dev Implementation of the basic standard token.
 * https://github.com/ethereum/EIPs/issues/20
 * Based on code by FirstBlood: https://github.com/Firstbloodio/token/blob/master/smart_contract/FirstBloodToken.hpp
 */
class StandardToken : ERC20, BasicToken {

public:
  // mapping (account_name => mapping (account_name => uint256_t)) internal allowed;

  struct allowed_ {
            asset    balance;

            uint64_t primary_key()const { return balance.symbol.name(); }
         };

        

         typedef eosio::multi_index<N(allowed), allowed_> allowed;
  /**
   * @dev Transfer tokens from one account_name to another
   * @param _from account_name The account_name which you want to send tokens from
   * @param _to account_name The account_name which you want to transfer to
   * @param _value uint256_t the amount of tokens to be transferred
   */
  bool transferFrom(
    account_name _from,
    account_name _to,
    uint256_t _value
  )
  {
    eosio_assert(_value <= balances[_from]);
    eosio_assert(_value <= allowed[_from][msg.sender]);
    eosio_assert(_to != account_name(0));

    balances[_from] = balances[_from].sub(_value);
    balances[_to] = balances[_to].add(_value);
    allowed[_from][msg.sender] = allowed[_from][msg.sender].sub(_value);
    // emit Transfer(_from, _to, _value);
    return true;
  }

  /**
   * @dev Approve the passed account_name to spend the specified amount of tokens on behalf of msg.sender.
   * Beware that changing an allowance with this method brings the risk that someone may use both the old
   * and the new allowance by unfortunate transaction ordering. One possible solution to mitigate this
   * race condition is to first reduce the spender's allowance to 0 and set the desired value afterwards:
   * https://github.com/ethereum/EIPs/issues/20#issuecomment-263524729
   * @param _spender The account_name which will spend the funds.
   * @param _value The amount of tokens to be spent.
   */
  bool approve(account_name _spender, uint256_t _value) {
    allowed[msg.sender][_spender] = _value;
    // emit Approval(msg.sender, _spender, _value);
    return true;
  }

  /**
   * @dev Function to check the amount of tokens that an owner allowed to a spender.
   * @param _owner account_name The account_name which owns the funds.
   * @param _spender account_name The account_name which will spend the funds.
   * @return A uint256_t specifying the amount of tokens still available for the spender.
   */
  uint256_t allowance(
    account_name _owner,
    account_name _spender
   )
    // public
    // view
    // returns (uint256_t)
  {
    return allowed[_owner][_spender];
  }

  /**
   * @dev Increase the amount of tokens that an owner allowed to a spender.
   * approve should be called when allowed[_spender] == 0. To increment
   * allowed value is better to use this function to avoid 2 calls (and wait until
   * the first transaction is mined)
   * From MonolithDAO Token.hpp
   * @param _spender The account_name which will spend the funds.
   * @param _addedValue The amount of tokens to increase the allowance by.
   */
  bool increaseApproval(
    account_name _spender,
    uint256_t _addedValue
  )
  {
    allowed[msg.sender][_spender] = (
      allowed[msg.sender][_spender].add(_addedValue));
    // emit Approval(msg.sender, _spender, allowed[msg.sender][_spender]);
    return true;
  }

  /**
   * @dev Decrease the amount of tokens that an owner allowed to a spender.
   * approve should be called when allowed[_spender] == 0. To decrement
   * allowed value is better to use this function to avoid 2 calls (and wait until
   * the first transaction is mined)
   * From MonolithDAO Token.hpp
   * @param _spender The account_name which will spend the funds.
   * @param _subtractedValue The amount of tokens to decrease the allowance by.
   */
  bool decreaseApproval(
    account_name _spender,
    uint256_t _subtractedValue
  )
  {
    uint256_t oldValue = allowed[msg.sender][_spender];
    if (_subtractedValue >= oldValue) {
      allowed[msg.sender][_spender] = 0;
    } else {
      allowed[msg.sender][_spender] = oldValue.sub(_subtractedValue);
    }
    // emit Approval(msg.sender, _spender, allowed[msg.sender][_spender]);
    return true;
  }

}
