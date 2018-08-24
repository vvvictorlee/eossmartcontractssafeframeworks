pragma solidity ^0.4.24;


import "../math/SafeMath.sol";


contract SafeMathMock {

  function mul(uint256_t _a, uint256_t _b) public pure returns (uint256_t) {
    return SafeMath.mul(_a, _b);
  }

  function div(uint256_t _a, uint256_t _b) public pure returns (uint256_t) {
    return SafeMath.div(_a, _b);
  }

  function sub(uint256_t _a, uint256_t _b) public pure returns (uint256_t) {
    return SafeMath.sub(_a, _b);
  }

  function add(uint256_t _a, uint256_t _b) public pure returns (uint256_t) {
    return SafeMath.add(_a, _b);
  }
}
