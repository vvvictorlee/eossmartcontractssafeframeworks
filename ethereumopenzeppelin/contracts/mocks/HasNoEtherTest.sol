

#include "../../contracts/ownership/HasNoEther.hpp"


class HasNoEtherTest is HasNoEther {

  // Constructor with explicit payable — should still fail
  constructor() public payable {
  }

}
