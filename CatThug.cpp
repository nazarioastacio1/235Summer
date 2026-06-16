#include "CatThug.hpp"
#include <vector>
#include <iostream>

/**
Default constructor.
Default-initializes all private members.
Default Cat Thug category: HUMANOID
Default Cat Thug school: MYTH
Default Cat Thug weapons: {}
Default Cat Thug notoriety: ROOKIE
Booleans are default-initialized to False
*/
CatThug::CatThug(){
    setCategory(Creature::Category::HUMANOID);
    setSchool(Creature::School::MYTH);
    weapons_ = {};
    notorietyLevel_ = ROOKIE;
    isWanted_ = false;
}

/**
Parameterized constructor.
@param: The name of the Cat Thug (a string)
@param: The category of the Cat Thug (a Category enum) with a default
value HUMANOID
@param: The school of the Cat Thug (a School enum) with a default value
MYTH
@param: The health of the Cat Thug (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the Cat Thug (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the Cat Thug (a boolean) with default value of
False
@param: The weapons of the Cat Thug (a vector of Weapons) with a default
value {}
@param: The notoriety of the Cat Thug (a Notoriety enum) with default
value ROOKIE
@param: A flag indicating whether the Cat Thug is wanted, with default
value False
*/
CatThug::CatThug(const std::string& name, Category category, School school, int health, int level, bool isHostile, std::vector<Weapon> weapons, Notoriety notoriety, bool isWanted) : Creature(name, category, school, health, level, isHostile){
    weapons_ = weapons;
    notorietyLevel_ = notoriety;
    isWanted_ = isWanted;
}

/**
@param: The weapons of a Cat Thug
@post: Sets the Cat Thug’s weapons to the value of the parameter
*/
void CatThug::setWeapons(const std::vector<Weapon>& weapons){
    weapons_ = weapons;
}

/**
@return: The weapons (a vector of Weapon structs)
*/
std::vector<CatThug::Weapon> CatThug::getWeapons() const{
    return weapons_;
}

/**
@param: A weapon to be added to the vector
@post: Adds the weapon to the vector only if the weapon does not exist in
the vector
@post: if weapon exists, update the damage of the weapon in the vector with
the higher damage number
@return: true if weapon was added, false otherwise
Hint: bat and BAT are the same weapon
*/
bool CatThug::addWeapon(const Weapon& weapon){
    std::string newName;
    for (int i = 0; i < weapon.name.length(); i++){
        newName += toupper(weapon.name[i]);
    }
    for (int j = 0; j < weapons_.size(); j++){
        std::string existingName;
        for (int k = 0; k < weapons_[j].name.length(); k++){
            existingName += toupper(weapons_[j].name[k]);
        }
        if (existingName == newName){
            if (weapons_[j].damage < weapon.damage){
                weapons_[j].damage = weapon.damage;
            }
            return false;
        }

    }
    weapons_.push_back(weapon);
    return true;
}

/**
@param: A weapon to be removed from the vector
@post: Removes the weapon from the vector only if the weapon exists
@return: true if weapon was removed, false otherwise
Hint: bat and BAT are the same weapon\
*/
bool CatThug::removeWeapon(const Weapon& weapon){
    std::string removed;
    for (int i = 0; i < weapon.name.length(); i++){
        removed += toupper(weapon.name[i]);
    }
    for (int j = 0; j < weapons_.size(); j++){
        std::string existingWeapon;
        for (int k = 0; k < weapons_[j].name.length(); k++){
            existingWeapon += toupper(weapons_[j].name[k]);
        }
        if (removed == existingWeapon){
            weapons_.erase(weapons_.begin() + j);
            return true;
        }
    }
    return false;
}

/**
@param: The notoriety of the Cat Thug (an enum)
@post: Sets the Cat Thug’s notoriety to the value of the parameter
*/
void CatThug::setNotoriety(const Notoriety& notoriety){
    notorietyLevel_ = notoriety;
}

/**
@return: The notoriety of the Cat Thug (in string form)
*/
std::string CatThug::getNotoriety() const{
    switch(notorietyLevel_){
        case ROOKIE : return "ROOKIE";
        case THIEF : return "THIEF";
        case ENFORCER : return "ENFORCER";
        case MOB_BOSS : return "MOB_BOSS";
        default : return "UNKNOWN";
    }
}

/**
@param: A boolean value of whether or not the Cat Thug is wanted by the
authorities
@post: Sets the is wanted flag to the value of the parameter
*/
void CatThug::setIsWanted(const bool& isWanted){
    isWanted_ = isWanted;
}

/**
@return: true if the Cat Thug is wanted, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getIsWanted()
*/
bool CatThug::isWanted() const{
    return isWanted_;
}

/**
@post: Displays Cat Thug data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Weapons: [WEAPON NAME]: [DAMAGE], [RANGED/NOT RANGED]\n
Notoriety: [NOTORIETY]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Is Wanted: [TRUE/FALSE]\n
Hostile: [TRUE/FALSE]”
*/
void CatThug::display() const{
    std::cout << getName() << "\n";
    std::cout << "Category: " << getCategory() << "\n";
    std::cout << "School: " << getSchool() << "\n";
    for (int i = 0; i < weapons_.size(); i++){
        std::cout << "Weapons: " << weapons_[i].name << ": " << weapons_[i].damage << ", " << (weapons_[i].ranged ?  "RANGED" : "NOT RANGED") << "\n";
    } 
    std::cout << "Notoriety: " << getNotoriety() << "\n";
    std::cout << "Health: " << getHealth() << "\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Is Wanted: " << (isWanted_? "TRUE" : "FALSE") << "\n";
    std::cout << "Hostile: " << (isHostile()? "TRUE" : "FALSE") << "\n";
}

/**
@post: Checks to see if two cat thugs are equal
@post: Checks names, notoriety, and is wanted
*/
bool operator==(const CatThug& catThug1, const CatThug& catThug2){
    return catThug1.getName() == catThug2.getName() && catThug1.getNotoriety() == catThug2.getNotoriety() && catThug1.isWanted_ == catThug2.isWanted_;
}

