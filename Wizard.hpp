/**
 * Title: Wizard.hpp
 * Author: Jonathan Nazario
 * Date: 07/01/2026
 * Description: The Declaration of the Wizard class
 */
#ifndef WIZARD_H_
#define WIZARD_H_

#include "Creature.hpp"

class Wizard : public Creature{
    public: 

    /**
    Default constructor.
    Default-initializes all private members.
    Default Wizard Category: HUMANOID
    Default Wizard School: Choose what you like
    */
    Wizard();

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
    Wizard(const std::string& name, Category category = Category::HUMANOID, School school = School::FIRE, int level = 1, bool tame = false, int speed = 10, int health = 100);

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
    void attackSpell(Creature* target);

    /**
    Defensive spell - heals the wizard
    @post: Increases the wizard's health by 15 points and displays an action message
    <Wizard Name> casts Fairy!
    */
    void healSpell();
};
#endif