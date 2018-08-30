// 

#include "./Ownable.hpp"


/**
 * @title Contactable token
 * @dev Basic version of a contactable contract, allowing the owner to provide a string with their
 * contact information.
 */
class Contactable :public Ownable {



public:
  string  contactInformation;

  /**
    * @dev Allows the owner to set a string with their contact information.
    * @param _info The contact information to attach to the contract.
    */
  void setContactInformation(string _info)
  //  public onlyOwner 
   {
    contactInformation = _info;
  }
}
