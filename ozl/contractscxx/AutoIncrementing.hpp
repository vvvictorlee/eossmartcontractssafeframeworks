// 


/**
 * @title AutoIncrementing
 * @author Matt Condon (@shrugs)
 * @dev Provides an auto-incrementing uint256_t id acquired by the `Counter#nextId` getter.
 * Use this for issuing ERC721Token ids or keeping track of request ids, anything you want, really.
 *
 * Include with `using AutoIncrementing for AutoIncrementing.Counter;`
 * @notice Does not allow an Id of 0, which is popularly used to signify a null state in solidity.
 * Does not protect from overflows, but if you have 2^256 ids, you have other problems.
 * (But actually, it's generally impossible to increment a counter this many times, energy wise
 * so it's not something you have to worry about.)
 */
class AutoIncrementing {

  struct Counter {
    uint256_t prevId; // default: 0
  }

  uint256_t nextId(Counter storage _counter)
    // internal
    // returns (uint256_t)
  {
    _counter.prevId = _counter.prevId + 1;
    return _counter.prevId;
  }
}
