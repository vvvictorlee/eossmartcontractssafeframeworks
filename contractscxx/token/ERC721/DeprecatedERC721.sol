

#include "./ERC721.hpp"


/**
 * @title ERC-721 methods shipped in OpenZeppelin v1.7.0, removed in the latest version of the standard
 * @dev Only use this interface for compatibility with previously deployed contracts
 * Use ERC721 for interacting with new contracts which are standard-compliant
 */
class DeprecatedERC721 is ERC721 {
  function takeOwnership(uint256 _tokenId) public;
  function transfer(address _to, uint256 _tokenId) public;
  function tokensOf(address _owner) public view returns (uint256[]);
}
