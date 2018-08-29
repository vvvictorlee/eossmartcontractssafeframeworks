


class MessageHelper {

  // event Show(bytes32 b32, uint256_t number, string text);
  // event Buy(bytes32 b32, uint256_t number, string text, uint256_t value);

  bool showMessage(
    bytes32 _message,
    uint256_t _number,
    string _text
  )
    // public
    // returns (bool)
  {
    // emit Show(_message, _number, _text);
    return true;
  }

  function buyMessage(
    bytes32 _message,
    uint256_t _number,
    string _text
  )
    public
    payable
    returns (bool)
  {
    emit Buy(
      _message,
      _number,
      _text,
      msg.value);
    return true;
  }

  function fail() public {
    eosio_assert(false);
  }

  function call(account_name _to, bytes _data) public returns (bool) {
    // solium-disable-next-line security/no-low-level-calls
    if (_to.call(_data))
      return true;
    else
      return false;
  }

}
