/*
Author: Ibrahim Moftah
*/

#include "skill.hpp"

using namespace std;

Skill::Skill()
{
    skill_name= "Undefined";
    skill_description= "Undefined";
    skill_specialty= -1;
    skill_uses= -1;

}

Skill::Skill(string name, string description, int specialty, int uses)
{
    skill_name = name;
    skill_description = description;
    skill_specialty = specialty;
    skill_uses = uses;

}

string Skill::getName()
{
    return skill_name;
}

string Skill::getDescription()
{
    return skill_description;
}

int Skill::getTotalUses()
{
    return skill_uses;
}

int Skill::getSpecialty()
{
    return skill_specialty;
}

void Skill::setName(string name)
{
    skill_name = name;
}

void Skill::setDescription(string description)
{
    skill_description = description;
}

void Skill::setTotalUses(int uses)
{
    skill_uses = uses;
}

bool Skill::setSpecialty(int specialty)
{
    if ((specialty <= 2) && (specialty >= 0))
    {
        skill_specialty = specialty;
        return true;
    }

    return false;
    
}
