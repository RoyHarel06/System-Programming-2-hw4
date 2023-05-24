#include "Team.hpp"
#include <iostream>

namespace ariel
{
    void Team::orderMembers()
    {
        vector<Character*> ordered_members;
        
        for (Character* member : members)
        {
            if (dynamic_cast<Cowboy*>(member))
                ordered_members.push_back(member);
        }
        
        for (Character* member : members)
        {
            if (dynamic_cast<Ninja*>(member))
                ordered_members.push_back(member);
        }
        
        members = ordered_members;
    }

	Team::Team(Character* leader)
		: leader(leader)
	{
		members.push_back(leader);
	}

	Team::~Team()
    {
        for (Character* member : members)
        {
            delete member;
        }

        members.clear();
    }

	void Team::add(Character* new_member)
	{
        for (Character* member : members)
        {
            if (member == new_member)
                return;
        }

		members.push_back(new_member);
        orderMembers();
	}

	vector<Character*> Team::getMembers() const
	{
		return members;
	}

	int Team::stillAlive() const
	{
        int living_members = 0;

		for (Character* member : members)
        {
            if (member->isAlive() == true)
                living_members++;
        }

        return living_members;
	}

	void Team::print() const
	{
        cout << "Leader: " << leader->getName() << "\n";

		for (Character* member : members)
        {
            cout << member->print() << "\n";
        }
	}

    Character* Team::findClosestToLeader(vector<Character*> characters) {
        double min_distance = std::numeric_limits<double>::max();
        Character* closest_character = nullptr;

        for (Character* character : characters)
        {
            if (character->isAlive())
            {
                double distance = leader->distance(character);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    closest_character = character;
                }
            }
        }

        return closest_character;
    }

    void Team::electNewLeader()
    {
        if (leader->isAlive())
            return;

        leader = findClosestToLeader(members);
    }

    Character* Team::findTarget(Team* other)
    {
        vector<Character*> enemies = other->getMembers();
        return findClosestToLeader(enemies);
    }

    void Team::attack(Team* other)
	{
        if (leader->isAlive() == false)
            electNewLeader();

        Character* target = findTarget(other);

        for (Character* member : members)
        {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member))
            {
                if (cowboy->hasBullets())
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

    // TEAM2---------------------------------------------------------------------

    Team2::Team2(Character* leader) : Team(leader) {
    }

    // Empty function taht will not change the order. Hence the order will be kept as the insertion order.
    void Team2::orderMembers()
    {
        return; 
    }

    // MART TEAM-------------------------------------------------------------------

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
                if (cowboy->hasBullets())
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
