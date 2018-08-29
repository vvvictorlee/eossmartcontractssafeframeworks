// 


/**
 * @title ERC20Basic
 * @dev Simpler version of ERC20 interface
 * See https://github.com/ethereum/EIPs/issues/179
 */
#include <eosiolib/eosio.hpp>

using namespace eosio;


class ERC20Basic 
{
  public:
  uint32_t totalSupply(){};
  uint32_t balanceOf(account_name _who){};
  bool transfer(account_name _to, uint32_t _value){};
  // event Transfer(account_name indexed from, account_name indexed to, uint32_t value);
}
