/**
 * Title: Tavern.cpp
 * Author: Jonathan Nazario
 * Date: 06/26/2026
 * Description: The Implementation of the Tavern class
 */
#include "Tavern.hpp"
#include <iostream>


Tavern::Tavern(){
    totalLevel_ = 0;
    creatureCount_ = 0;
}

/**
@param: A creature entering the tavern
@post: If the given creature is not already in the tavern, add the creature to
the tavern and update the level sum and the creature count
@return: Returns true if the creature was successfully added to the cavern,
false otherwise
*/
bool Tavern::enterTavern(Creature* newCreature){
    if(MagicalBag::contains(newCreature)){
        return false;  
    }
    MagicalBag::add(newCreature);
    totalLevel_ += newCreature -> getLevel();
    creatureCount_ ++;
    return true;
}

/**
@param: A creature exiting the tavern
@post: Removes the creature from the cavern, if they exist, and updates the
level sum and creature count accordingly.
@return: Returns true if the creature was successfully removed from the
cavern, false otherwise
*/
bool Tavern::exitTavern(Creature* newCreature){
    if (!MagicalBag::contains(newCreature)){
        return false;
    }
    MagicalBag::remove(newCreature);
    totalLevel_ -= newCreature ->getLevel();
    creatureCount_ --;
    return true;
}

/**
@return: Returns the combined level of all creatures in the tavern
*/
int Tavern::getLevelSum() const{
    return totalLevel_;
}

/**
@return: Returns the amount of creatures in the tavern
*/
int Tavern::getCreatureCount() const{
    return creatureCount_;
}

/**
@return: Returns the amount of creatures in the tavern that are hostile
*/
int Tavern::getHostileCount() const{
    int count = 0;
    for (int i = 0; i < item_count_; i++){
        if ( items_[i] -> isHostile()){
            count ++;
        }
    }
    return count;
}

/**
@post: Computes the percentage of hostile creatures in the tavern rounded
up to 2 decimal places
@return: Returns the percentage of all the hostile creatures in the tavern
*/
double Tavern::calculateHostilePercentage() const {
    if(getCreatureCount() == 0) return 0;
    double percentage = ( (double)getHostileCount()
    / getCreatureCount()) * 100;
    return percentage;
}

/**
@param: A string representing a creature category
@return: An integer tally of the number of creatures in the tavern of the
given category
Hint: If string parameter does not match a category, return 0
*/
int Tavern::tallyCategory(const std::string& category) const{
    int count = 0;
    for (int i = 0; i < item_count_; i++){
        if(items_[i]-> getCategory() == category){
            count++;
        }
    }
    return count;
}

/**
@param: A string representing a creature school
@return: An integer tally of the number of creatures in the tavern of the
given school
Hint: If string parameter does not match a school, return 0
*/
int Tavern::tallySchool(const std::string& school) const{
    int count = 0;
    for (int i = 0; i < item_count_; i++){
        if (items_[i]->getSchool() == school){
            count ++;
        }
    }
    return count;
}

/**
@param: An integer representing the level threshold of the creatures to be
removed from the tavern, with a default value of 0
@post: Removes all creatures from the tavern whose level is less than the
given level. If no level is given, remove no creatures. Ignore negative inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesBelowLevel(int level){
    if(level <= 0) return 0;
    int count = 0;
    for (int i = 0; i < item_count_; i++){
        if (items_[i]->getLevel() < level){
            exitTavern(items_[i]);
            i--;
            count ++;
        }
    }
    return count;
}

/**
@param: A string representing a creature category to be removed from the
tavern, with a default value of "ALL"
@post: Removes all creatures from the tavern whose category matches the
given category. If no category is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfCategory(const std::string& category){
    int count = 0;
    if(category == "ALL"){
        count = item_count_;
        MagicalBag::clear();
        return count;
    }

    if(category != "MAGICAL" && category != "UNDEAD" && category != "ANIMAL" && category != "HUMANOID" && category != "UNKNOWN"){
        return 0;
    }

    for (int i = 0; i < item_count_; i++){
        if ( items_[i]->getCategory() == category){
            exitTavern(items_[i]);
            i--;
            count ++;
        }
    }
    return count;
}

/**
@param: A string representing a creature school to be removed from the
tavern, with a default value of "ALL"
@post: Removes all creatures from the tavern whose school matches the
given school. If no school is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfSchool(const std::string& school){
    int count = 0;
    if(school == "ALL"){
        count = item_count_;
        MagicalBag::clear();
        return count;
    }

    if(school != "FIRE" && school != "ICE" && school != "STORM" && school != "LIFE" && school != "MYTH" && school != "DEATH" && school != "UNKNOWN"){
        return 0;
    }

    for (int i = 0; i < item_count_; i++){
        if ( items_[i]->getSchool() == school){
            exitTavern(items_[i]);
            i--;
            count ++;
        }
    }
    return count;
}

/**
@post: Outputs a report of the creatures current in the tavern in the form:
CATEGORY COUNT:
MAGICAL: [INTEGER]
UNDEAD: [INTEGER]
ANIMAL: [INTEGER]
HUMANOID: [INTEGER]
CATEGORY_UNKNOWN: [INTEGER]
SCHOOL COUNT:
FIRE: [INTEGER]
ICE: [INTEGER]
STORM: [INTEGER]
LIFE: [INTEGER]
MYTH: [INTEGER]
DEATH: [INTEGER]
SCHOOL_UNKNOWN: [INTEGER]
AVERAGE LEVEL: [INTEGER]
HOSTILE: [DOUBLE]
*/
void Tavern::tavernReport() const{
    std::cout << "CATEGORY COUNT:" << "\n";
    std::cout << "MAGICAL: " << tallyCategory("MAGICAL") << "\n";
    std::cout << "UNDEAD: " << tallyCategory("UNDEAD") << "\n";
    std::cout << "ANIMAL: " << tallyCategory("ANIMAL") << "\n";
    std::cout << "HUMANOID: " << tallyCategory("HUMANOID") << "\n";
    std::cout << "CATEGORY_UNKNOWN: " << tallyCategory("UNKNOWN") << "\n";
    std::cout << "SCHOOL COUNT:" << "\n";
    std::cout << "FIRE: " << tallySchool("FIRE") << "\n";
    std::cout << "ICE: " << tallySchool("ICE") << "\n";
    std::cout << "STORM: " << tallySchool("STORM") << "\n";
    std::cout << "LIFE: " << tallySchool("LIFE") << "\n";
    std::cout << "MYTH: " << tallySchool("MYTH") << "\n";
    std::cout << "DEATH: " << tallySchool("DEATH") << "\n";
    std::cout << "SCHOOL_UNKNOWN: " << tallySchool("UNKNOWN") << "\n";
    std::cout << "AVERAGE LEVEL: " << getLevelSum() / getCreatureCount() << "\n";
    std::cout << "HOSTILE: " << calculateHostilePercentage() << "\n";
}

/**
@post: For every creature in the tavern, display each creature's information
*/
void Tavern::displayCreatures() const{
    for(int i = 0; i < item_count_; i++){
        items_[i]->display();
    }
}