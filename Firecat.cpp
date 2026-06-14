#include "Firecat.hpp"
#include <iostream>

/**
Default constructor.
Default-initializes all private members.
Default Firecat category: ANIMAL
Default Firecat school: FIRE
Default Firecat flame color: ORANGE
Default Firecat flame intensity: 1
Booleans are default-initialized to False
*/
Firecat::Firecat() :  Creature(){
    setCategory(Creature::Category::ANIMAL);
    setSchool(Creature::School::FIRE);
    flameColor_ = ORANGE;
    flameIntensity_ = 1;
    arsonist_ = false;
}

/**
Parameterized constructor.
@param: The name of the Firecat (a string)
@param: The category of the Firecat (a Category enum) with a default value
ANIMAL
@param: The school of the Firecat (a School enum) with a default value
FIRE
@param: The health of the Firecat (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the Firecat (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the Firecat (a boolean) with default value of False
@param: The flame color of the Firecat (an FlameColor enum) with a
default value ORANGE
@param: The flame intensity of the Firecat (an integer) with default value 1
if not provided, or if the value provided is 0 or negative
@param: A flag indicating whether the Firecat is an arsonist, with default
value False
*/
Firecat::Firecat(const std::string& name, Category category, School school, int health, int level, bool isHostile, FlameColor flameColor, int flameIntensity, bool arsonist) : Creature(name, category, school, health, level, isHostile){
    flameColor_ = flameColor;
    if (flameIntensity <= 0){
        flameIntensity_ = 1;
    }else{
        flameIntensity_ = flameIntensity;
    }
    arsonist_ = arsonist;
};

/**
@param: The flame color of the Firecat (an enum)
@post: Sets the Firecat’s flame color to the value of the parameter
*/

void Firecat::setFlameColor(const FlameColor& flameColor){
    flameColor_ = flameColor;
}

/**
@return: The flame color of the Firecat (in string form)
*/
std::string Firecat::getFlameColor() const{
    switch (flameColor_){
        case RED : return "RED";
        case ORANGE : return "ORANGE";
        case BLUE : return "BLUE";
        case WHITE : return "WHITE";
        default : return "UNKNOWN";
    }
}

/**
@param: An integer that represents the Firecat’s flame intensity
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the flame intensity private member to the value of the parameter
@return: true if the flame intensity was set, false otherwise
*/
bool Firecat::setFlameIntensity(const int& flameIntensity){
    if (flameIntensity <=0 ){
        return false;
    }else{
        flameIntensity_ = flameIntensity;
        return true;
    }
}

/**
@return: The flame intensity of the Firecat
*/
int Firecat::getFlameItensity() const{
    return flameIntensity_;
}

/**
@param: A boolean value of whether or not the Firecat is an arsonist
@post: Sets the arsonist flag to the value of the parameter
*/
void Firecat::setArsonist(const bool& arsonist){
    arsonist_ = arsonist;
}

/**
@return: true if the Firecat is an arsonist, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getArsonist()
*/
bool Firecat::isArsonist() const{
    return arsonist_;
}

/**
@post: Displays Firecat data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Flame Color: [FLAME COLOR]\n
Flame Intensity: [FLAME INTENSITY]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Arsonist: [TRUE/FALSE]\n
Hostile: [TRUE/FALSE]”
*/
void Firecat::display() const{
    std::cout << getName() << "\n";
    std::cout << "Category: " << getCategory() << "\n";
    std::cout << "School: " << getSchool() << "\n";
    std::cout << "Flame Color: " << getFlameColor() << "\n";
    std::cout << "Flame Intensity: " << getFlameItensity() << "\n";
    std::cout << "Health: " << getHealth() << "\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Arsonist: " << (isArsonist() ? "TRUE" : "FALSE") << "\n";
    std::cout << "Hostile: " << (isHostile() ? "TRUE" : "FALSE") << std::endl;
}

/**
@post: Checks to see if two firecats are equal
@post: Checks names, flame color, and if they are both arsonists
*/
bool operator==(const Firecat& firecat1, const Firecat& firecat2){
    return firecat1.getName() == firecat2.getName() &&
    firecat1.flameColor_ == firecat2.flameColor_ &&
    firecat1.isArsonist() == firecat2.isArsonist();
}