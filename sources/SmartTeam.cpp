#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character* leader) : Team(leader) {
    }

    void SmartTeam::attack(Team* other)
    {
        if (leader->isAlive() == false)
            electNewLeader();

        Character* target = findTarget(other);

        for (Character* member : members)
        {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member))
            {
                if (cowboy->hasboolets())
				    cowboy->shoot(target);
                else
                    cowboy->reload();
            }
            else if (Ninja* ninja = dynamic_cast<Ninja*>(member))
            {
                if (ninja->distance(target) <= 1)
                    ninja->slash(target);
                else
                    ninja->move(target);
            }

            if (target->isAlive() == false)
            {
                target = findTarget(other);
                if (target == nullptr)
                    break;
            }
        }
    }
}