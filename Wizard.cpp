/**
 * Title: Wizard.cpp
 * Author: Jonathan Nazario
 * Date: 07/01/2026
 * Description: The Implementation of the wizard class
 */
#include "Wizard.hpp"
#include <iostream>
#include "Creature.hpp"

/**
Default constructor.
Default-initializes all private members.
Default Wizard Category: HUMANOID
Default Wizard School: Choose what you like
*/
Wizard::Wizard() : Creature(){
    setHealth(100);
    setSpeed(10);
    setCategory(Category::HUMANOID);
    setSchool(School::FIRE);
}

/**
Parameterized constructor.
@param: The name of the wizard (a string)
@param: The category of the wizard (a Category enum) with a default value HUMANOID
@param: The school of the wizard (a School enum) with a default value of whatever you like
@param: The health of the wizard (an integer) with default value 100 if not provided,
        or if the value provided is 0 or negative
@param: The level of the wizard (an integer) with default value 1 if not provided,
        or if the value provided is 0 or negative
@param: The hostility of the wizard (a boolean) with default value of False
@param: The speed of the wizard (an integer) with default value of 10 if not provided,
        or if the value provided is 0 or negative
*/
Wizard::Wizard(const std::string& name, Category category, School school, int level, bool tame, int speed, int health) : Creature(name, category, school, health, level, tame, speed){

}

/**
Offensive spell - attacks a target creature with magic
@param: A pointer to the creature being attacked
@post: Decreases the health of the creature being attacked by 20 and
displays a different message for the spell used based on wizard's school:
FIRE: Fire Cat
STORM: Thunder Snake
ICE: Frost Beetle
LIFE: Imp
MYTH: Blood Bat
DEATH: Dark Sprite
<Wizard Name> casts <School spell> on <Target Name>!
*/
void Wizard::attackSpell(Creature* target){
    target->setHealth(target->getHealth() - 20);
    if(getSchool() == "FIRE"){
        std::cout << getName() << " casts Fire Cat on " << target->getName() << "!\n";
    }else if(getSchool() == "STORM"){
        std::cout << getName() << " casts Thunder Snake on " << target->getName() << "!\n";
    }else if(getSchool() == "ICE"){
        std::cout << getName() << " casts Frost Beetle on " << target->getName() << "!\n";
    }else if(getSchool() == "LIFE"){
        std::cout << getName() << " casts Imp on " << target->getName() << "!\n";
    }else if(getSchool() == "MYTH"){
        std::cout << getName() << " casts Blood Bat on " << target->getName() << "!\n";
    }else if(getSchool() == "DEATH"){
        std::cout << getName() << " casts Dark Sprite on " << target->getName() << "!\n";
    }
}

/**
Defensive spell - heals the wizard
@post: Increases the wizard's health by 15 points and displays an action message
<Wizard Name> casts Fairy!
*/
void Wizard::healSpell(){
    setHealth(getHealth() + 15);
    std::cout << getName() << " casts Fairy!" << std::endl;
}