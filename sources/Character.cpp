#include "Character.hpp"

namespace ariel
{
	Character::Character(string name, Point& location, int hit_points)
		: name(name), location(location), hit_points(hit_points) {
	}

	bool Character::isAlive() const
	{
		if (hit_points > 0)
            return true;
        else
            return false;
	}

	double Character::distance(Character* other) const
	{
		return location.distance(other->getLocation());
	}

	void Character::hit(int power)
	{
		hit_points -= power;
	}

	string Character::getName() const
	{
		return name;
	}

	const Point& Character::getLocation() const
	{
		return location;
	}

	string Character::print() const
	{
		if (hit_points > 0)
            return name + ", " + to_string(hit_points) + ", " + location.print();
        else
            return "(" + name + "), " + location.print();
	}
}