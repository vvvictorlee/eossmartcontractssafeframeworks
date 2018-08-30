// 
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>

#include "./ERC20.hpp"


/**
 * @title DetailedERC20 token
 * @dev The decimals are only for visualization purposes.
 * All the operations are done using the smallest and indivisible token unit,
 * just as on Ethereum all the operations are done in wei.
 */
class DetailedERC20 : ERC20 {
  string  name;
  string  symbol;
  uint8_t  decimals;

  DetailedERC20(string _name, string _symbol, uint8 _decimals)  {
    name = _name;
    symbol = _symbol;
    decimals = _decimals;
  }
}
