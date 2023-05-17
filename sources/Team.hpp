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

		public:
			// Constructor:
			Team(Character* leader);

            // Destructor:
			virtual ~Team();

			/*
			 * Adds 'member' to the team.
			 */
			void add(Character* member);

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
		public:
			Team2(Character* leader);

			/*
			 * Attack team 'other'. Based on recency in team.
			 */
			void attack(Team* other) override;

			/*
			 * Prints the team members details. Prints based on recency in team.
			 */
			void print() const override;
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