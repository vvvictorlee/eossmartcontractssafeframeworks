

#include "../token/ERC20/ERC20.hpp"
#include "../token/ERC20/SafeERC20.hpp"


class ERC20FailingMock :public ERC20 {
  uint64_t totalSupply() 
  // public view returns (uint64_t)
   {
    return 0;
  }

  bool transfer(account_name, uint64_t) 
  // public returns (bool) 
  {
    return false;
  }

  bool transferFrom(account_name, account_name, uint64_t)
  //  public returns (bool) 
   {
    return false;
  }

  bool approve(account_name, uint64_t) 
  // public returns (bool)
   {
    return false;
  }

  uint64_t balanceOf(account_name) 
  // public view returns (uint64_t) 
  {
    return 0;
  }

  uint64_t allowance(account_name, account_name)
  //  public view returns (uint64_t) 
   {
    return 0;
  }
}


class ERC20SucceedingMock :public ERC20 {
  uint64_t totalSupply()
  // public view returns (uint64_t) 
   {
    return 0;
  }

  bool transfer(account_name, uint64_t)// public returns (bool)
  {
    return true;
  }

  uint64_t transferFrom(account_name, account_name, uint64_t) 
  // public returns (bool)
   {
    return true;
  }

  uint64_t approve(account_name, uint64_t) 
  // public returns (bool) 
  {
    return true;
  }

  uint64_t balanceOf(account_name) 
  // public view returns (uint64_t) 
  {
    return 0;
  }

  uint64_t allowance(account_name, account_name) 
  // public view returns (uint64_t) 
  {
    return 0;
  }
}


class SafeERC20Helper {
  // using SafeERC20 for ERC20;

  ERC20 failing;
  ERC20 succeeding;

  SafeERC20Helper()  {
    failing = new ERC20FailingMock();
    succeeding = new ERC20SucceedingMock();
  }

  uint64_t doFailingTransfer()  {
    failing.safeTransfer(account_name(0), 0);
  }

  uint64_t doFailingTransferFrom()  {
    failing.safeTransferFrom(account_name(0), account_name(0), 0);
  }

  uint64_t doFailingApprove()  {
    failing.safeApprove(account_name(0), 0);
  }

  uint64_t doSucceedingTransfer()  {
    succeeding.safeTransfer(account_name(0), 0);
  }

  uint64_t doSucceedingTransferFrom()  {
    succeeding.safeTransferFrom(account_name(0), account_name(0), 0);
  }

  uint64_t doSucceedingApprove()  {
    succeeding.safeApprove(account_name(0), 0);
  }
}
