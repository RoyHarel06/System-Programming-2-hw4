#pragma once

#include "Character.hpp"

namespace ariel
{
	class Cowboy : public Character
	{
		private:
			int bullet_count;

		public:
			// Constructor:
			Cowboy(string name, Point location);

			/*
			 * Shoots character 'other' for 10 hp using 1 bullet.
             * If the cowboy is dead or out of bullets nothing will happend.
			 */
			void shoot(Character *other);

			/*
			 * Returns true if the cowboy has bullets left.
			 */
			bool hasBullets() const;

			/*
			 * Reloads the cowboy's gun to 6 bullets.
			 */
			void reload();

			/*
			 * Prints cowboy's details in the following format: "C: name, hp, location".
             * If the cowboy died the format will be the following: "C: (name), location".
			 */
			string print() const override;
	};
}