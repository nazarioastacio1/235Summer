/**
 * Title: Creature.cpp
 * Author: Jonathan Nazario
 * Date: 06/06/2026
 * Description: The Implementation of the Creature class
 */

#include "Creature.hpp"
#include <iostream>
#include <string>

/**
 * Default constructor.
 * @post: Default-initializes all private members.
 * Default creature name: "NAMELESS"
 * Default creature category: UNKNOWN
 * Default creature school: UNKNOWN
 * Default creature health: 1
 * Default creature level: 1
 * Booleans are default-initialized to False
 */
Creature::Creature(){
    name_ = "NAMELESS";
    category_ = Category::CATEGORY_UNKNOWN;
    school_ = School::SCHOOL_UNKNOWN;
    health_ = 1;
    level_ = 1;
    isHostile_ = false;
    speed_ = 1;
};

/**
 * Parameterized constructor.
 * @param name: The name of the creature (a string)
 * @param category: The category of the creature (a Category enum) with a default value UNKNOWN
 * @param school: The school of the creature (a School enum) with a default value UNKNOWN
 * @param health: The health of the creature (an integer) with default value 1 if not
 *                provided, or if the value provided is 0 or negative
 * @param level: The level of the creature (an integer) with default value 1 if not
 *               provided, or if the value provided is 0 or negative
 * @param tame: The hostility of the creature (a boolean) with default value of False
 */
Creature::Creature(const std::string& name, Category category, School school, int health, int level, bool tame, int speed){
    std::string upperName = name;
    for(int i = 0; i < upperName.length(); i++){
        upperName[i] = toupper(upperName[i]);
    }
    name_ = upperName;
    category_ = category;
    school_ = school;
    if (health <= 0 ){
        health_ = 1;
    }else{
        health_ = health;
    };
    if (level <= 0 ){
        level_ = 1;
    }else{
        level_ = level;
    };
    isHostile_ = tame;
    if (speed <= 0){
        speed_ = 1;
    }else{
        speed_ = speed;
    }
};

/**
 * @param name: The name of the creature (a string)
 * @post: Sets the Creature's name to the value of the parameter in UPPERCASE
 *        (convert any lowercase character to uppercase)
 * @post: Only alphabetical characters are allowed. If the input contains
 *        non-alphabetic characters, do nothing
 * @return: true if the name was set, false otherwise
 */
bool Creature::setName(const std::string& name){
    for (int i = 0; i < name.length(); i++){
        if (!isalpha(name[i])){
            return false;
        }
    }
    std::string newUpper = name;
    for (int i = 0; i < newUpper.length(); i++){
        newUpper[i] = toupper(newUpper[i]);
    }
    name_ = newUpper;
    return true;
};

/**
 * @return: The name of the Creature
 */
std::string Creature::getName()const{
    return name_;
};

/**
 * @param category: The category of the Creature (an enum)
 * @post: Sets the Creature's category to the value of the parameter
 */
void Creature::setCategory(const Category& category){
    category_ = category;
};

/**
 * @return: The category of the Creature (in string form)
 */
std::string Creature::getCategory() const{
    switch(category_){
        case CATEGORY_UNKNOWN: return "UNKNOWN";
        case MAGICAL: return "MAGICAL";
        case UNDEAD: return "UNDEAD";
        case ANIMAL: return "ANIMAL";
        case HUMANOID: return "HUMANOID";
        default: return "UNKNOWN";
    }
};

/**
 * @param school: The school of the Creature (an enum)
 * @post: Sets the Creature's school to the value of the parameter
 */
void Creature::setSchool(const School& school){
    school_ = school;
};

/**
 * @return: The school of the Creature (in string form)
 */
std::string Creature::getSchool()const{
    switch(school_){
        case SCHOOL_UNKNOWN: return "UNKNOWN";
        case FIRE: return "FIRE";
        case ICE: return "ICE";
        case STORM: return "STORM";
        case LIFE: return "LIFE";
        case MYTH: return "MYTH";
        case DEATH: return "DEATH";
        default: return "UNKNOWN";
    }
};

/**
 * @param health: An integer that represents the creature's health
 * @pre: Parameter must be greater than 0, if not, do nothing
 * @post: Sets the health private member to the value of the parameter
 * @return: true if the health was set, false otherwise
 */
bool Creature::setHealth(const int& health){
    if (health <= 0){
        return false;
    }else{
        health_ = health;
        return true;
    }
};

/**
 * @return: The health of the Creature
 */
int Creature::getHealth() const{
    return health_;
};

/**
 * @param level: An integer that represents the creature's level
 * @pre: Parameter must be greater than 0, if not, do nothing
 * @post: Sets the level private member to the value of the parameter
 * @return: true if the level was set, false otherwise
 */
bool Creature::setLevel(const int& level){
    if (level <= 0){
        return false;
    }else{
        level_ = level;
        return true;
    }
};

/**
 * @return: The level of the Creature
 */
int Creature::getLevel()const{
    return level_;
};

/**
@param: The speed of the creature
@post: Sets the speed to the given value if greater than 0, if not, do nothing
@return: true if speed was set, false otherwise
*/
bool Creature::setSpeed(int speed){
    if (speed <=0){
        return false;
    }else{
        speed_ = speed;
        return true;
    }
}

/**
@return: The speed of the creature
*/
int Creature::getSpeed() const{
    return speed_;
}

/**
 * @param isHostile: A boolean value of whether or not the Creature is hostile
 * @post: Sets the isHostile flag to the value of the parameter
 */
void Creature::setHostility(const bool& isHostile){
    isHostile_ = isHostile;
};

/**
 * @return: true if the Creature is hostile, false otherwise
 */
bool Creature::isHostile() const{
    return isHostile_;
};

/**
 * @post: Displays Creature data in the form:
 * "[NAME]\n
 * Category: [CATEGORY]\n
 * School: [SCHOOL]\n
 * Health: [HEALTH]\n
 * Level: [LEVEL]\n
 * Hostile: [TRUE/FALSE]"
 */
void Creature::display() const{
    std::cout << name_ << "\n";
    std::cout <<"Category: " << getCategory() << "\n";
    std::cout <<"School: " << getSchool() << "\n"; 
    std::cout <<"Health: " << health_ << "\n";
    std::cout <<"Level: " << level_ << "\n";
    std::cout <<"Hostile: " << (isHostile_? "TRUE" : "FALSE") << "\n"; 
    std::cout << "Speed: " << getSpeed() << std::endl;  
};
