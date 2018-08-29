


#include "../ECRecovery.hpp"


class ECRecoveryMock {
  // using ECRecovery for bytes32;

  account_name recover(bytes32 _hash, bytes _sig)
    // public
    // pure
    // returns (account_name)
  {
    return _hash.recover(_sig);
  }

  bytes32 toEthSignedMessageHash(bytes32 _hash)
    // public
    // pure
    // returns (bytes32)
  {
    return _hash.toEthSignedMessageHash();
  }
}
