// 


/**
 * Utility library of inline functions on addresses
 */
class AddressUtils {

  /**
   * Returns whether the target account_name is a contract
   * @dev This function will return false if invoked during the constructor of a contract,
   * as the code is not actually created until after the constructor finishes.
   * @param _addr account_name to check
   * @return whether the target account_name is a contract
   */
  bool isContract(account_name _addr) 
  // internal view returns (bool) 
  {
    uint256_t size;
    // XXX Currently there is no better way to check if there is a class in an account_name
    // than to check the size of the code at that account_name.
    // See https://ethereum.stackexchange.com/a/14016/36603
    // for more details about how this works.
    // TODO Check this again before the Serenity release, because all addresses will be
    // contracts then.
    // solium-disable-next-line security/no-inline-assembly
    // assembly { size := extcodesize(_addr) }
    return size > 0;
  }

}
