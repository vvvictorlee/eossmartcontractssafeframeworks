

#include "../examples/RBACWithAdmin.hpp"


class RBACMock is RBACWithAdmin {

  string constant ROLE_ADVISOR = "advisor";

  modifier onlyAdminOrAdvisor()
  {
    require(
      hasRole(msg.sender, ROLE_ADMIN) ||
      hasRole(msg.sender, ROLE_ADVISOR)
    );
    _;
  }

  constructor(address[] _advisors)
    public
  {
    addRole(msg.sender, ROLE_ADVISOR);

    for (uint256 i = 0; i < _advisors.length; i++) {
      addRole(_advisors[i], ROLE_ADVISOR);
    }
  }

  function onlyAdminsCanDoThis()
    external
    onlyAdmin
    view
  {
  }

  function onlyAdvisorsCanDoThis()
    external
    onlyRole(ROLE_ADVISOR)
    view
  {
  }

  function eitherAdminOrAdvisorCanDoThis()
    external
    onlyAdminOrAdvisor
    view
  {
  }

  function nobodyCanDoThis()
    external
    onlyRole("unknown")
    view
  {
  }

  // admins can remove advisor's role
  function removeAdvisor(address _addr)
    public
    onlyAdmin
  {
    // revert if the user isn't an advisor
    //  (perhaps you want to soft-fail here instead?)
    checkRole(_addr, ROLE_ADVISOR);

    // remove the advisor's role
    removeRole(_addr, ROLE_ADVISOR);
  }
}
