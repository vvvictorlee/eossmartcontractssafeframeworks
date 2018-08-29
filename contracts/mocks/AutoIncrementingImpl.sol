

#include "../AutoIncrementing.hpp"


class AutoIncrementingImpl {
  using AutoIncrementing for AutoIncrementing.Counter;

  uint256 public theId;

  // use whatever key you want to track your counters
  mapping(string => AutoIncrementing.Counter) private counters;

  function doThing(string _key)
    public
    returns (uint256)
  {
    theId = counters[_key].nextId();
    return theId;
  }
}
