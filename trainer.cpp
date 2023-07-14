/*
Author: Ibrahim Moftah
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3B

*/

#include "trainer.hpp"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

Trainer::Trainer()
{
   currentProfemon = nullptr;

}

Trainer::Trainer(vector <Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++) 
    {
        if (i < 3)
        {
            team[i] = profemons[i];
        }

        else 
        {
            profedex.push_back(profemons[i]);
        }
    }

    currentProfemon = &team[0];
}

bool Trainer::contains(string name)
{
    for (int i = 0; i < 3; i++) 
    {
        if (team[i].getName() == name) 
        {
            return true;
        }
    }

    for (int i = 0; i < profedex.size(); i++) 
    {
        if (profedex[i].getName() == name) 
        {
            return true;
        }
    }

    return false;
    
}

bool Trainer::addProfemon(Profemon profemon)
{
    if (contains(profemon.getName())) 
    {
        return false;
    }

    for (int i = 0; i < 3; i++) 
    {
        if (team[i].getName() == "Undefined") 
        {
            team[i] = profemon;
            if (currentProfemon == nullptr) 
            {
                currentProfemon = &team[i];
            }
            return true;
        }
    }
    profedex.push_back(profemon);
    return true;
    
}

bool Trainer::removeProfemon(string name)
{
    // First, check if the profémon is in the current team
    for (int i = 0; i < 3; i++) 
    {
        if (team[i].getName() == name) 
        {
            // Found the profémon in the team, remove it and return true
            team[i] = Profemon(); // set to default-constructed Profemon object
            return true;
        }
    }

    for (int i = 0; i < profedex.size(); i++) 
    {
        if (profedex[i].getName() == name) 
        {
            profedex.erase(profedex.begin()+i);
            return true;
        }
    } 

    // The profémon was not found, return false
    return false;

}

void Trainer::setTeamMember(int slot, string name)
{
    if (slot < 0 || slot > 2) 
    {
        return;
    }

    Profemon temp;

    for (int i = 0; i < profedex.size(); i++) 
    {
        if (profedex[i].getName() == name) 
        {
            if (team[slot].getName() == "Undefined") 
            {
                temp = profedex[i];
                removeProfemon(name);
                team[slot] = temp;
                break;
            }
            else 
            {
                temp = team[slot];
                team[slot] = profedex[i];
                profedex[i] = temp;
                break;
            }
        }
    }

}

bool Trainer::chooseProfemon(int slot)
{
    // Check if the slot contains a profémon
    if (team[slot].getName() == "Undefined") 
    {
        return false;
    }

    // Set the accompanying profémon to the profémon in the slot
    currentProfemon = &team[slot];

    return true;
}

Profemon Trainer::getCurrent()
{
    return *currentProfemon;
}

void Trainer::printProfedex()
{
    for (int i = 0; i < profedex.size(); i++) 
    {
        profedex[i].printProfemon(false);
        cout << endl;
    }
}

void Trainer::printTeam()
{
    for (int i = 0; i < 3; i++) 
    {
        if (team[i].getName() != "Undefined") 
        {
            team[i].printProfemon(true);
            cout << endl;
        }
    }
}