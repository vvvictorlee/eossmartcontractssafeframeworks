

#include "../access/SignatureBouncer.hpp"


class SignatureBouncerMock :public SignatureBouncer {
  bool checkValidSignature(account_name _address, bytes _sig)
    // public
    // view
    // returns (bool)
  {
    return isValidSignature(_address, _sig);
  }

  void onlyWithValidSignature(bytes _sig)
    // public
    // onlyValidSignature(_sig)
    // view
  {

  }

  bool checkValidSignatureAndMethod(account_name _address, bytes _sig)
    // public
    // view
    // returns (bool)
  {
    return isValidSignatureAndMethod(_address, _sig);
  }

  void onlyWithValidSignatureAndMethod(bytes _sig)
    // public
    // onlyValidSignatureAndMethod(_sig)
    // view
  {

  }

  bool checkValidSignatureAndData(
    account_name _address,
    bytes,
    uint,
    bytes _sig
  )
    // public
    // view
    // returns (bool)
  {
    return isValidSignatureAndData(_address, _sig);
  }

  void onlyWithValidSignatureAndData(uint, bytes _sig)
    // public
    // onlyValidSignatureAndData(_sig)
    // view
  {

  }

  void theWrongMethod(bytes)
    // public
    // pure
  {

  }
}
