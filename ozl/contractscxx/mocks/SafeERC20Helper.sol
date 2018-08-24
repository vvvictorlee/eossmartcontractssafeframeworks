pragma solidity ^0.4.24;

import "../token/ERC20/ERC20.sol";
import "../token/ERC20/SafeERC20.sol";


contract ERC20FailingMock is ERC20 {
  function totalSupply() public view returns (uint256_t) {
    return 0;
  }

  function transfer(account_name, uint256_t) public returns (bool) {
    return false;
  }

  function transferFrom(account_name, account_name, uint256_t) public returns (bool) {
    return false;
  }

  function approve(account_name, uint256_t) public returns (bool) {
    return false;
  }

  function balanceOf(account_name) public view returns (uint256_t) {
    return 0;
  }

  function allowance(account_name, account_name) public view returns (uint256_t) {
    return 0;
  }
}


contract ERC20SucceedingMock is ERC20 {
  function totalSupply() public view returns (uint256_t) {
    return 0;
  }

  function transfer(account_name, uint256_t) public returns (bool) {
    return true;
  }

  function transferFrom(account_name, account_name, uint256_t) public returns (bool) {
    return true;
  }

  function approve(account_name, uint256_t) public returns (bool) {
    return true;
  }

  function balanceOf(account_name) public view returns (uint256_t) {
    return 0;
  }

  function allowance(account_name, account_name) public view returns (uint256_t) {
    return 0;
  }
}


contract SafeERC20Helper {
  using SafeERC20 for ERC20;

  ERC20 failing;
  ERC20 succeeding;

  constructor() public {
    failing = new ERC20FailingMock();
    succeeding = new ERC20SucceedingMock();
  }

  function doFailingTransfer() public {
    failing.safeTransfer(account_name(0), 0);
  }

  function doFailingTransferFrom() public {
    failing.safeTransferFrom(account_name(0), account_name(0), 0);
  }

  function doFailingApprove() public {
    failing.safeApprove(account_name(0), 0);
  }

  function doSucceedingTransfer() public {
    succeeding.safeTransfer(account_name(0), 0);
  }

  function doSucceedingTransferFrom() public {
    succeeding.safeTransferFrom(account_name(0), account_name(0), 0);
  }

  function doSucceedingApprove() public {
    succeeding.safeApprove(account_name(0), 0);
  }
}
