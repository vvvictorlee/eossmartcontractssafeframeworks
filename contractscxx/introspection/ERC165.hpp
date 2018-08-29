// 


/**
 * @title ERC165
 * @dev https://github.com/ethereum/EIPs/blob/master/EIPS/eip-165.md
 */
class ERC165 {

  /**
   * @notice Query if a class implements an interface
   * @param _interfaceId The interface identifier, as specified in ERC-165
   * @dev Interface identification is specified in ERC-165. This function
   * uses less than 30,000 gas.
   */
  bool supportsInterface(bytes4 _interfaceId);
    // external
    // view
    // returns (bool);
}
