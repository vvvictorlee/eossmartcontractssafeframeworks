

#include "../../contracts/ownership/HasNoEther.hpp"


class HasNoEtherTest :public HasNoEther {

  // Constructor with explicit payable — should still fail
  HasNoEtherTest() 
  // public payable 
  {
  }

}
