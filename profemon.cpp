/*
Author: Ibrahim Moftah
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3A

*/

#include "profemon.hpp"

Profemon::Profemon()
{
    profemon_name = "Undefined";

}

Profemon::Profemon(string name, double max_health, Specialty specialty)
{
    profemon_name = name;
    profemon_max_health = max_health;
    profemon_specialty = specialty;
    profemon_requiredExp = 50;
    profemon_currentExp = 0;
    profemon_level = 0;

}

string Profemon::getName()
{
    return profemon_name;
}

Specialty Profemon::getSpecialty()
{
    return profemon_specialty;
}

int Profemon::getLevel()
{
    return profemon_level;
}

double Profemon::getMaxHealth()
{
    return profemon_max_health;
}

void Profemon::setName(string name)
{
    profemon_name = name;
}

void Profemon::levelUp(int exp)
{
    profemon_currentExp += exp;

    while (profemon_currentExp >= profemon_requiredExp)
    {
        profemon_currentExp -= profemon_requiredExp;
        profemon_level++;

        if (profemon_specialty == ML)
        {
            profemon_requiredExp += 10;
        }

        if (profemon_specialty == SOFTWARE)
        {
            profemon_requiredExp += 15;
        }

        if (profemon_specialty == HARDWARE)
        {
            profemon_requiredExp += 20;
        }

    }
    
}

bool Profemon::learnSkill(int slot, Skill skill)
{
    if ((slot >= 0 && slot <= 2) && (profemon_specialty == skill.getSpecialty()))
    {
        profemon_skill[slot] = skill;
        return true;
    }

    return false;
    
}

string Profemon::printSpecialty()
{
    string pr_specialty;
    
    if (profemon_specialty == 0)
    {
        pr_specialty = "ML";
    }
    
    if (profemon_specialty == 1)
    {
        pr_specialty = "SOFTWARE";
    }
    
    if (profemon_specialty == 2)
    {
        pr_specialty = "HARDWARE";
    }
    return pr_specialty;
}

void Profemon::printProfemon(bool print_skills)
{
    cout << profemon_name << " [" << printSpecialty() << "] | lvl " << profemon_level << " | exp " << profemon_currentExp << "/" << profemon_requiredExp << " | hp " << profemon_max_health << endl;
    if (print_skills == true) 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (profemon_skill[i].getName() != "Undefined") 
            {
                cout << "    " << profemon_skill[i].getName() << " [" << profemon_skill[i].getTotalUses() << "] : " << profemon_skill[i].getDescription() << endl;
            }
        }
    }
}