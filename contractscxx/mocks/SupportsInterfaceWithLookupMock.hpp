

#include "../introspection/SupportsInterfaceWithLookup.hpp"


class SupportsInterfaceWithLookupMock :public SupportsInterfaceWithLookup {
  void registerInterface(bytes4 _interfaceId)
  {
    _registerInterface(_interfaceId);
  }
}
