/**
 * Title: Banshee.cpp
 * Author: Jonathan Nazario
 * Date: 06/16/2026
 * Description: The Implementation of the Banshee class
 */
#include "Banshee.hpp"
#include <iostream>

/**
Default constructor.
Default-initializes all private members.
Default Banshee category: UNDEAD
Default Banshee school: DEATH
Default Banshee aura: RED
Default Banshee scream volume: 1
Booleans are default-initialized to False
*/
Banshee::Banshee() : Creature() {
    setCategory(Creature::Category::UNDEAD);
    setSchool(Creature::School::DEATH);
    spectralAura_ = RED;
    screamVolume_ = 1;
    fearInducing_ = false;
};

/**
Parameterized constructor.
@param: The name of the Banshee (a string)
@param: The category of the Banshee (a Category enum) with a default
value UNDEAD
@param: The school of the Banshee (a School enum) with a default value
DEATH
@param: The health of the Banshee (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the Banshee (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the Banshee (a boolean) with default value of
False
@param: The spectral aura of the Banshee (an Aura enum) with a default
value RED
@param: The decibel level of the Banshee (an integer) with default value 1
if not provided, or if the value provided is 0 or negative
@param: A flag indicating whether the Banshee can induce fear, with
default value False
*/
Banshee::Banshee(const std::string& name, Creature::Category category, Creature::School school, int health, int level, bool isHostile, Aura spectralAura, int screamVolume, bool fearInducing) : Creature(name, category, school, health, level, isHostile){
       spectralAura_ = spectralAura;
       if (screamVolume <=0){
        screamVolume_ = 1;
       }else{
        screamVolume_ = screamVolume;
       }
       fearInducing_ = fearInducing; 

}

/**
@param: The aura of the Banshee (an enum)
@post: Sets the Banshee’s aura to the value of the parameter
*/
void Banshee::setAura(const Aura& spectralAura){
    spectralAura_ = spectralAura;
}

/**
@return: The aura of the Banshee (in string form)
*/
std::string Banshee::getAura() const {
    switch(spectralAura_){
        case RED : return "RED";
        case BLUE : return "BLUE";
        case GRAY : return "GRAY";
        case GREEN : return "GREEN";
        default : return "UNKNOWN"; 
    }
}

/**
@param: An integer that represents the Banshee’s decibel level
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the scream volume private member to the value of the parameter
@return: true if the scream volume was set, false otherwise
*/
bool Banshee::setScreamVolume(const int& screamVolume){
    if (screamVolume <= 0){
        return false;
    }else{
        screamVolume_ = screamVolume;
        return true;
    }

}

/**
@return: The scream volume of the Banshee
*/
int Banshee::getScreamVolume() const{
    return screamVolume_;
}

/**
@param: A boolean value of whether or not the Banshee is fear inducing
@post: Sets the fear inducing flag to the value of the parameter
*/

void Banshee::setFearInducing(const bool& fearInducing){
    fearInducing_ = fearInducing;
}

/**
@return: true if the Banshee is fear inducing, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getFearInducing()
*/
bool Banshee::isFearInducing() const{
    return fearInducing_;

}

/**
@post: Displays Banshee data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Aura Color: [AURA]\n
Scream Level: [SCREAM LEVEL]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Fear Inducing: [TRUE/FALSE]\n
Hostile: [TRUE/FALSE]”
*/
void Banshee::display() const {
    std::cout << getName() << "\n";
    std::cout << "Category: " << getCategory() << "\n";
    std::cout << "School: " << getSchool() << "\n";
    std::cout << "Aura Color: " << getAura() << "\n";
    std::cout << "Scream Level: " << screamVolume_ << "\n";
    std::cout << "Health: " << getHealth() << "\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Fear Inducing: " << (fearInducing_ ? "TRUE" : "FALSE") << "\n";
    std::cout << "Hostile: " << (isHostile() ? "TRUE" : "FALSE") << "\n";
}

/**
@post: Checks to see if two banshees are equal
@post: Checks names, aura color, and fear inducing qualities
*/
bool operator==(const Banshee& banshee1, const Banshee& banshee2){
    return banshee1.getName() == banshee2.getName() &&
           banshee1.spectralAura_ == banshee2.spectralAura_ &&
           banshee1.fearInducing_ == banshee2.fearInducing_;
}
