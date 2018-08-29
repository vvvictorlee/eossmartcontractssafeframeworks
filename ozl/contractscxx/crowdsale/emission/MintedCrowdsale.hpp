// 

#include "../Crowdsale.hpp";
#include "../../token/ERC20/MintableToken.hpp";


/**
 * @title MintedCrowdsale
 * @dev Extension of Crowdsale class whose tokens are minted in each purchase.
 * Token ownership should be transferred to MintedCrowdsale for minting.
 */
class MintedCrowdsale : public Crowdsale {

  /**
   * @dev Overrides delivery by minting tokens upon purchase.
   * @param _beneficiary Token purchaser
   * @param _tokenAmount Number of tokens to be minted
   */
  void _deliverTokens(
    account_name _beneficiary,
    uint256_t _tokenAmount
  )
    // internal
  {
    // Potentially dangerous assumption about the type of the token.
    eosio_assert(MintableToken(account_name(token)).mint(_beneficiary, _tokenAmount));
  }
}
