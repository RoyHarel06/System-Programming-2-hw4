#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
	{
		private:
			Character* findLowestHP(vector<Character*> characters);
			Character* findTarget(Team* other) override;
			
		public:
			SmartTeam(Character* leader);

			/*
			 * Attack team 'other'. Using a smarter attack algorithm.
			 */
			void attack(Team* other) override;
	};
}