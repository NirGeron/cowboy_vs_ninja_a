#include <iostream>
#include "Team.hpp"
#include <math.h>
#include <string>


using namespace ariel; 
using namespace std;


// Class Character
Character::Character(const std::string& name, const Point& location): _name(name), _location(location) {}
double Character::distance(const Character& c) const {return c.getLocation().distance(_location);}

// Class Cowboy
Cowboy::Cowboy(const std::string& name, const Point& location):Character(name,location) {}
    void Cowboy::shoot(Character* c) {}
std::string Cowboy::print() const {return getName();}

// Class Ninja
Ninja::Ninja(const std::string& name, const Point& location):Character(name, location) {}

void Ninja::move(Character* c) {
    cout << getName() << " go to" << c->getLocation().getX() << ", "
        << c ->getLocation().getY() << endl;
}
void Ninja::slash(Character* c) {std::cout << getName() << " cut " << c->getName() << std::endl;}


// Class Point

Point::Point(double x, double y) : x(x), y(y) {}
double Point::distance(const Point& p) const {return sqrt(pow(p.y - y, 2) + pow(p.x - x, 2));}
double Point::getX() const { return x; }
double Point::getY() const { return y; }

Point Point::moveTowards(const Point& source, const Point& target, double distance){
    Point p(0,0);
    return p;
    }

// Class OldNinja
OldNinja::OldNinja(const std::string& name, const Point& location): Ninja(name,location) {}

std::string OldNinja::print() const { return getName(); }
   
// Class YoungNinja    
YoungNinja::YoungNinja(const std::string& name, const Point& location)
    :Ninja(name,location) {}
std::string YoungNinja::print() const { return getName(); }

 // Class TrainedNinja   
TrainedNinja::TrainedNinja(const std::string& name, const Point& location): Ninja(name,location) {}

std::string TrainedNinja::print() const { return getName(); }

// Class Team
Team::Team(Character* leader) { members.push_back(leader); }
Team::~Team() {
    for (Character* c : members) {delete c;}
}
void Team::add(Character* c) { members.push_back(c); }

void Team::attack(Team* t) {}

int Team::stillAlive() const {return 0;}

void Team::print() const {}


// Class Team2
Team2::Team2(Character* leader):Team(leader) { members.push_back(leader); }

Team2::~Team2() {
    for (Character* c : members) {
            delete c;
        }
    }

    
// Class SmartTeam
SmartTeam::SmartTeam(Character* leader):Team(leader){ members.push_back(leader); }

SmartTeam::~SmartTeam() {
    for (Character* c : members) {
            delete c;
        }
    }