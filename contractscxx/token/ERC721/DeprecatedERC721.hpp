#include <eosiolib/eosio.hpp>

#include "./ERC721.hpp"


/**
 * @title ERC-721 methods shipped in OpenZeppelin v1.7.0, removed in the latest version of the standard
 * @dev Only use this interface for compatibility with previously deployed contracts
 * Use ERC721 for interacting with new contracts which are standard-compliant
 */
class DeprecatedERC721 : ERC721 {
  void takeOwnership(uint256_t _tokenId) ;
  void transfer(account_name _to, uint256_t _tokenId);
  uint256_t[] tokensOf(account_name _owner) ;
  //public view returns ();
}
