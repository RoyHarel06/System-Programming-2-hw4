#include "Ninja.hpp"

namespace ariel
{
	Ninja::Ninja(string name, Point location, int hit_points, int move_speed)
		: Character(name, location, hit_points), move_speed(move_speed) {
	}

	void Ninja::move(Character* other)
	{
		if (isAlive() == false)
			throw runtime_error("A dead ninja cant move.");

		location =  Point::moveTowards(getLocation(), other->getLocation(), move_speed);
	}

	void Ninja::slash(Character* other)
	{
		if (other == nullptr)
			throw invalid_argument("Other character is null.");
		else if (other == this)
			throw runtime_error("Character cant attack itself.");
		else if (isAlive() == false)
			throw runtime_error("A dead character cant attack.");
		else if (other->isAlive() == false)
			throw runtime_error("Cant attack a dead character.");

		if (this->distance(other) <= 1) {
            other->hit(40);
        }
	}

	string Ninja::print() const
	{
		return "N: " + Character::print();
	}
}