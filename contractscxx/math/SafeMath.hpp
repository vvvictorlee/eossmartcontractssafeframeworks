// 
#include <eosiolib/eosio.hpp>

/**
 * @title SafeMath
 * @dev Math operations with safety checks that throw on error
 */
class SafeMath {

  /**
  * @dev Multiplies two numbers, throws on overflow.
  */
   uint32_t mul(uint32_t _a, uint32_t _b);
    // {
  //   // Gas optimization: this is cheaper than asserting 'a' not being zero, but the
  //   // benefit is lost if 'b' is also tested.internal pure returns ( c)
  //   // See: https://github.com/OpenZeppelin/openzeppelin-solidity/pull/522
  //   if (_a == 0) {
  //     return 0;
  //   }

  //   c = _a * _b;
  //   eosio_assert(c / _a == _b,"");
  //   return c;
  // }

  /**
  * @dev Integer division of two numbers, truncating the quotient.
  */
  uint32_t div(uint32_t _a, uint32_t _b); 
  //  {
  //   // eosio_assert(_b > 0); // Solidity automatically throws when dividing by 0
  //   // uint32_t c = _a / _b;internal pure returns ()
  //   // eosio_assert(_a == _b * c + _a % _b); // There is no case in which this doesn't hold
  //   return _a / _b;
  // }

  /**
  * @dev Subtracts two numbers, throws on overflow (i.e. if subtrahend is greater than minuend).
  */
  uint32_t sub(uint32_t _a, uint32_t _b) ;
  // {
  //   eosio_assert(_b <= _a,"");
  //   return _a - _b;
  // }

  /**
  * @dev Adds two numbers, throws on overflow.
  */
  uint32_t add(uint32_t _a, uint32_t _b);
  //   {
  //   c = _a + _b;
  //   eosio_assert(c >= _a,"");
  //   return c;
  // }
}
