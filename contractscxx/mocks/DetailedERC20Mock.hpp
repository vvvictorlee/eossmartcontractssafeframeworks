

#include "../token/ERC20/StandardToken.hpp"
#include "../token/ERC20/DetailedERC20.hpp"


class DetailedERC20Mock :public  StandardToken,public DetailedERC20 {
  DetailedERC20Mock(
    string _name,
    string _symbol,
    uint8 _decimals
  ):DetailedERC20(_name, _symbol, _decimals)
   
  {}
}
