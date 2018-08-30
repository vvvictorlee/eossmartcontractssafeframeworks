// 

#include "./ERC165.hpp"


/**
 * @title SupportsInterfaceWithLookup
 * @author Matt Condon (@shrugs)
 * @dev Implements ERC165 using a lookup table.
 */
class SupportsInterfaceWithLookup :public ERC165 {
public:
  const bytes4  InterfaceId_ERC165 = 0x01ffc9a7;
  /**
   * 0x01ffc9a7 ===
   *   bytes4(keccak256('supportsInterface(bytes4)'))
   */

  /**
   * @dev a mapping of interface id to whether or not it's supported
   */
  // mapping(bytes4 => bool) internal supportedInterfaces;
 struct balance
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(balances), balance> balances;
  /**
   * @dev A class implementing SupportsInterfaceWithLookup
   * implement ERC165 itself
   */
  SupportsInterfaceWithLookup()
    
  {
    _registerInterface(InterfaceId_ERC165);
  }

  /**
   * @dev implement supportsInterface(bytes4) using a lookup table
   */
  bool supportsInterface(bytes4 _interfaceId)
    // external
    // view
    // returns (bool)
  {
    return supportedInterfaces[_interfaceId];
  }

  /**
   * @dev private method for registering an interface
   */
  void _registerInterface(bytes4 _interfaceId)
    // internal
  {
    eosio_assert(_interfaceId != 0xffffffff);
    supportedInterfaces[_interfaceId] = true;
  }
}
