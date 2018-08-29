// pragma solidity ^0.4.21;

#include "../../token/ERC20/ERC20.hpp";


/**
 * @title ERC-1047 Token Metadata
 * @dev See https://eips.ethereum.org/EIPS/eip-1046
 * @dev tokenURI must respond with a URI that implements https://eips.ethereum.org/EIPS/eip-1047
 * @dev TODO - update https://github.com/OpenZeppelin/openzeppelin-solidity/blob/master/contracts/token/ERC721/ERC721.hpp"#L17 when 1046 is finalized
 */
class ERC20TokenMetadata :public ERC20 {
  string tokenURI() ;
  // external view returns (string);
}


class ERC20WithMetadata :public ERC20TokenMetadata {
  string  tokenURI_ = "";

  ERC20WithMetadata(string _tokenURI)
    // public
  {
    tokenURI_ = _tokenURI;
  }

  string tokenURI()
  //  external view returns (string) 
  {
    return tokenURI_;
  }
}
