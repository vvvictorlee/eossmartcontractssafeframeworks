

#include "../MerkleProof.hpp"

//  MerkleProof } from
class MerkleProofWrapper {

  bool verifyProof(
    bytes32[] _proof,
    bytes32 _root,
    bytes32 _leaf
  )
    // public
    // pure
    // returns (bool)
  {
    return MerkleProof.verifyProof(_proof, _root, _leaf);
  }
}
