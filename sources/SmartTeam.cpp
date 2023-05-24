#include "SmartTeam.hpp"
#include <limits>

namespace ariel
{
    SmartTeam::SmartTeam(Character* leader) : Team(leader) {
    }

    Character* SmartTeam::findLowestHP(vector<Character*> characters) {
        double min_hp = numeric_limits<double>::max();
        Character* lowest_character = nullptr;

        for (Character* character : characters)
        {
            if (character->isAlive())
            {
                if (character->getHP() < min_hp)
                {
                    min_hp = character->getHP();
                    lowest_character = character;
                }
            }
        }

        return lowest_character;
    }

    Character* SmartTeam::findTarget(Team* other)
    {
        vector<Character*> enemies = other->getMembers();
        return findClosestToLeader(enemies);
    }

    void SmartTeam::attack(Team* other)
	{
        if (other == nullptr)
			throw invalid_argument("Other team in null.");
        else if (other->stillAlive() <= 0)
            throw runtime_error("Other team is dead.");

        if (leader->isAlive() == false)
            electNewLeader();

        Character* target = findTarget(other);

        for (Character* member : members)
        {
            if (member->isAlive() == false)
                continue;

            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            if (cowboy != nullptr)
            {
                if (cowboy->hasboolets())
				    cowboy->shoot(target);
                else
                    cowboy->reload();
            }

            Ninja* ninja = dynamic_cast<Ninja*>(member);
            if (ninja != nullptr)
            {
                if (ninja->distance(target) <= 1)
                    ninja->slash(target);
                else
                    ninja->move(target);
            }

            if (target->isAlive() == false)
            {
                if (other->stillAlive() <= 0)
                    break;
                target = findTarget(other);
            }
        }
	}
}