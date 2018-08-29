#include <eosiolib/eosio.hpp>

#include "./ERC721Basic.hpp";


/**
 * @title ERC-721 Non-Fungible Token Standard, optional enumeration extension
 * @dev See https://github.com/ethereum/EIPs/blob/master/EIPS/eip-721.md
 */
class ERC721Enumerable : ERC721Basic {
  uint256_t totalSupply();// public view returns ();
  uint256_t tokenOfOwnerByIndex(
    account_name _owner,
    uint256_t _index
  );
    // public
    // view
    // returns (uint256_t _tokenId);

  uint256_t tokenByIndex(uint256_t _index);
  // public view returns (uint256_t);
}


/**
 * @title ERC-721 Non-Fungible Token Standard, optional metadata extension
 * @dev See https://github.com/ethereum/EIPs/blob/master/EIPS/eip-721.md
 */
class ERC721Metadata : ERC721Basic {
  string name();// external view returns (string _name);
  string symbol();// external view returns (string _symbol);
  string tokenURI(uint256_t _tokenId);// public view returns (string);
}


/**
 * @title ERC-721 Non-Fungible Token Standard, full implementation interface
 * @dev See https://github.com/ethereum/EIPs/blob/master/EIPS/eip-721.md
 */
class ERC721 : ERC721Basic, ERC721Enumerable, ERC721Metadata {
}
