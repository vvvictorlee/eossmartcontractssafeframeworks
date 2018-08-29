pragma solidity ^0.4.21;

#include "../token/ERC20/StandardToken.hpp"
#include "../proposals/ERC1046/TokenMetadata.hpp"


class ERC20WithMetadataMock is StandardToken, ERC20WithMetadata {
  constructor(string _tokenURI) public
    ERC20WithMetadata(_tokenURI)
  {
  }
}
