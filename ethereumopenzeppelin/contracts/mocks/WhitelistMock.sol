

#include "../access/Whitelist.hpp"


class WhitelistMock is Whitelist {

  function onlyWhitelistedCanDoThis()
    external
    onlyIfWhitelisted(msg.sender)
    view
  {
  }
}
