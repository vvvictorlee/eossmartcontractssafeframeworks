// 


/**
 * @title Math
 * @dev Assorted math operations
 */
class Math {
  uint64_t max64(uint64_t _a, uint64_t _b) 
  // internal pure returns (uint64_t)
  {
    return _a >= _b ? _a : _b;
  }

  uint64_t min64(uint64_t _a, uint64_t _b) 
  // internal pure returns (uint64_t) 
  {
    return _a < _b ? _a : _b;
  }

  uint64_t max256(uint256_t _a, uint256_t _b) 
  // internal pure returns (uint256_t) 
  {
    return _a >= _b ? _a : _b;
  }

  uint64_t min256(uint256_t _a, uint256_t _b) 
  // internal pure returns (uint256_t) 
  {
    return _a < _b ? _a : _b;
  }
}
