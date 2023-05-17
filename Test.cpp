#include "doctest.h"

#include "sources/Team.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
using namespace ariel;

TEST_CASE("Point constructor")
{
	Point p1(1, 3);

	CHECK(p1.getX() == 1);
	CHECK(p1.getY() == 3);
}

TEST_CASE("Point distance")
{
	Point p1(1, 1);
    Point p2(2, 1);

	CHECK(p1.distance(p2) == p2.distance(p1));
	CHECK(p1.distance(p2) == 1);
}

TEST_CASE("Point moveTowards")
{
	Point p1(1, 1);
    Point p2(3, 1);

	CHECK_NOTHROW(Point::moveTowards(p1, p2, 1));
    CHECK((Point::moveTowards(p1, p2, 1)).distance(p2) == 1);
}

TEST_CASE("Character distance")
{
    Cowboy cowboy1("bob", Point(0, 0));
    Cowboy cowboy2("bob", Point(1, 0));

    CHECK(cowboy1.distance(&cowboy2) == 1);
}

TEST_CASE("Character hit")
{
    Cowboy cowboy("bob", Point(0, 0));

    cowboy.hit(55);
    CHECK(cowboy.isAlive() == true);
    CHECK(cowboy.print() == "C: bob, 55, (0,0)");

    cowboy.hit(55);
    CHECK(cowboy.isAlive() == false);
    CHECK(cowboy.print() == "C: (bob), (0,0)");
}

TEST_CASE("Cowboy constructor")
{
	Cowboy cowboy("bob", Point(0, 0));

	CHECK(cowboy.getName() == "bob");

	CHECK(cowboy.getLocation().getX() == 0);
	CHECK(cowboy.getLocation().getY() == 0);

	CHECK(cowboy.isAlive() == true);
	CHECK(cowboy.print() == "C: bob, 110, (0,0)");
}

TEST_CASE("Cowboy reload")
{
	Cowboy cowboy1("alice", Point(0, 0));
    Cowboy cowboy2("bob", Point(0, 0));

    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    CHECK(cowboy2.print() == "C: bob, 50, (0,0)");

    cowboy1.shoot(&cowboy2);
    CHECK(cowboy2.print() == "C: bob, 50, (0,0)");

    cowboy1.reload();

    cowboy1.shoot(&cowboy2);
    CHECK(cowboy2.print() == "C: bob, 40, (0,0)");
}

TEST_CASE("Cowboy hasBullets")
{
	Cowboy cowboy1("alice", Point(0, 0));
    Cowboy cowboy2("bob", Point(0, 0));

    CHECK(cowboy1.hasBullets() = true);

    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);
    cowboy1.shoot(&cowboy2);

    CHECK(cowboy1.hasBullets() = false);

    cowboy1.reload();

    CHECK(cowboy1.hasBullets() = true);
}

TEST_CASE("Cowboy shoot")
{
	Cowboy cowboy1("alice", Point(0, 0));
    Cowboy cowboy2("bob", Point(0, 0));

    cowboy1.shoot(&cowboy2);
    CHECK(cowboy2.isAlive() == true);
    CHECK(cowboy2.print() == "C: bob, 100, (0,0)");

    for (int i = 0; i < 10; i++)
    {
        cowboy1.shoot(&cowboy2);
        cowboy1.reload();
    }
    CHECK(cowboy2.isAlive() == false);
}

TEST_CASE("Ninja constructor")
{
	YoungNinja ninja1("alice", Point(0, 0));
    TrainedNinja ninja2("bob", Point(0, 0));
    OldNinja ninja3("charlie", Point(0, 0));

	CHECK(ninja1.getName() == "alice");

	CHECK(ninja1.getLocation().getX() == 0);
	CHECK(ninja1.getLocation().getY() == 0);

	CHECK(ninja1.isAlive() == true);
	CHECK(ninja1.print() == "N: alice, 100, (0,0)");
    CHECK(ninja2.print() == "N: bob, 120, (0,0)");
    CHECK(ninja3.print() == "N: charlie, 150, (0,0)");
}

TEST_CASE("Ninja move")
{
	YoungNinja ninja1("alice", Point(0, 0));
    TrainedNinja ninja2("bob", Point(20, 0));
    OldNinja ninja3("charlie", Point(40, 0));

    CHECK_NOTHROW(ninja1.move(&ninja2));
    CHECK(ninja1.distance(&ninja2) == 6);

    ninja2.move(&ninja3);
    CHECK(ninja2.distance(&ninja3) == 8);
    
    ninja3.move(&ninja2);
    CHECK(ninja3.distance(&ninja2) == 0);
}

TEST_CASE("Ninja slash")
{
	YoungNinja ninja1("alice", Point(0, 0));
    TrainedNinja ninja2("bob", Point(0, 0));
    TrainedNinja ninja3("charlie", Point(2, 0));

    ninja1.slash(&ninja2);
    CHECK(ninja2.print() == "N: bob, 80, (0,0)");
    ninja1.slash(&ninja2);
    ninja1.slash(&ninja2);
    CHECK(ninja2.isAlive() == false);

    ninja1.slash(&ninja3);
    ninja1.slash(&ninja3);
    ninja1.slash(&ninja3);
    CHECK(ninja3.isAlive() == true);
}

TEST_CASE("Team constructor")
{
	YoungNinja ninja1("alice", Point(0, 0));

	Team team1(&ninja1);
    CHECK(team1.getMembers().size() == 1);
}

TEST_CASE("Team add")
{
	YoungNinja ninja1("alice", Point(0, 0));
    Cowboy cowboy1("bob", Point(0, 0));

	Team team1(&ninja1);

	team1.add(&cowboy1);
	CHECK(team1.getMembers().size() == 2);
}

TEST_CASE("Team stillAlive")
{
	YoungNinja ninja1("alice", Point(0, 0));
    Cowboy cowboy1("bob", Point(0, 0));

	Team team1(&ninja1);
	team1.add(&cowboy1);

	CHECK(team1.stillAlive() == 2);

    ninja1.slash(&cowboy1);
    ninja1.slash(&cowboy1);
    ninja1.slash(&cowboy1);

    CHECK(team1.stillAlive() == 1);
}

TEST_CASE("Team attack")
{
	YoungNinja ninja1("alice", Point(0, 0));
    Cowboy cowboy1("bob", Point(0, 0));

	Team team1(&ninja1);
	Team team2(&cowboy1);

    team1.attack(&team2);

	CHECK(cowboy1.print() == "C: bob, 70, (0,0)");
}

TEST_CASE("Team attack order")
{
	YoungNinja ninja1("alice", Point(0, 0));
    Cowboy cowboy1("bob", Point(0, 0));

	Team team1(&ninja1);
    team1.add(&cowboy1);

    YoungNinja ninja2("moshe", Point(0, 0));
    ninja1.slash(&ninja2);
    ninja1.slash(&ninja2); // left at 20 hp

	Team team2(&ninja2);

    YoungNinja ninja3("yotam", Point(1, 1));
    team2.add(&ninja3);

    team1.attack(&team2);

    CHECK(ninja2.print() == "N: (moshe), (0,0)");
	CHECK(ninja3.print() == "N: yotam, 100, (1,1)");
}

TEST_CASE("Team2 attack order")
{
	YoungNinja ninja1("alice", Point(0, 0));
    Cowboy cowboy1("bob", Point(0, 0));

	Team2 team1(&ninja1);
    team1.add(&cowboy1);

    YoungNinja ninja2("moshe", Point(0, 0));
    ninja1.slash(&ninja2);
    ninja1.slash(&ninja2); // left at 20 hp

	Team2 team2(&ninja2);

    YoungNinja ninja3("yotam", Point(1, 1));
    team2.add(&ninja3);

    team1.attack(&team2);

    CHECK(ninja2.print() == "N: (moshe), (0,0)");
	CHECK(ninja3.print() == "N: yotam, 90, (1,1)");
}

TEST_CASE("Team cowboy attack logic")
{
    Cowboy cowboy1("alice", Point(0, 0));
    Cowboy cowboy2("bob", Point(0, 0));

	Team team1(&cowboy1);
    Team team2(&cowboy2);

    for (int i = 0; i < 6; i++)
    {
        team1.attack(&team2); // shoot
    }
    CHECK(cowboy2.print() == "C: bob, 40, (0,0)");

    team1.attack(&team2); // reload
    CHECK(cowboy2.print() == "C: bob, 40, (0,0)");

    team1.attack(&team2); // shoot
    CHECK(cowboy2.print() == "C: bob, 30, (0,0)");
}

TEST_CASE("Team ninja attack logic")
{
    YoungNinja ninja1("alice", Point(0, 0));
    YoungNinja ninja2("bob", Point(14, 0));

	Team team1(&ninja1);
    Team team2(&ninja2);

    team1.attack(&team2); // move
    CHECK(ninja2.print() == "N: bob, 100, (14,0)");

    team1.attack(&team2); // slash
    CHECK(ninja2.print() == "N: bob, 60, (14,0)");
}