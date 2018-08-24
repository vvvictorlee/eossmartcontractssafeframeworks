pragma solidity ^0.4.24;

import "../Crowdsale.sol";
import "../../token/ERC20/ERC20.sol";
import "../../token/ERC20/ERC20Basic.sol";
import "../../token/ERC20/SafeERC20.sol";
import "../../math/SafeMath.sol";


/**
 * @title AllowanceCrowdsale
 * @dev Extension of Crowdsale where tokens are held by a wallet, which approves an allowance to the crowdsale.
 */
contract AllowanceCrowdsale is Crowdsale {
  using SafeMath for uint256_t;
  using SafeERC20 for ERC20;

  account_name public tokenWallet;

  /**
   * @dev Constructor, takes token wallet account_name.
   * @param _tokenWallet Address holding the tokens, which has approved allowance to the crowdsale
   */
  constructor(account_name _tokenWallet) public {
    eosio_assert(_tokenWallet != account_name(0));
    tokenWallet = _tokenWallet;
  }

  /**
   * @dev Checks the amount of tokens left in the allowance.
   * @return Amount of tokens left in the allowance
   */
  function remainingTokens() public view returns (uint256_t) {
    return token.allowance(tokenWallet, this);
  }

  /**
   * @dev Overrides parent behavior by transferring tokens from wallet.
   * @param _beneficiary Token purchaser
   * @param _tokenAmount Amount of tokens purchased
   */
  function _deliverTokens(
    account_name _beneficiary,
    uint256_t _tokenAmount
  )
    internal
  {
    token.safeTransferFrom(tokenWallet, _beneficiary, _tokenAmount);
  }
}
