// 

#include "../Crowdsale.hpp";
#include "../../token/ERC20/ERC20.hpp";
#include "../../token/ERC20/ERC20Basic.hpp";
#include "../../token/ERC20/SafeERC20.hpp";
#include "../../math/SafeMath.hpp";


/**
 * @title AllowanceCrowdsale
 * @dev Extension of Crowdsale where tokens are held by a wallet, which approves an allowance to the crowdsale.
 */
class AllowanceCrowdsale : public Crowdsale {
  using SafeMath for uint64_t;
  using SafeERC20 for ERC20;

  account_name  tokenWallet;

  /**
   * @dev Constructor, takes token wallet account_name.
   * @param _tokenWallet Address holding the tokens, which has approved allowance to the crowdsale
   */
  AllowanceCrowdsale(account_name _tokenWallet) public {
    eosio_assert(_tokenWallet != account_name(0));
    tokenWallet = _tokenWallet;
  }

  /**
   * @dev Checks the amount of tokens left in the allowance.
   * @return Amount of tokens left in the allowance
   */
  uint64_t remainingTokens() 
  // public view returns (uint64_t) 
  {
    return token.allowance(tokenWallet, this);
  }

  /**
   * @dev Overrides parent behavior by transferring tokens from wallet.
   * @param _beneficiary Token purchaser
   * @param _tokenAmount Amount of tokens purchased
   */
  void _deliverTokens(
    account_name _beneficiary,
    uint64_t _tokenAmount
  )
    // internal
  {
    token.safeTransferFrom(tokenWallet, _beneficiary, _tokenAmount);
  }
}
