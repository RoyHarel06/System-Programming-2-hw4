#include "Team.hpp"
#include <iostream>
#include <limits>

namespace ariel
{
    void Team::orderMembers()
    {
        vector<Character*> ordered_members;
        
        for (Character* member : members)
        {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            if (cowboy != nullptr)
                ordered_members.push_back(cowboy);
        }
        
        for (Character* member : members)
        {
            Ninja* ninja = dynamic_cast<Ninja*>(member);
            if (ninja != nullptr)
                ordered_members.push_back(ninja);
        }
        
        members = ordered_members;
    }

	Team::Team(Character* leader)
		: leader(leader)
	{
		add(leader);
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
        if (members.size() == 10)
		    throw runtime_error("Team can only have 10 members.");

        if (new_member->isInTeam())
            throw runtime_error("Character already in a team.");

        for (Character* member : members)
        {
            if (member == new_member)
                return;
        }

        new_member->enterTeam();
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
            if (member->isAlive())
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
        double min_distance = numeric_limits<double>::max();
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
