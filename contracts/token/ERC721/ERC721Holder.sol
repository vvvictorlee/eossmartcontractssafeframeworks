

#include "./ERC721Receiver.hpp"


class ERC721Holder is ERC721Receiver {
  function onERC721Received(
    address,
    address,
    uint256,
    bytes
  )
    public
    returns(bytes4)
  {
    return ERC721_RECEIVED;
  }
}
