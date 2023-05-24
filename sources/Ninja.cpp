#include "Ninja.hpp"

namespace ariel
{
	Ninja::Ninja(string name, Point location, int hit_points, int move_speed)
		: Character(name, location, hit_points), move_speed(move_speed) {
	}

	void Ninja::move(Character* other)
	{
		location =  Point::moveTowards(getLocation(), other->getLocation(), move_speed);
	}

	void Ninja::slash(Character* other)
	{
		if (this->distance(other) <= 1) {
            other->hit(40);
        }
	}

	string Ninja::print() const
	{
		return "N: " + Character::print();
	}

	YoungNinja::YoungNinja(string name, Point location)
		: Ninja(name, location, 100, 14) {
	}

	TrainedNinja::TrainedNinja(string name, Point location)
		: Ninja(name, location, 120, 12) {
	}

	OldNinja::OldNinja(string name, Point location)
		: Ninja(name, location, 150, 8) {
	}
}