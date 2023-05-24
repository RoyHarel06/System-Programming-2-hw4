#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character* leader) : Team(leader) {
    }

    // Empty function taht will not change the order. Hence the order will be kept as the insertion order.
    void Team2::orderMembers()
    {
        return; 
    }
}