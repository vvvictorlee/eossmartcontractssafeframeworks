#include <eosiolib/eosio.hpp>

#include "ballot.hpp"

//namespace eosio {

    // 投票发起人接口
    void ballot::addproposal(string proposal_name) // 初始化投票提案
    {
        require_auth(_self);
        
//        proposal_index proposals(_self, _self);
        auto it = proposals.find(eosio::string_to_name(proposal_name.c_str()));
        eosio_assert(it == proposals.end(), "proposal exist");
        
        proposals.emplace(_self, [&](auto &a) {
            a.name = proposal_name;
            a.voteCount = 0;
        });
    }
    void ballot::addvoter(account_name voter_name, uint64_t weight /* =1 */) // 初始化投票人
    {
        require_auth(_self);
        eosio_assert(weight > 0, "must positive weight");
        
//        voter_index voters(_self, _self);
        auto it = voters.find(voter_name);
        
        eosio_assert(it == voters.end(), "voter exist");
        voters.emplace(_self, [&](auto &a) {
            a.account = voter_name;
            a.weight = weight;
            a.voted = false;
            a.delegate_account = 0;
            a.proposal_name = "";
        });
    }
    // 普通选民接口
    void ballot::delegate(account_name voter, account_name delegate_to) // 委托投票（跟随投票）
    {
        require_auth(voter);
        
//        voter_index voters(_self, _self);
        auto vit = voters.find(voter);
        eosio_assert(vit->voted == false, "is voted");
        eosio_assert(vit != voters.end(), "voter not exist");
        auto it = voters.find(delegate_to);
        eosio_assert(it != voters.end(), "delegate_to not exist");
        
        while (it != voters.end() && it->delegate_account != 0 && it->delegate_account != voter)
            it = voters.find(it->delegate_account);
        
        eosio_assert(it != voters.end(), "delegate obj not exist");
        eosio_assert(it->account != voter, "not delegate self");
        
        if (it->voted)
        {
            vote(voter, it->proposal_name);
        }
        else
        {
            voters.modify(it, _self, [&](auto &a) {
                a.weight  = vit->weight;
            });
            voters.modify(vit, _self, [&](auto &a) {
                a.voted = true;
            });
        }
    }
    void ballot::vote(account_name voter, string proposal) // 投票给某个提议
    {
        require_auth(voter);
//        proposal_index proposals(_self, _self);
        auto it = proposals.find(eosio::string_to_name(proposal.c_str()));
        eosio_assert(it != proposals.end(), "proposal not exist");
        
//        voter_index voters(_self, _self);
        auto vit = voters.find(voter);
        eosio_assert(vit->voted == false, "is voted");
        eosio_assert(vit != voters.end(), "voter not exist");
        
        voters.modify(vit, _self, [&](auto &a) {
            a.voted = true;
            a.proposal_name = proposal;
        });
        
        proposals.modify(it, _self, [&](auto &a) {
            a.voteCount  = vit->weight;
        });
    }
    void ballot::winproposal(account_name self) // 返回投票数最多的提议
    {
//        proposal_index proposals(_self, _self);
        auto win = proposal();
        uint64_t max = 0;
        for (auto it : proposals)
        {
            if (it.voteCount > max)
            {
                max = it.voteCount;
                win = it;
            }
        }
        if (max > 0)
        {
            eosio::print("win proposal is: ", win.name.c_str(), "vote count", win.voteCount, "\n");
        }
        else
        {
            eosio::print("not vote", "\n");
        }
    }
    void ballot::allproposal(account_name self) // 返回全部提案投票状态
    {
//        proposal_index proposals(_self, _self);
        uint64_t idx = 0;
        for (auto it : proposals)
        {
            eosio::print(" proposal ", idx, ":", it.name.c_str(), ", vote count:", it.voteCount, "\n");
        }
    }
    
//} /// namespace eosio

EOSIO_ABI(ballot, (addproposal)(addvoter)(delegate)(vote)(winproposal)(allproposal))
