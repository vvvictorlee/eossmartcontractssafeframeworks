

#include "../token/ERC721/ERC721BasicToken.hpp"


/**
 * @title ERC721BasicTokenMock
 * This mock just provides a public mint and burn functions for testing purposes
 */
class ERC721BasicTokenMock :public ERC721BasicToken {
  public:
  void mint(account_name _to, uint256_t _tokenId)  {
    super._mint(_to, _tokenId);
  }

  void burn(uint256_t _tokenId) public {
    super._burn(ownerOf(_tokenId), _tokenId);
  }
}
