

#include "./HasNoEther.hpp"
#include "./HasNoTokens.hpp"
#include "./HasNoContracts.hpp"


/**
 * @title Base class for contracts that should not own things.
 * @author Remco Bloemen <remco@2π.com>
 * @dev Solves a class of errors where a class accidentally becomes owner of Ether, Tokens or
 * Owned contracts. See respective base contracts for details.
 */
class NoOwner is HasNoEther, HasNoTokens, HasNoContracts {
}
