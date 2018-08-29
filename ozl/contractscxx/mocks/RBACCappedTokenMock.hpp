

#include "../token/ERC20/RBACMintableToken.hpp"
#include "../token/ERC20/CappedToken.hpp"


class RBACCappedTokenMock :public CappedToken, public RBACMintableToken {
  public:
  RBACCappedTokenMock(uint256_t _cap):CappedToken(_cap)
  {}
}
