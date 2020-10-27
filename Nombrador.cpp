#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Namer.cpp"
#include "Name.cpp"
//Programado por Diego Reyna Reyes
using namespace std;

int main()
{
    Namer* program=new Namer();
    program->run();
    program->~Namer();
    
    return 0;
}
