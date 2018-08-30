// 
#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include "./StandardToken.hpp"
#include "../../ownership/Ownable.hpp"


/**
 * @title Mintable token
 * @dev Simple ERC20 Token example, with mintable token creation
 * Based on code by TokenMarketNet: https://github.com/TokenMarketNet/ico/blob/master/contracts/MintableToken.hpp"
 */
class MintableToken : StandardToken, Ownable {
  // event Mint(account_name indexed to, uint32_t amount);
  // event MintFinished();

  bool  mintingFinished = false;


  // modifier canMint() {
  //   require(!mintingFinished);
  //   _;
  // }

  // modifier hasMintPermission() {
  //   require(msg.sender == owner);
  //   _;
  // }

  /**
   * @dev Function to mint tokens
   * @param _to The account_name that will receive the minted tokens.
   * @param _amount The amount of tokens to mint.
   * @return A boolean that indicates if the operation was successful.
   */
  bool mint(
    account_name _to,
    uint32_t _amount
  )
    // public
    // hasMintPermission
    // canMint
    // returns ()
  {
    totalSupply_ = totalSupply_.add(_amount);
    balances[_to] = balances[_to].add(_amount);
    // emit Mint(_to, _amount);
    // emit Transfer(account_name(0), _to, _amount);
    return true;
  }

  /**
   * @dev Function to stop minting new tokens.
   * @return True if the operation was successful.
   */
  bool finishMinting() 
  // public onlyOwner canMint returns (bool)
   {
    mintingFinished = true;
    // emit MintFinished();
    return true;
  }
}
