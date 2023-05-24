#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
	{
		public:
			SmartTeam(Character* leader);

			/*
			 * Attack team 'other'. Using a smarter attack algorithm.
			 */
			void attack(Team* other) override;
	};
}