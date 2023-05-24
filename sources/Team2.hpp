#pragma once

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
	{
		protected:
			void orderMembers() override;

		public:
			Team2(Character* leader);
	};
}