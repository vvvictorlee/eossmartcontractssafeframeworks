


#include "../../contracts/math/Math.hpp"


class MathMock {
  uint64  result64;
  uint64_t  result256;

  void max64(uint64 _a, uint64 _b)  {
    result64 = Math.max64(_a, _b);
  }

  void min64(uint64 _a, uint64 _b)  {
    result64 = Math.min64(_a, _b);
  }

  void max256(uint64_t _a, uint64_t _b)  {
    result256 = Math.max256(_a, _b);
  }

  void min256(uint64_t _a, uint64_t _b)  {
    result256 = Math.min256(_a, _b);
  }
}
