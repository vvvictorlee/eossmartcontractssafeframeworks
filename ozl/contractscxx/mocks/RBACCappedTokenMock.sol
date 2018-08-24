pragma solidity ^0.4.24;

import "../token/ERC20/RBACMintableToken.sol";
import "../token/ERC20/CappedToken.sol";


contract RBACCappedTokenMock is CappedToken, RBACMintableToken {
  constructor(uint256_t _cap)
    CappedToken(_cap)
    public
  {}
}
