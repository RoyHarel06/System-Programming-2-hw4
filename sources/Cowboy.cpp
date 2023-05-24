#include "Cowboy.hpp"
#include <stdexcept>

namespace ariel
{
	Cowboy::Cowboy(string name, Point location)
		: Character(name, location, 110), bullet_count(6) {
	}

	void Cowboy::shoot(Character* other)
	{            
		if (bullet_count > 0) {
            other->hit(10);
            bullet_count--;
        }
	}

	bool Cowboy::hasBullets() const
	{
		if (bullet_count > 0)
            return true;
        else
            return false;
	}

	void Cowboy::reload()
	{
		bullet_count = 6;
	}

	string Cowboy::print() const
	{
		return "C: " + Character::print();
	}
}
