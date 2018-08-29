


#include "../lifecycle/Pausable.hpp"


// mock class using Pausable
class PausableMock is Pausable {
  bool public drasticMeasureTaken;
  uint256 public count;

  constructor() public {
    drasticMeasureTaken = false;
    count = 0;
  }

  function normalProcess() external whenNotPaused {
    count++;
  }

  function drasticMeasure() external whenPaused {
    drasticMeasureTaken = true;
  }

}
