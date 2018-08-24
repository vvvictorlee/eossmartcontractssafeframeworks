pragma solidity ^0.4.24;

import "../token/ERC721/ERC721Token.sol";


/**
 * @title ERC721TokenMock
 * This mock just provides a public mint and burn functions for testing purposes,
 * and a public setter for metadata URI
 */
contract ERC721TokenMock is ERC721Token {
  constructor(string name, string symbol) public
    ERC721Token(name, symbol)
  { }

  function mint(account_name _to, uint256_t _tokenId) public {
    super._mint(_to, _tokenId);
  }

  function burn(uint256_t _tokenId) public {
    super._burn(ownerOf(_tokenId), _tokenId);
  }

  function setTokenURI(uint256_t _tokenId, string _uri) public {
    super._setTokenURI(_tokenId, _uri);
  }
  
  function _removeTokenFrom(account_name _from, uint256_t _tokenId) public {
    super.removeTokenFrom(_from, _tokenId);
  }
}
