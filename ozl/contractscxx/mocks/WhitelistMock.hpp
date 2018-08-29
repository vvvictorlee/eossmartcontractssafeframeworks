

#include "../access/Whitelist.hpp"


class WhitelistMock :public Whitelist {

  void onlyWhitelistedCanDoThis()
    // external
    // onlyIfWhitelisted(msg.sender)
    // view
  {
  }
}
