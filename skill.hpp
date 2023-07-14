/*
Author: Ibrahim Moftah
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3A

*/
#ifndef SKILL_HPP
#define SKILL_HPP
#include <iostream>

using namespace std;

class Skill {
private:
    string skill_name;
    string skill_description;
    int skill_specialty;
    int skill_uses;
    
public:

    /*
    @post       :   Initializes the name and 
                    description of the skill as 
                    "Undefined". Initializes the 
                    total uses of the skill and
                    the skill specialty as -1 
    */ 
    Skill();

    /*
    @post       :   Parameterized constructor that
                    sets the corresponding data members
                    equal to the respective parameters
    */
    Skill(string name, string description, int specialty, int uses);

    /*
        @return     :   name of the skill
    */
    string getName();

    /*
        @return     :   description of the skill
    */
    string getDescription();

    /*
        @return     :   total uses of the skill
    */
    int getTotalUses();

    /*
        @return     :   specialty of the skill 
    */
    int getSpecialty();

    /*
        @post       :   set the name of the skill 
                        equal to the given parameter
    */
    void setName(string name);

    /*
        @post       :   set the description of the skill 
                        equal to the given parameter
    */
    void setDescription(string description);

    /*
        @post       :   set the total uses of the skill
                        equal to the given parameter
    */
    void setTotalUses(int uses);
    
    /*
    @return     :   Return 'true' if the given parameter 
                    is either 0, 1 or 2. Otherwise,
                    return 'false'
    @post       :   set the specialty of the skill
                    equal to the given parameter only
                    if the given parameter is valid (0,1,2)
                    Return 'true' if the specialty
                    is successfully updated 
    */
    bool setSpecialty(int specialty);

};

#endif