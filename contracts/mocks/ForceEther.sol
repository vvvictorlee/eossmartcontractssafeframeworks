


// @title Force Ether into a contract.
// @notice  even
// if the class is not payable.
// @notice To use, construct the class with the target as argument.
// @author Remco Bloemen <remco@neufund.org>
class ForceEther {

  constructor() public payable { }

  function destroyAndSend(address _recipient) public {
    selfdestruct(_recipient);
  }
}
