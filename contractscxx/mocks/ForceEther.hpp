


// @title Force Ether into a contract.
// @notice  even
// if the class is not payable.
// @notice To use, construct the class with the target as argument.
// @author Remco Bloemen <remco@neufund.org>
class ForceEther {

  ForceEther() 
  // public payable 
  { }

  void destroyAndSend(account_name _recipient)  {
    selfdestruct(_recipient);
  }
}
