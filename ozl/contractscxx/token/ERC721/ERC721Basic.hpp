#include <eosiolib/eosio.hpp>

#include "../../introspection/ERC165.hpp";


/**
 * @title ERC721 Non-Fungible Token Standard basic interface
 * @dev see https://github.com/ethereum/EIPs/blob/master/EIPS/eip-721.md
 */
class ERC721Basic : ERC165 {

  // bytes4 internal constant InterfaceId_ERC721 = 0x80ac58cd;
  const bytes4   InterfaceId_ERC721 = 0x80ac58cd;
  /*
   * 0x80ac58cd ===
   *   bytes4(keccak256('balanceOf(account_name)')) ^
   *   bytes4(keccak256('ownerOf(uint256_t)')) ^
   *   bytes4(keccak256('approve(account_name,uint256_t)')) ^
   *   bytes4(keccak256('getApproved(uint256_t)')) ^
   *   bytes4(keccak256('setApprovalForAll(account_name,bool)')) ^
   *   bytes4(keccak256('isApprovedForAll(account_name,account_name)')) ^
   *   bytes4(keccak256('transferFrom(account_name,account_name,uint256_t)')) ^
   *   bytes4(keccak256('safeTransferFrom(account_name,account_name,uint256_t)')) ^
   *   bytes4(keccak256('safeTransferFrom(account_name,account_name,uint256_t,bytes)'))
   */

  const bytes4 InterfaceId_ERC721Exists = 0x4f558e79;
  /*
   * 0x4f558e79 ===
   *   bytes4(keccak256('exists(uint256_t)'))
   */

  const bytes4  InterfaceId_ERC721Enumerable = 0x780e9d63;
  /**
   * 0x780e9d63 ===
   *   bytes4(keccak256('totalSupply()')) ^
   *   bytes4(keccak256('tokenOfOwnerByIndex(account_name,uint256_t)')) ^
   *   bytes4(keccak256('tokenByIndex(uint256_t)'))
   */

  const bytes4  InterfaceId_ERC721Metadata = 0x5b5e139f;
  /**
   * 0x5b5e139f ===
   *   bytes4(keccak256('name()')) ^
   *   bytes4(keccak256('symbol()')) ^
   *   bytes4(keccak256('tokenURI(uint256_t)'))
   */

  // event Transfer(
  //   account_name indexed _from,
  //   account_name indexed _to,
  //   uint256_t indexed _tokenId
  // );
  // event Approval(
  //   account_name indexed _owner,
  //   account_name indexed _approved,
  //   uint256_t indexed _tokenId
  // );
  // event ApprovalForAll(
  //   account_name indexed _owner,
  //   account_name indexed _operator,
  //   bool _approved
  // );

  uint256_t balanceOf(account_name _owner);// public view returns (uint256_t _balance);
  account_name ownerOf(uint256_t _tokenId);// public view returns (account_name _owner);
  bool exists(uint256_t _tokenId);// public view returns (bool _exists);

  void approve(account_name _to, uint256_t _tokenId) ;
  account_name getApproved(uint256_t _tokenId);
   // public view returns (account_name _operator);

  void setApprovalForAll(account_name _operator, bool _approved) ;
  bool isApprovedForAll(account_name _owner, account_name _operator);
   // public view returns (bool);

   void transferFrom(account_name _from, account_name _to, uint256_t _tokenId) ;
   void safeTransferFrom(account_name _from, account_name _to, uint256_t _tokenId)
    ;

  void safeTransferFrom(
    account_name _from,
    account_name _to,
    uint256_t _tokenId,
    bytes _data
  );
}
