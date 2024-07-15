/*
Author: Ibrahim Moftah
*/

#ifndef DEPARTMENT
#define DEPARTMENT

#include "trainer.hpp"

class MLDepartment: public Trainer{
    public:
        MLDepartment(vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class SoftwareDepartment: public Trainer{
    public:
        SoftwareDepartment(vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class HardwareDepartment: public Trainer{
    public:
        HardwareDepartment(vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

#endif
