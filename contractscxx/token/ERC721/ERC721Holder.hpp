#include <eosiolib/eosio.hpp>

#include "./ERC721Receiver.hpp";


class ERC721Holder : ERC721Receiver {
  bytes4 onERC721Received(
    account_name,
    account_name,
    uint256_t,
    bytes
  )
    // public
    // returns(bytes4)
  {
    return ERC721_RECEIVED;
  }
}
