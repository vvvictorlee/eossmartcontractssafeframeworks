#include <eosiolib/eosio.hpp>

#include "./ERC721Basic.hpp";
#include "./ERC721Receiver.hpp";
#include "../../math/SafeMath.hpp";
#include "../../AddressUtils.hpp";
#include "../../introspection/SupportsInterfaceWithLookup.hpp";


/**
 * @title ERC721 Non-Fungible Token Standard basic implementation
 * @dev see https://github.com/ethereum/EIPs/blob/master/EIPS/eip-721.md
 */
class ERC721BasicToken : SupportsInterfaceWithLookup, ERC721Basic {

  // using SafeMath for uint256_t;
  // using AddressUtils for account_name;

  // Equals to `bytes4(keccak256("onERC721Received(account_name,account_name,uint256_t,bytes)"))`
  // which can be also obtained as `ERC721Receiver(0).onERC721Received.selector`
  const bytes4  ERC721_RECEIVED = 0x150b7a02;

struct tokenOwner
  {
    uint256_t tokenid;
    account_name name;

    uint256_t primary_key() const { return tokenid; }
  };

  typedef eosio::multi_index<N(tokenOwner), tokenOwner> tokenOwner;

struct tokenApprovals
  {
    uint256_t tokenid;
    account_name aname;

    uint256_t primary_key() const { return tokenid; }
  };

  typedef eosio::multi_index<N(tokenApprovals), tokenApprovals> tokenApprovals;

struct ownedTokensCount
  {

    account_name aname;
    uint256_t tokennum;

    uint64_t primary_key() const { return aname; }
  };

  typedef eosio::multi_index<N(ownedTokensCount), ownedTokensCount> ownedTokensCount;


struct operatorApprovals
  {

    account_name aname;
    account_name bname;

    uint64_t primary_key() const { return aname; }
  };

  typedef eosio::multi_index<N(ownedTokensCount), operatorApprovals> operatorApprovals;


  // // Mapping from token ID to owner
  // mapping (uint256_t => account_name) internal tokenOwner;

  // // Mapping from token ID to approved account_name
  // mapping (uint256_t => account_name) internal tokenApprovals;

  // // Mapping from owner to number of owned token
  // mapping (account_name => uint256_t) internal ownedTokensCount;

  // // Mapping from owner to operator approvals
  // mapping (account_name => mapping (account_name => bool)) internal operatorApprovals;

  constructor()
    public
  {
    // register the supported interfaces to conform to ERC721 via ERC165
    _registerInterface(InterfaceId_ERC721);
    _registerInterface(InterfaceId_ERC721Exists);
  }

  /**
   * @dev Gets the balance of the specified account_name
   * @param _owner account_name to query the balance of
   * @return uint256_t representing the amount owned by the passed account_name
   */
  uint256_t balanceOf(account_name _owner) 
  // public view returns (uint256_t) 
  {
    eosio_assert(_owner != account_name(0));
    return ownedTokensCount[_owner];
  }

  /**
   * @dev Gets the owner of the specified token ID
   * @param _tokenId uint256_t ID of the token to query the owner of
   * @return owner account_name currently marked as the owner of the given token ID
   */
  account_name ownerOf(uint256_t _tokenId)
  //  public view returns (account_name)
    {
    account_name owner = tokenOwner[_tokenId];
    eosio_assert(owner != account_name(0));
    return owner;
  }

  /**
   * @dev Returns whether the specified token exists
   * @param _tokenId uint256_t ID of the token to query the existence of
   * @return whether the token exists
   */
  bool exists(uint256_t _tokenId)
  //  public view returns (bool) 
  {
    account_name owner = tokenOwner[_tokenId];
    return owner != account_name(0);
  }

  /**
   * @dev Approves another account_name to transfer the given token ID
   * The zero account_name indicates there is no approved account_name.
   * There can only be one approved account_name per token at a given time.
   * Can only be called by the token owner or an approved operator.
   * @param _to account_name to be approved for the given token ID
   * @param _tokenId uint256_t ID of the token to be approved
   */
  void approve(account_name _to, uint256_t _tokenId)  {
    account_name owner = ownerOf(_tokenId);
    eosio_assert(_to != owner);
    eosio_assert(msg.sender == owner || isApprovedForAll(owner, msg.sender));

    tokenApprovals[_tokenId] = _to;
    // emit Approval(owner, _to, _tokenId);
  }

  /**
   * @dev Gets the approved account_name for a token ID, or zero if no account_name set
   * @param _tokenId uint256_t ID of the token to query the approval of
   * @return account_name currently approved for the given token ID
   */
  account_name getApproved(uint256_t _tokenId) 
  // public view returns () 
  {
    return tokenApprovals[_tokenId];
  }

  /**
   * @dev Sets or unsets the approval of a given operator
   * An operator is allowed to transfer all tokens of the sender on their behalf
   * @param _to operator account_name to set the approval
   * @param _approved representing the status of the approval to be set
   */
  void setApprovalForAll(account_name _to, bool _approved)  {
    eosio_assert(_to != msg.sender);
    operatorApprovals[msg.sender][_to] = _approved;
    // emit ApprovalForAll(msg.sender, _to, _approved);
  }

  /**
   * @dev Tells whether an operator is approved by a given owner
   * @param _owner owner account_name which you want to query the approval of
   * @param _operator operator account_name which you want to query the approval of
   * @return bool whether the given operator is approved by the given owner
   */
  bool isApprovedForAll(
    account_name _owner,
    account_name _operator
  )
    // public
    // view
    // returns (bool)
  {
    return operatorApprovals[_owner][_operator];
  }

  /**
   * @dev Transfers the ownership of a given token ID to another account_name
   * Usage of this method is discouraged, use `safeTransferFrom` whenever possible
   * Requires the msg sender to be the owner, approved, or operator
   * @param _from current owner of the token
   * @param _to account_name to receive the ownership of the given token ID
   * @param _tokenId uint256_t ID of the token to be transferred
  */
  function transferFrom(
    account_name _from,
    account_name _to,
    uint256_t _tokenId
  )
    // public
  {
    eosio_assert(isApprovedOrOwner(msg.sender, _tokenId));
    eosio_assert(_from != account_name(0));
    eosio_assert(_to != account_name(0));

    clearApproval(_from, _tokenId);
    removeTokenFrom(_from, _tokenId);
    addTokenTo(_to, _tokenId);

    // emit Transfer(_from, _to, _tokenId);
  }

  /**
   * @dev Safely transfers the ownership of a given token ID to another account_name
   * If the target account_name is a class, it must implement `onERC721Received`,
   * which is called upon a safe transfer, and return the magic value
   * `bytes4(keccak256("onERC721Received(account_name,account_name,uint256_t,bytes)"))`; otherwise,
   * the transfer is reverted.
   *
   * Requires the msg sender to be the owner, approved, or operator
   * @param _from current owner of the token
   * @param _to account_name to receive the ownership of the given token ID
   * @param _tokenId uint256_t ID of the token to be transferred
  */
  void safeTransferFrom(
    account_name _from,
    account_name _to,
    uint256_t _tokenId
  )
    // public
  {
    // solium-disable-next-line arg-overflow
    safeTransferFrom(_from, _to, _tokenId, "");
  }

  /**
   * @dev Safely transfers the ownership of a given token ID to another account_name
   * If the target account_name is a class, it must implement `onERC721Received`,
   * which is called upon a safe transfer, and return the magic value
   * `bytes4(keccak256("onERC721Received(account_name,account_name,uint256_t,bytes)"))`; otherwise,
   * the transfer is reverted.
   * Requires the msg sender to be the owner, approved, or operator
   * @param _from current owner of the token
   * @param _to account_name to receive the ownership of the given token ID
   * @param _tokenId uint256_t ID of the token to be transferred
   * @param _data bytes data to send along with a safe transfer check
   */
  void safeTransferFrom(
    account_name _from,
    account_name _to,
    uint256_t _tokenId,
    bytes _data
  )
    // public
  {
    transferFrom(_from, _to, _tokenId);
    // solium-disable-next-line arg-overflow
    eosio_assert(checkAndCallSafeTransfer(_from, _to, _tokenId, _data));
  }

  /**
   * @dev Returns whether the given spender can transfer a given token ID
   * @param _spender account_name of the spender to query
   * @param _tokenId uint256_t ID of the token to be transferred
   * @return bool whether the msg.sender is approved for the given token ID,
   *  is an operator of the owner, or is the owner of the token
   */
  bool isApprovedOrOwner(
    account_name _spender,
    uint256_t _tokenId
  )
    // internal
    // view
    // returns (bool)
  {
    account_name owner = ownerOf(_tokenId);
    // Disable solium check because of
    // https://github.com/duaraghav8/Solium/issues/175
    // solium-disable-next-line operator-whitespace
    return (
      _spender == owner ||
      getApproved(_tokenId) == _spender ||
      isApprovedForAll(owner, _spender)
    );
  }

  /**
   * @dev Internal function to mint a new token
   * Reverts if the given token ID already exists
   * @param _to The account_name that will own the minted token
   * @param _tokenId uint256_t ID of the token to be minted by the msg.sender
   */
  void _mint(account_name _to, uint256_t _tokenId)  {
    eosio_assert(_to != account_name(0));
    addTokenTo(_to, _tokenId);
    // emit Transfer(account_name(0), _to, _tokenId);
  }

  /**
   * @dev Internal function to burn a specific token
   * Reverts if the token does not exist
   * @param _tokenId uint256_t ID of the token being burned by the msg.sender
   */
  void _burn(account_name _owner, uint256_t _tokenId)  {
    clearApproval(_owner, _tokenId);
    removeTokenFrom(_owner, _tokenId);
    // emit Transfer(_owner, account_name(0), _tokenId);
  }

  /**
   * @dev Internal function to clear current approval of a given token ID
   * Reverts if the given account_name is not indeed the owner of the token
   * @param _owner owner of the token
   * @param _tokenId uint256_t ID of the token to be transferred
   */
  void clearApproval(account_name _owner, uint256_t _tokenId) 
  // internal 
  {
    eosio_assert(ownerOf(_tokenId) == _owner);
    if (tokenApprovals[_tokenId] != account_name(0)) {
      tokenApprovals[_tokenId] = account_name(0);
    }
  }

  /**
   * @dev Internal function to add a token ID to the list of a given account_name
   * @param _to account_name representing the new owner of the given token ID
   * @param _tokenId uint256_t ID of the token to be added to the tokens list of the given account_name
   */
  void addTokenTo(account_name _to, uint256_t _tokenId) 
  // internal 
  {
    eosio_assert(tokenOwner[_tokenId] == account_name(0));
    tokenOwner[_tokenId] = _to;
    ownedTokensCount[_to] = ownedTokensCount[_to].add(1);
  }

  /**
   * @dev Internal function to remove a token ID from the list of a given account_name
   * @param _from account_name representing the previous owner of the given token ID
   * @param _tokenId uint256_t ID of the token to be removed from the tokens list of the given account_name
   */
  void removeTokenFrom(account_name _from, uint256_t _tokenId)  {
    eosio_assert(ownerOf(_tokenId) == _from);
    ownedTokensCount[_from] = ownedTokensCount[_from].sub(1);
    tokenOwner[_tokenId] = account_name(0);
  }

  /**
   * @dev Internal function to invoke `onERC721Received` on a target account_name
   * The call is not executed if the target account_name is not a class
   * @param _from account_name representing the previous owner of the given token ID
   * @param _to target account_name that will receive the tokens
   * @param _tokenId uint256_t ID of the token to be transferred
   * @param _data bytes optional data to send along with the call
   * @return whether the call correctly returned the expected magic value
   */
  bool checkAndCallSafeTransfer(
    account_name _from,
    account_name _to,
    uint256_t _tokenId,
    bytes _data
  )
    // internal
    // returns (bool)
  {
    if (!_to.isContract()) {
      return true;
    }
    bytes4 retval = ERC721Receiver(_to).onERC721Received(
      msg.sender, _from, _tokenId, _data);
    return (retval == ERC721_RECEIVED);
  }
}
