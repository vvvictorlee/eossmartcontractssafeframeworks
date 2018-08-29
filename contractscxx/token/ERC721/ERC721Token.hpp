#include <eosiolib/eosio.hpp>

#include "./ERC721.hpp";
#include "./ERC721BasicToken.hpp";
#include "../../introspection/SupportsInterfaceWithLookup.hpp";


/**
 * @title Full ERC721 Token
 * This implementation includes all the required and some optional functionality of the ERC721 standard
 * Moreover, it includes approve all functionality using operator terminology
 * @dev see https://github.com/ethereum/EIPs/blob/master/EIPS/eip-721.md
 */
class ERC721Token : SupportsInterfaceWithLookup, ERC721BasicToken, ERC721 {

  // Token name
  string  name_;

  // Token symbol
  string  symbol_;

  // // Mapping from owner to list of owned token IDs
  // mapping(account_name => uint256_t[]) internal ownedTokens;

  // // Mapping from token ID to index of the owner tokens list
  // mapping(uint256_t => uint256_t) internal ownedTokensIndex;

  // // Array with all token ids, used for enumeration
  // uint256_t[]  allTokens;

  // // Mapping from token id to position in the allTokens array
  // mapping(uint256_t => uint256_t) internal allTokensIndex;

  // // Optional mapping for token URIs
  // mapping(uint256_t => string) internal tokenURIs;

 struct ownedTokensx
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(ownedTokens), ownedTokensx> ownedTokens;


   struct ownedTokensIndex
  {
    uint64_t name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(ownedTokensIndex), ownedTokensIndexx> ownedTokensIndex;


  struct allTokensIndexx
  {
    uint64_t name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(allTokensIndex), allTokensIndex> allTokensIndex;

  struct tokenURIsx
  {
    uint64_t name;
    std::string balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(tokenURIs), tokenURIsx> tokenURIs;




  /**
   * @dev Constructor function
   */
  ERC721Token(string _name, string _symbol)  {
    name_ = _name;
    symbol_ = _symbol;

    // register the supported interfaces to conform to ERC721 via ERC165
    _registerInterface(InterfaceId_ERC721Enumerable);
    _registerInterface(InterfaceId_ERC721Metadata);
  }

  /**
   * @dev Gets the token name
   * @return string representing the token name
   */
  string name() 
  // external view returns (string) 
  {
    return name_;
  }

  /**
   * @dev Gets the token symbol
   * @return string representing the token symbol
   */
  string symbol() 
  // external view returns (string) 
  {
    return symbol_;
  }

  /**
   * @dev Returns an URI for a given token ID
   * Throws if the token ID does not exist. May return an empty string.
   * @param _tokenId uint256_t ID of the token to query
   */
  string tokenURI(uint256_t _tokenId) 
  // public view returns (string) 
  {
    eosio_assert(exists(_tokenId));
    return tokenURIs[_tokenId];
  }

  /**
   * @dev Gets the token ID at a given index of the tokens list of the requested owner
   * @param _owner account_name owning the tokens list to be accessed
   * @param _index uint256_t representing the index to be accessed of the requested tokens list
   * @return uint256_t token ID at the given index of the tokens list owned by the requested account_name
   */
  uint256_t tokenOfOwnerByIndex(
    account_name _owner,
    uint256_t _index
  )
    // public
    // view
    // returns (uint256_t)
  {
    eosio_assert(_index < balanceOf(_owner));
    return ownedTokens[_owner][_index];
  }

  /**
   * @dev Gets the total amount of tokens stored by the class
   * @return uint256_t representing the total amount of tokens
   */
  uint256_t totalSupply() 
  // public view returns (uint256_t) 
  {
    return allTokens.length;
  }

  /**
   * @dev Gets the token ID at a given index of all the tokens in this class
   * Reverts if the index is greater or equal to the total number of tokens
   * @param _index uint256_t representing the index to be accessed of the tokens list
   * @return uint256_t token ID at the given index of the tokens list
   */
  uint256_t tokenByIndex(uint256_t _index)
  //  public view returns (uint256_t) 
   {
    eosio_assert(_index < totalSupply());
    return allTokens[_index];
  }

  /**
   * @dev Internal function to set the token URI for a given token
   * Reverts if the token ID does not exist
   * @param _tokenId uint256_t ID of the token to set its URI
   * @param _uri string URI to assign
   */
  void _setTokenURI(uint256_t _tokenId, string _uri)  {
    eosio_assert(exists(_tokenId));
    tokenURIs[_tokenId] = _uri;
  }

  /**
   * @dev Internal function to add a token ID to the list of a given account_name
   * @param _to account_name representing the new owner of the given token ID
   * @param _tokenId uint256_t ID of the token to be added to the tokens list of the given account_name
   */
  void addTokenTo(account_name _to, uint256_t _tokenId)  {
    super.addTokenTo(_to, _tokenId);
    uint256_t length = ownedTokens[_to].length;
    ownedTokens[_to].push(_tokenId);
    ownedTokensIndex[_tokenId] = length;
  }

  /**
   * @dev Internal function to remove a token ID from the list of a given account_name
   * @param _from account_name representing the previous owner of the given token ID
   * @param _tokenId uint256_t ID of the token to be removed from the tokens list of the given account_name
   */
  void removeTokenFrom(account_name _from, uint256_t _tokenId)  {
    super.removeTokenFrom(_from, _tokenId);

    // To prevent a gap in the array, we store the last token in the index of the token to delete, and
    // then delete the last slot.
    uint256_t tokenIndex = ownedTokensIndex[_tokenId];
    uint256_t lastTokenIndex = ownedTokens[_from].length.sub(1);
    uint256_t lastToken = ownedTokens[_from][lastTokenIndex];

    ownedTokens[_from][tokenIndex] = lastToken;
    // This also deletes the contents at the last position of the array
    ownedTokens[_from].length--;

    // Note that this will handle single-element arrays. In that case, both tokenIndex and lastTokenIndex are going to
    // be zero. Then we can make sure that we will remove _tokenId from the ownedTokens list since we are first swapping
    // the lastToken to the first position, and then dropping the element placed in the last position of the list

    ownedTokensIndex[_tokenId] = 0;
    ownedTokensIndex[lastToken] = tokenIndex;
  }

  /**
   * @dev Internal function to mint a new token
   * Reverts if the given token ID already exists
   * @param _to account_name the beneficiary that will own the minted token
   * @param _tokenId uint256_t ID of the token to be minted by the msg.sender
   */
  void _mint(account_name _to, uint256_t _tokenId)  {
    super._mint(_to, _tokenId);

    allTokensIndex[_tokenId] = allTokens.length;
    allTokens.push(_tokenId);
  }

  /**
   * @dev Internal function to burn a specific token
   * Reverts if the token does not exist
   * @param _owner owner of the token to burn
   * @param _tokenId uint256_t ID of the token being burned by the msg.sender
   */
  void _burn(account_name _owner, uint256_t _tokenId)  {
    super._burn(_owner, _tokenId);

    // Clear metadata (if any)
    if (bytes(tokenURIs[_tokenId]).length != 0) {
      delete tokenURIs[_tokenId];
    }

    // Reorg all tokens array
    uint256_t tokenIndex = allTokensIndex[_tokenId];
    uint256_t lastTokenIndex = allTokens.length.sub(1);
    uint256_t lastToken = allTokens[lastTokenIndex];

    allTokens[tokenIndex] = lastToken;
    allTokens[lastTokenIndex] = 0;

    allTokens.length--;
    allTokensIndex[_tokenId] = 0;
    allTokensIndex[lastToken] = tokenIndex;
  }

}
