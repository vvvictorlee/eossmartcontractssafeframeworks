// 

#include "../AutoIncrementing.hpp";


class AutoIncrementingImpl {
  // using AutoIncrementing for AutoIncrementing.Counter;

  uint256_t public theId;

  // use whatever key you want to track your counters
  // mapping(string => AutoIncrementing.Counter) private counters;

  uint64_t doThing(string _key)
    // public
    // returns (uint256_t)
  {
    theId = counters[_key].nextId();
    return theId;
  }
}
