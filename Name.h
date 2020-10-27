#include <iostream>
#include <sstream>
#include <vector>
#ifndef NAME_H
#define NAME_H
using namespace std;
//Programado por Diego Reyna Reyes
class Name
{
    public:
        /**
         * Creates a name class, it receives the name information and the delimiters within the info 
         * @param info_line: A stringstream that contains the information as stored in the info file
         * @param delimiter: A characher that delimits the division between name and paired names
        */
        Name(string info_line, char new_delimiter);
        ~Name();
        /**
         * Adds a name's index to the paired index list
         * @param index: The index number of the paired name in the file
        */
        void addPairedName(int index);
        /**
         *Returns of the searched index is inside the paired index list
         *@param index: The index number of the paired name in the file
        */
        bool newPairedName(int index);
        /**
         * Returns the name value
        */
        string getName();
        string getInfo();
        string getFrase();
        int getFranc();
    protected:
        string name;
        vector <int> paired_names_index;
        string delimiter;
        int franchise_index;
        string frase;

};

#endif