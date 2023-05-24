#pragma once

#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"

namespace ariel
{
	class Team
	{
		protected:
			Character* leader;
			vector<Character*> members;

			virtual void orderMembers();

			Character* findClosestToLeader(vector<Character*> characters);
			void electNewLeader();
			Character* findTarget(Team* other);

		public:
			// Constructor:
			Team(Character* leader);

            // Destructor:
			virtual ~Team();

			/*
			 * Adds 'member' to the team.
			 */
			void add(Character* new_member);

            /*
             * Returns 'members' list.
             */
            vector<Character*> getMembers() const;

			/*
			 * Attack team 'other'. Cowboys first then Ninjas.
			 */
			virtual void attack(Team* other);

			/*
			 * Returns the number of living members.
			 */
			int stillAlive() const;

			/*
			 * Prints the team members details. Prints Cowboys first and then Ninjas.
			 */
			virtual void print() const;
	};

    class Team2 : public Team
	{
		protected:
			void orderMembers() override;

		public:
			Team2(Character* leader);
	};
	class SmartTeam : public Team
	{
		public:
			SmartTeam(Character* leader);

			/*
			 * Attack team 'other'. Using a 'smarter' attack algorithm.
			 */
			void attack(Team* other) override;
	};
}