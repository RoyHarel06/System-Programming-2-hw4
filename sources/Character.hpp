#pragma once

#include "Point.hpp"

#include <string>
#include <stdexcept>
using namespace std;

namespace ariel
{
	class Character
	{
		protected:
			string name;
			Point location;
			int hit_points;
			bool in_team;

		public:
            // Constructor:
			Character(string name, const Point& location, int hit_points);

			// Destructor:
			virtual ~Character();

			/*
			 * Returns true if the character is alive.
			 */
			bool isAlive() const;

			/*
			 * Returns the distance between this character and the other character.
			 */
			double distance(Character* other) const;

			/*
			 * Reduces hp of this character based on 'power'.
			 */
			void hit(int power);

			/*
			 * Returns character name.
			 */
			string getName() const;

			/*
			 * Returns character location.
			 */
			const Point& getLocation() const;

			/*
			 * Prints character's details in the following format: "name, hp, location".
             * If the character died the format will be the following: "(name), location".
			 */
			virtual string print() const = 0;

			/*
			 * Returns true if the character is in a team.
			 */
			bool isInTeam();

			/*
			 * Sets character as part of a team.
			 */
			void enterTeam();
	};
}