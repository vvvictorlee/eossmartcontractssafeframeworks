// 

#include "../../math/SafeMath.hpp"
#include "../Crowdsale.hpp"
#include "../../ownership/Ownable.hpp"


/**
 * @title IndividuallyCappedCrowdsale
 * @dev Crowdsale with per-user caps.
 */
class IndividuallyCappedCrowdsale :public Crowdsale, Ownable {
  // using SafeMath for uint64_t;

  // mapping(account_name => uint64_t) public contributions;
  // mapping(account_name => uint64_t) public caps;
 struct balance
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(balances), balance> balances;

   struct balance
  {
    account_name name;
    uint64_t balance;

    uint64_t primary_key() const { return name; }
  };

  typedef eosio::multi_index<N(balances), balance> balances;
  /**
   * @dev Sets a specific user's maximum contribution.
   * @param _beneficiary Address to be capped
   * @param _cap Wei limit for individual contribution
   */
  void setUserCap(account_name _beneficiary, uint64_t _cap) 
  external onlyOwner 
  {
    caps[_beneficiary] = _cap;
  }

  /**
   * @dev Sets a group of users' maximum contribution.
   * @param _beneficiaries List of addresses to be capped
   * @param _cap Wei limit for individual contribution
   */
  void setGroupCap(
    account_name[] _beneficiaries,
    uint64_t _cap
  )
    // external
    // onlyOwner
  {
    for (uint64_t i = 0; i < _beneficiaries.length; i++) {
      caps[_beneficiaries[i]] = _cap;
    }
  }

  /**
   * @dev Returns the cap of a specific user.
   * @param _beneficiary Address whose cap is to be checked
   * @return Current cap for individual user
   */
  uint64_t getUserCap(account_name _beneficiary) 
  // public view returns (uint64_t) 
  {
    return caps[_beneficiary];
  }

  /**
   * @dev Returns the amount contributed so far by a sepecific user.
   * @param _beneficiary Address of contributor
   * @return User contribution so far
   */
  uint64_t getUserContribution(account_name _beneficiary)
    // public view returns (uint64_t)
  {
    return contributions[_beneficiary];
  }

  /**
   * @dev Extend parent behavior requiring purchase to respect the user's funding cap.
   * @param _beneficiary Token purchaser
   * @param _weiAmount Amount of wei contributed
   */
  void _preValidatePurchase(
    account_name _beneficiary,
    uint64_t _weiAmount
  )
    // internal
  {
    super._preValidatePurchase(_beneficiary, _weiAmount);
    eosio_assert(contributions[_beneficiary].add(_weiAmount) <= caps[_beneficiary]);
  }

  /**
   * @dev Extend parent behavior to update user contributions
   * @param _beneficiary Token purchaser
   * @param _weiAmount Amount of wei contributed
   */
  void _updatePurchasingState(
    account_name _beneficiary,
    uint64_t _weiAmount
  )
    // internal
  {
    super._updatePurchasingState(_beneficiary, _weiAmount);
    contributions[_beneficiary] = contributions[_beneficiary].add(_weiAmount);
  }

}
