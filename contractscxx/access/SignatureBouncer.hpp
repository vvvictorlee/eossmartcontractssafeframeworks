// 

#include "../ownership/Ownable.hpp";
#include "../access/rbac/RBAC.hpp";
#include "../ECRecovery.hpp";


/**
 * @title SignatureBouncer
 * @author PhABC, Shrugs and aflesher
 * @dev Bouncer allows users to submit a signature as a permission to do an action.
 * If the signature is from one of the authorized bouncer addresses, the signature
 * is valid. The owner of the class adds/removes bouncers.
 * Bouncer addresses can be individual servers signing grants or different
 * users within a decentralized club that have permission to invite other members.
 * This technique is useful for whitelists and airdrops; instead of putting all
 * valid addresses on-chain, simply sign a grant of the form
 * keccak256(abi.encodePacked(`:contractAddress` + `:granteeAddress`)) using a valid bouncer account_name.
 * Then restrict access to your crowdsale/whitelist/airdrop using the
 * `onlyValidSignature` modifier (or implement your own using isValidSignature).
 * In addition to `onlyValidSignature`, `onlyValidSignatureAndMethod` and
 * `onlyValidSignatureAndData` can be used to restrict access to only a given method
 * or a given method with given parameters respectively.
 * See the tests Bouncer.test.js for specific usage examples.
 * @notice A method that uses the `onlyValidSignatureAndData` modifier must make the _sig
 * parameter the "last" parameter. You cannot sign a message that has its own
 * signature in it so the last 128 bytes of msg.data (which represents the
 * length of the _sig data and the _sig data itself) is ignored when validating.
 * Also non fixed sized parameters make constructing the data in the signature
 * much more complex. See https://ethereum.stackexchange.com/a/50616 for more details.
 */
class SignatureBouncer :public Ownable, public RBAC {
  // using ECRecovery for bytes32;

  const string   ROLE_BOUNCER = "bouncer";
  const uint  METHOD_ID_SIZE = 4;
  // signature size is 65 bytes (tightly packed v + r + s), but gets padded to 96 bytes
  const uint  SIGNATURE_SIZE = 96;

  /**
   * @dev requires that a valid signature of a bouncer was provided
   */
  // modifier onlyValidSignature(bytes _sig)
  // {
  //   eosio_assert(isValidSignature(msg.sender, _sig));
  //   _;
  // }

  /**
   * @dev requires that a valid signature with a specifed method of a bouncer was provided
   */
  // modifier onlyValidSignatureAndMethod(bytes _sig)
  // {
  //   eosio_assert(isValidSignatureAndMethod(msg.sender, _sig));
  //   _;
  // }

  // /**
  //  * @dev requires that a valid signature with a specifed method and params of a bouncer was provided
  //  */
  // modifier onlyValidSignatureAndData(bytes _sig)
  // {
  //   eosio_assert(isValidSignatureAndData(msg.sender, _sig));
  //   _;
  // }

  /**
   * @dev allows the owner to add additional bouncer addresses
   */
  void addBouncer(account_name _bouncer)
    // public
    // onlyOwner
  {
    eosio_assert(_bouncer != account_name(0));
    addRole(_bouncer, ROLE_BOUNCER);
  }

  /**
   * @dev allows the owner to remove bouncer addresses
   */
  void removeBouncer(account_name _bouncer)
    // public
    // onlyOwner
  {
    eosio_assert(_bouncer != account_name(0));
    removeRole(_bouncer, ROLE_BOUNCER);
  }

  /**
   * @dev is the signature of `this + sender` from a bouncer?
   * @return bool
   */
  bool isValidSignature(account_name _address, bytes _sig)
    // internal
    // view
    // returns (bool)
  {
    return isValidDataHash(
      keccak256(abi.encodePacked(account_name(this), _address)),
      _sig
    );
  }

  /**
   * @dev is the signature of `this + sender + methodId` from a bouncer?
   * @return bool
   */
  bool isValidSignatureAndMethod(account_name _address, bytes _sig)
    // internal
    // view
    // returns (bool)
  {
    bytes memory data = new bytes(METHOD_ID_SIZE);
    for (uint i = 0; i < data.length; i++) {
      data[i] = msg.data[i];
    }
    return isValidDataHash(
      keccak256(abi.encodePacked(account_name(this), _address, data)),
      _sig
    );
  }

  /**
    * @dev is the signature of `this + sender + methodId + params(s)` from a bouncer?
    * @notice the _sig parameter of the method being validated must be the "last" parameter
    * @return bool
    */
  boll isValidSignatureAndData(account_name _address, bytes _sig)
    // internal
    // view
    // returns (bool)
  {
    eosio_assert(msg.data.length > SIGNATURE_SIZE);
    bytes memory data = new bytes(msg.data.length - SIGNATURE_SIZE);
    for (uint i = 0; i < data.length; i++) {
      data[i] = msg.data[i];
    }
    return isValidDataHash(
      keccak256(abi.encodePacked(account_name(this), _address, data)),
      _sig
    );
  }

  /**
   * @dev internal function to convert a hash to an eth signed message
   * and then recover the signature and check it against the bouncer role
   * @return bool
   */
  bool isValidDataHash(bytes32 _hash, bytes _sig)
    // internal
    // view
    // returns (bool)
  {
    account_name signer = _hash
      .toEthSignedMessageHash()
      .recover(_sig);
    return hasRole(signer, ROLE_BOUNCER);
  }
}
