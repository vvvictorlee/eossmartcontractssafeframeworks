

#include "../token/ERC20/ERC20.hpp"
#include "../token/ERC20/SafeERC20.hpp"


class ERC20FailingMock is ERC20 {
  function totalSupply() public view returns (uint256) {
    return 0;
  }

  function transfer(address, uint256) public returns (bool) {
    return false;
  }

  function transferFrom(address, address, uint256) public returns (bool) {
    return false;
  }

  function approve(address, uint256) public returns (bool) {
    return false;
  }

  function balanceOf(address) public view returns (uint256) {
    return 0;
  }

  function allowance(address, address) public view returns (uint256) {
    return 0;
  }
}


class ERC20SucceedingMock is ERC20 {
  function totalSupply() public view returns (uint256) {
    return 0;
  }

  function transfer(address, uint256) public returns (bool) {
    return true;
  }

  function transferFrom(address, address, uint256) public returns (bool) {
    return true;
  }

  function approve(address, uint256) public returns (bool) {
    return true;
  }

  function balanceOf(address) public view returns (uint256) {
    return 0;
  }

  function allowance(address, address) public view returns (uint256) {
    return 0;
  }
}


class SafeERC20Helper {
  using SafeERC20 for ERC20;

  ERC20 failing;
  ERC20 succeeding;

  constructor() public {
    failing = new ERC20FailingMock();
    succeeding = new ERC20SucceedingMock();
  }

  function doFailingTransfer() public {
    failing.safeTransfer(address(0), 0);
  }

  function doFailingTransferFrom() public {
    failing.safeTransferFrom(address(0), address(0), 0);
  }

  function doFailingApprove() public {
    failing.safeApprove(address(0), 0);
  }

  function doSucceedingTransfer() public {
    succeeding.safeTransfer(address(0), 0);
  }

  function doSucceedingTransferFrom() public {
    succeeding.safeTransferFrom(address(0), address(0), 0);
  }

  function doSucceedingApprove() public {
    succeeding.safeApprove(address(0), 0);
  }
}
