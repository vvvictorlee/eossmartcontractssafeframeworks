

#include "../token/ERC721/ERC721Token.hpp"


/**
 * @title ERC721TokenMock
 * This mock just provides a public mint and burn functions for testing purposes,
 * and a public setter for metadata URI
 */
class ERC721TokenMock :public ERC721Token {
  public:
  ERC721TokenMock(string name, string symbol) :    ERC721Token(name, symbol)
  { }

  void mint(account_name _to, uint256_t _tokenId)  {
    super._mint(_to, _tokenId);
  }

  void burn(uint256_t _tokenId)  {
    super._burn(ownerOf(_tokenId), _tokenId);
  }

  void setTokenURI(uint256_t _tokenId, string _uri)  {
    super._setTokenURI(_tokenId, _uri);
  }
  
  void _removeTokenFrom(account_name _from, uint256_t _tokenId)  {
    super.removeTokenFrom(_from, _tokenId);
  }
}
