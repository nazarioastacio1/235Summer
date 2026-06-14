#ifndef BANSHEE_H_
#define BANSHEE_H_

#include "Creature.hpp"

class Banshee : public Creature{
    public:
    enum Aura {RED,BLUE,GRAY,GREEN};

    /**
     * Default constructor.
     * Default-initializes all private members.
     * Default Banshee category: UNDEAD
     * Default Banshee school: DEATH
     * Default Banshee aura: RED
     * Default Banshee scream volume: 1
     * Booleans are default-initialized to False
     */
    Banshee();

    /**
     * Parameterized constructor.
     * @param: The name of the Banshee (a string)
     * @param: The category of the Banshee (a Category enum) with a default value UNDEAD
     * @param: The school of the Banshee (a School enum) with a default value DEATH
     * @param: The health of the Banshee (an integer) with default value 1 if not
     *         provided, or if the value provided is 0 or negative
     * @param: The level of the Banshee (an integer) with default value 1 if not
     *         provided, or if the value provided is 0 or negative
     * @param: The hostility of the Banshee (a boolean) with default value of False
     * @param: The spectral aura of the Banshee (an Aura enum) with a default value RED
     * @param: The decibel level of the Banshee (an integer) with default value 1
     *         if not provided, or if the value provided is 0 or negative
     * @param: A flag indicating whether the Banshee can induce fear, with default value False
     */
    Banshee(const std::string&name, Creature::Category category, Creature::School school, int health, int level, bool isHostile, Aura spectralAura, int screamVolume, bool fearInducing);

    /**
     * @param: The aura of the Banshee (an enum)
     * @post: Sets the Banshee's aura to the value of the parameter
     */
    void setAura(const Aura& spectralAura);

    /**
     * @return: The aura of the Banshee (in string form)
     */
    std:: string getAura() const;

    /**
     * @param: An integer that represents the Banshee's decibel level
     * @pre: Parameter must be greater than 0, if not, do nothing
     * @post: Sets the scream volume private member to the value of the parameter
     * @return: true if the scream volume was set, false otherwise
     */
    bool setScreamVolume(const int& screanVolume);

    /**
     * @return: The scream volume of the Banshee
     */
    int getScreamVolume()const;

    /**
     * @param: A boolean value of whether or not the Banshee is fear inducing
     * @post: Sets the fear inducing flag to the value of the parameter
     */
    void setFearInducing(const bool& fearInducing);

    /**
     * @return: true if the Banshee is fear inducing, false otherwise
     * Note: This is still an accessor function and must follow the same
     * conventions as all accessor functions even if it not called getFearInducing()
     */
    bool isFearInducing()const;

    /**
     * @post: Displays Banshee data in the form:
     * "[NAME]\n
     * Category: [CATEGORY]\n
     * School: [SCHOOL]\n
     * Aura Color: [AURA]\n
     * Scream Level: [SCREAM LEVEL]\n
     * Health: [HEALTH]\n
     * Level: [LEVEL]\n
     * Fear Inducing: [TRUE/FALSE]\n
     * Hostile: [TRUE/FALSE]"
     */
    void display()const;

    /**
     * @post: Checks to see if two banshees are equal
     * @post: Checks names, aura color, and fear inducing qualities
     */
    friend bool operator==(const Banshee& banshee1, const Banshee& banshee2);
    

    private:

    Aura spectralAura_;
    int screamVolume_;
    bool fearInducing_;

};

#endif