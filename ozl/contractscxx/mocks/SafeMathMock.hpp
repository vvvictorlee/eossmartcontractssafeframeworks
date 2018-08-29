


#include "../math/SafeMath.hpp"


class SafeMathMock {

  uint64_t mul(uint64_t _a, uint64_t _b) 
  // public pure returns (uint64_t) 
  {
    return SafeMath.mul(_a, _b);
  }

  uint64_t div(uint64_t _a, uint64_t _b)
  //  public pure returns (uint64_t) 
   {
    return SafeMath.div(_a, _b);
  }

  uint64_t sub(uint64_t _a, uint64_t _b)
  //  public pure returns (uint64_t) 
  {
    return SafeMath.sub(_a, _b);
  }

  uint64_t add(uint64_t _a, uint64_t _b) 
  // public pure returns (uint64_t) 
  {
    return SafeMath.add(_a, _b);
  }
}
