#include "Character.hpp"

namespace ariel
{
	Character::Character(string name, const Point& location, int hit_points)
		: name(name), location(location), hit_points(hit_points), in_team(false) {
	}

	Character::~Character() {
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
		if (power < 0)
			throw invalid_argument("Power cant be negative.");

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

	bool Character::isInTeam() {
		return in_team;
	}

	void Character::enterTeam() {
		in_team = true;
	}

	int Character::getHP() {
		return hit_points;
	}
}