

#include "../introspection/SupportsInterfaceWithLookup.hpp"


class SupportsInterfaceWithLookupMock is SupportsInterfaceWithLookup {
  function registerInterface(bytes4 _interfaceId)
    public
  {
    _registerInterface(_interfaceId);
  }
}
