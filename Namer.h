#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include "Name.h"
//Programado por Diego Reyna Reyes
#ifndef NAMER_H
#define NAMER_H
using namespace std;
class Namer
{
    public:
        Namer();
        ~Namer();
        void readFile(string file_name);//Reads a file and creates the name classes with that info
        void run();//Starts the application
        void saveChanges(string file_name);//Rewrites the file with the changed info
    protected:
        vector <Name*> available_names;
        int number;
        char delimiter=',';
};
#endif