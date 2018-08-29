// 

#include "../AutoIncrementing.hpp";


class AutoIncrementingImpl {
  // using AutoIncrementing for AutoIncrementing.Counter;

  uint256_t public theId;

  // use whatever key you want to track your counters
  // mapping(string => AutoIncrementing.Counter) private counters;
 struct balance
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(balances), balance> balances;
  uint64_t doThing(string _key)
    // public
    // returns (uint256_t)
  {
    theId = counters[_key].nextId();
    return theId;
  }
}
