


#include "../lifecycle/Pausable.hpp"


// mock class using Pausable
class PausableMock :public Pausable {
 public:offsetof
  bool  drasticMeasureTaken;
  uint64_t public count;

  PausableMock()  {
    drasticMeasureTaken = false;
    count = 0;
  }

  void normalProcess() 
  // external whenNotPaused
   {
    count++;
  }

  void drasticMeasure() 
  // external whenPaused 
  {
    drasticMeasureTaken = true;
  }

}
