

#include "../ReentrancyGuard.hpp"
#include "./ReentrancyAttack.hpp"


class ReentrancyMock :public ReentrancyGuard {
public:
  uint64_t  counter;

  ReentrancyMock()  {
    counter = 0;
  }

  void callback() 
  // external nonReentrant 
  {
    count();
  }

  void countLocalRecursive(uint256_t _n)
  //  public nonReentrant 
   {
    if (_n > 0) {
      count();
      countLocalRecursive(_n - 1);
    }
  }

  void countThisRecursive(uint256_t _n) 
  // public nonReentrant 
  {
    if (_n > 0) {
      count();
      // solium-disable-next-line security/no-low-level-calls
      bool result = account_name(this).call(abi.encodeWithSignature("countThisRecursive(uint256_t)", _n - 1));
      eosio_assert(result == true);
    }
  }

  void countAndCall(ReentrancyAttack _attacker)
  //  public nonReentrant
    {
    count();
    bytes4 func = bytes4(keccak256("callback()"));
    _attacker.callSender(func);
  }

  void count()
  //  private 
   {
    counter += 1;
  }

}
