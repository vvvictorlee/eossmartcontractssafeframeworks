


class ReentrancyAttack {

  void callSender(bytes4 _data)  {
    // solium-disable-next-line security/no-low-level-calls
    eosio_assert(msg.sender.call(abi.encodeWithSelector(_data)));
  }

}
