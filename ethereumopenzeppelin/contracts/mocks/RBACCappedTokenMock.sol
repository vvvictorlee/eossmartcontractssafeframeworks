

#include "../token/ERC20/RBACMintableToken.hpp"
#include "../token/ERC20/CappedToken.hpp"


class RBACCappedTokenMock is CappedToken, RBACMintableToken {
  constructor(uint256 _cap)
    CappedToken(_cap)
    public
  {}
}
