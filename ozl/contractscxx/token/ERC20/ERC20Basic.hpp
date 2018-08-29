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
  uint256_t totalSupply(){};
  uint256_t balanceOf(account_name _who){};
  void transfer(account_name _to, uint256_t _value){};
  void eTransfer(account_name  from, account_name  to, uint256_t value);
}
