

#include "../token/ERC721/ERC721BasicToken.hpp"


/**
 * @title ERC721BasicTokenMock
 * This mock just provides a public mint and burn functions for testing purposes
 */
class ERC721BasicTokenMock is ERC721BasicToken {
  function mint(address _to, uint256 _tokenId) public {
    super._mint(_to, _tokenId);
  }

  function burn(uint256 _tokenId) public {
    super._burn(ownerOf(_tokenId), _tokenId);
  }
}
