#pragma once

#include "Character.hpp"

namespace ariel
{
	class Ninja : public Character
	{
		protected:
			int move_speed;

		public:
			// Constructor:
			Ninja(string name, Point location, int hit_points, int move_speed);

			/*
			 * Moves torwards character 'other' up to distance 'move_speed'.
			 */
			void move(Character* other);

			/*
			 * If character 'other' is within a range of 1 unit the ninja will hit him for 40 hp.
			 */
			void slash(Character* other);

			/*
			 * Prints ninja's details in the following format: "N: name, hp, location".
             * If the ninja died the format will be the following: "N: (name), location".
			 */
			string print() const override;
	};

	class YoungNinja : public Ninja {
		public:
			YoungNinja(string name, Point location);
	};
	class TrainedNinja : public Ninja {
		public:
			TrainedNinja(string name, Point location);
	};
	class OldNinja : public Ninja {
		public:
			OldNinja(string name, Point location);
	};
}