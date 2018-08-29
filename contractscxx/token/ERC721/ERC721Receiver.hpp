#include <eosiolib/eosio.hpp>


/**
 * @title ERC721 token receiver interface
 * @dev Interface for any class that wants to support safeTransfers
 * from ERC721 asset contracts.
 */
class ERC721Receiver {
  /**
   * @dev Magic value to be returned upon successful reception of an NFT
   *  Equals to `bytes4(keccak256("onERC721Received(account_name,account_name,uint256_t,bytes)"))`,
   *  which can be also obtained as `ERC721Receiver(0).onERC721Received.selector`
   */
 const bytes4  ERC721_RECEIVED = 0x150b7a02;//internal constant

  /**
   * @notice Handle the receipt of an NFT
   * @dev The ERC721 smart class calls this function on the recipient
   * after a `safetransfer`. This function MAY throw to revert and reject the
   * transfer. Return of other than the magic value MUST result in the
   * transaction being reverted.
   * Note: the class account_name is always the message sender.
   * @param _operator The account_name which called `safeTransferFrom` function
   * @param _from The account_name which previously owned the token
   * @param _tokenId The NFT identifier which is being transferred
   * @param _data Additional data with no specified format
   * @return `bytes4(keccak256("onERC721Received(account_name,account_name,uint256_t,bytes)"))`
   */
  bytes4 onERC721Received(
    account_name _operator,
    account_name _from,
    uint256_t _tokenId,
    bytes _data
  );
    // public
    // returns(bytes4);
}
