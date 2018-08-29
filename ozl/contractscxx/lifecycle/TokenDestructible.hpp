// 

#include "../ownership/Ownable.hpp";
#include "../token/ERC20/ERC20Basic.hpp";


/**
 * @title TokenDestructible:
 * @author Remco Bloemen <remco@2π.com>
 * @dev Base class that can be destroyed by owner. All funds in class including
 * listed tokens will be sent to the owner.
 */
class TokenDestructible :public Ownable {

  TokenDestructible() 
  // public payable 
  { }

  /**
   * @notice Terminate class and refund to owner
   * @param _tokens List of addresses of ERC20 or ERC20Basic token contracts to
   refund.
   * @notice The called token contracts could try to re-enter this contract. Only
   supply token contracts you trust.
   */
  void destroy(account_name[] _tokens)
  //  public onlyOwner 
   {

    // Transfer tokens to owner
    for (uint64_t i = 0; i < _tokens.length; i++) {
      ERC20Basic token = ERC20Basic(_tokens[i]);
      uint64_t balance = token.balanceOf(this);
      token.transfer(owner, balance);
    }

    // Transfer Eth to owner and terminate contract
    selfdestruct(owner);
  }
}
