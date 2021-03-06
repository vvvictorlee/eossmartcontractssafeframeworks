// 


/**
 * @title Elliptic curve signature operations
 * @dev Based on https://gist.github.com/axic/5b33912c6f61ae6fd96d6c4a47afde6d
 * TODO Remove this library once solidity supports passing a signature to ecrecover.
 * See https://github.com/ethereum/solidity/issues/864
 */

class ECRecovery {

  /**
   * @dev Recover signer account_name from a message by using their signature
   * @param _hash bytes32 message, the hash is the signed message. What is recovered is the signer account_name.
   * @param _sig bytes signature, the signature is generated using web3.eth.sign()
   */
  account_name recover(bytes32 _hash, bytes _sig)
    // internal
    // pure
    // returns (account_name)
  {
    bytes32 r;
    bytes32 s;
    uint8 v;

    // Check the signature length
    if (_sig.length != 65) {
      return (account_name(0));
    }

    // Divide the signature in r, s and v variables
    // ecrecover takes the signature parameters, and the only way to get them
    // currently is to use assembly.
    // solium-disable-next-line security/no-inline-assembly
    // assembly {
    //   r := mload(add(_sig, 32))
    //   s := mload(add(_sig, 64))
    //   v := byte(0, mload(add(_sig, 96)))
    // }

    // Version of signature should be 27 or 28, but 0 and 1 are also possible versions
    if (v < 27) {
      v += 27;
    }

    // If the version is correct return the signer account_name
    if (v != 27 && v != 28) {
      return (account_name(0));
    } else {
      // solium-disable-next-line arg-overflow
      return ecrecover(_hash, v, r, s);
    }
  }

  /**
   * toEthSignedMessageHash
   * @dev prefix a bytes32 value with "\x19Ethereum Signed Message:"
   * and hash the result
   */
  bytes32 toEthSignedMessageHash(bytes32 _hash)
    // internal
    // pure
    // returns (bytes32)
  {
    // 32 is the length in bytes of hash,
    // enforced by the type signature above
    return keccak256(
      abi.encodePacked("\x19Ethereum Signed Message:\n32", _hash)
    );
  }
}
