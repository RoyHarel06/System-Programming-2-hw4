#include "Cowboy.hpp"

namespace ariel
{
	Cowboy::Cowboy(string name, Point location)
		: Character(name, location, 110), bullet_count(6) {
	}

	void Cowboy::shoot(Character* other)
	{            
		if (other == nullptr)
			throw invalid_argument("Other character is null.");
		else if (other == this)
			throw runtime_error("Character cant attack itself.");
		else if (isAlive() == false)
			throw runtime_error("A dead character cant attack.");
		else if (other->isAlive() == false)
			throw runtime_error("Cant attack a dead character.");
			
		if (bullet_count > 0) {
            other->hit(10);
            bullet_count--;
        }
	}

	bool Cowboy::hasboolets() const
	{
		if (bullet_count > 0)
            return true;
        else
            return false;
	}

	void Cowboy::reload()
	{
		if (isAlive() == false)
			throw runtime_error("A dead cowboy cant reload.");

		bullet_count = 6;
	}

	string Cowboy::print() const
	{
		return "C: " + Character::print();
	}
}
