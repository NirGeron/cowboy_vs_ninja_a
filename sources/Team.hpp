#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>
#include <iostream>
#include <string>
#include <sstream>


namespace ariel {
using namespace std;

 // Class Point
    class Point {
    private:
        double x;
        double y;
        
    public:
        Point(double x, double y);
        double getX() const;
        double getY() const;
        double distance(const Point& other) const;
        Point moveTowards(const Point& source, const Point& target, double distance);
    };


// Class Character

    class Character {
    protected:
        string _name;
        Point _location;
    public:
        Character(const std::string& name, const Point& location);
        ~Character() {};
        virtual double distance(const Character& c) const ;
        virtual const std::string& getName() const {return _name;}
        virtual const Point& getLocation() const {return _location;}
        virtual void hit(double damage) {};
        virtual bool isAlive() const {return true;} 
        virtual std::string print() const {return "err";}
   
    };


// Class Cowboy
    class Cowboy : public Character {
    private:
        int _stack=6;
        int _health=110;
        int _damage=10;
    
    public:
        
        Cowboy(const std::string& name, const Point& location);
        virtual std::string print() const override ;
        virtual void hit(double damage) override{_health-=damage;}
        virtual bool isAlive() const override {return (_health>=0);} 
        void shoot(Character* c);
        bool hasboolet(){return (_stack==0);}
        void reload(){this->_stack=6;}

    };

// Class Ninja
    class Ninja : public Character {
    protected:
        int _speed=8;
        int _health=150;
        int _damage=40;    
    public:
        virtual void slash(Character* c);
        virtual void move(Character* c);
        Ninja(const std::string& name, const Point& location);
    };

// Class OldNinja
    class OldNinja : public Ninja {
    public:
        OldNinja(const std::string& name, const Point& location);
        virtual std::string print() const override;
    };

// Class YoungNinja
    class YoungNinja : public Ninja {
    public:
        YoungNinja(const std::string& name, const Point& location);
        virtual std::string print() const override;
    };

 // Class TrainedNinja
    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const std::string& name, const Point& location);
         virtual std::string print() const override;
    };

// Class Team
    class Team {
    protected:
        std::vector<Character*> members;    
    public:
        Team(Character* leader);
        ~Team();
        virtual int stillAlive() const;
        virtual void print() const;
        void add(Character* c);
        virtual void attack(Team* t);

    };

 // Class Team2
    class Team2 : public Team{
        Team2(Character* leader);
        ~Team2();
        virtual void attack(Team* t) override{};
        virtual int stillAlive() const override{return 1;}
        virtual void print() const override{};
    };

 // Class SmartTeam
    class SmartTeam : Team{
        SmartTeam(Character* leader);
        ~SmartTeam();
        virtual void attack(Team* t) override{};
        virtual int stillAlive() const override{return 1;}
        virtual void print() const override{};
    };
}
#endif 