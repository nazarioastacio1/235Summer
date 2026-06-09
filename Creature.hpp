/**
 * Title: Creature.hpp
 * Author: Jonathan Nazario 
 * Date: 06/05/2026
 * Description: The Declaration of the Creature class
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <string>


class Creature {
    public:

    enum Category {CATEGORY_UNKNOWN, MAGICAL, UNDEAD,ANIMAL,HUMANOID};
    enum School {SCHOOL_UNKNOWN, FIRE, ICE,STORM,LIFE,MYTH,DEATH};

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
    Creature();

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
    Creature(const std::string& name, Category category = Category::CATEGORY_UNKNOWN , School school = School::SCHOOL_UNKNOWN, int health = 1, int level = 1, bool tame = false);

    /**
     * @param name: The name of the creature (a string)
     * @post: Sets the Creature's name to the value of the parameter in UPPERCASE
     *        (convert any lowercase character to uppercase)
     * @post: Only alphabetical characters are allowed. If the input contains
     *        non-alphabetic characters, do nothing
     * @return: true if the name was set, false otherwise
     */
    bool setName(const std::string& name);

    /**
     * @return: The name of the Creature
     */
    std::string getName()const;

    /**
     * @param category: The category of the Creature (an enum)
     * @post: Sets the Creature's category to the value of the parameter
     */
    void setCategory(const Category& category);

    /**
     * @return: The category of the Creature (in string form)
     */
    std::string getCategory()const;

    /**
     * @param school: The school of the Creature (an enum)
     * @post: Sets the Creature's school to the value of the parameter
     */
    void setSchool(const School& school);

    /**
     * @return: The school of the Creature (in string form)
     */
    std::string getSchool() const;

    /**
     * @param health: An integer that represents the creature's health
     * @pre: Parameter must be greater than 0, if not, do nothing
     * @post: Sets the health private member to the value of the parameter
     * @return: true if the health was set, false otherwise
     */
    bool setHealth(const int& health);

    /**
     * @return: The health of the Creature
     */
    int getHealth() const;

    /**
     * @param level: An integer that represents the creature's level
     * @pre: Parameter must be greater than 0, if not, do nothing
     * @post: Sets the level private member to the value of the parameter
     * @return: true if the level was set, false otherwise
     */
    bool setLevel(const int& level);

    /**
     * @return: The level of the Creature
     */
    int getLevel() const;

    /**
     * @param isHostile: A boolean value of whether or not the Creature is hostile
     * @post: Sets the isHostile flag to the value of the parameter
     */
    void setHostility( const bool& isHostile);

    /**
     * @return: true if the Creature is hostile, false otherwise
     */
    bool isHostile() const;

    /**
     * @post: Displays Creature data in the form:
     * "[NAME]\n
     * Category: [CATEGORY]\n
     * School: [SCHOOL]\n
     * Health: [HEALTH]\n
     * Level: [LEVEL]\n
     * Hostile: [TRUE/FALSE]"
     */
    void display() const;

    private:
    std::string name_;
    Category category_;
    School school_;
    int health_;
    int level_;
    bool isHostile_;
};

#endif
