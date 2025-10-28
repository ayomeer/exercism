#include <stdexcept>
#include <iostream>
#include <map>

namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus{
    troll,
    guest,
    user,
    mod
};


// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove
};


// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus status_poster, AccountStatus status_viewer){
    bool display{true};
    
    if(status_poster == AccountStatus::troll){
        (status_viewer == AccountStatus::troll)? display=true : display=false;
    }
    return display;
}


// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus account_status){
    switch(account_status){
        case AccountStatus::guest:
            if(action==Action::read) return true;
            if(action==Action::write) return false;
            if(action==Action::remove) return false;
            break;
        case AccountStatus::troll:
        // no break: troll and user equal on action permissions
        case AccountStatus::user:
            if(action==Action::read) return true;
            if(action==Action::write) return true;
            if(action==Action::remove) return false;
            break;
        case AccountStatus::mod:
            if(action==Action::read) return true;
            if(action==Action::write) return true;
            if(action==Action::remove) return true;
            break;
    }
    throw std::runtime_error("Unexpected control behaviour: No switch case applies.");
    return false;

}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus p1_status, AccountStatus p2_status){
    
    // deny access to guest users
    if(p1_status == AccountStatus::guest || p2_status == AccountStatus::guest) return false;

    // match trolls to trolls and non-trolls to non-trolls
    bool p1_troll = (p1_status == AccountStatus::troll)? true : false;
    bool p2_troll = (p2_status == AccountStatus::troll)? true : false;

    if (p1_troll == p2_troll) return true;
    else return false;
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

std::map<AccountStatus, int> accStatus_to_priority{
    {AccountStatus::mod, 3},
    {AccountStatus::user, 2},
    {AccountStatus::guest, 1},
    {AccountStatus::troll, 0},
};

bool has_priority(AccountStatus p1_status, AccountStatus p2_status){
    return (accStatus_to_priority.at(p1_status) > accStatus_to_priority.at(p2_status))? 
        true : false;
}


}  // namespace hellmath
