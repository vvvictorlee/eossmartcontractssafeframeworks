

#include "../token/ERC20/StandardToken.hpp"
#include "../proposals/ERC1046/TokenMetadata.hpp"


class ERC20WithMetadataMock :public StandardToken,public ERC20WithMetadata {
  ERC20WithMetadataMock(string _tokenURI) :  ERC20WithMetadata(_tokenURI)
  {
  }
}
