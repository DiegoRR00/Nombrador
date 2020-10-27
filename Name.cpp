#include "Name.h"
//Programado por Diego Reyna Reyes
/**
 * Creates a name class, it receives the name information and the delimiters within the info 
 * @param info_line: A stringstream that contains the information as stored in the info file
 * @param delimiter: A characher that delimits the division between name and paired names
*/
Name::Name(string info_line, char new_delimiter)
{
    stringstream info_stream(info_line);
    string word;//Variable to save the infp in the line
    delimiter=new_delimiter;//Remember the delimiter
    getline(info_stream,name,new_delimiter);//Get the first member of the line, which is the name
    while(getline(info_stream,word,new_delimiter))//Fo every other characther in the line
    {
        paired_names_index.push_back(stoi(word));//Add it to the paired names index vector
    }
}
Name::~Name()
{

}
/**
 * Adds a name's index to the paired index list
 * @param index: The index number of the paired name in the file
*/
void Name::addPairedName(int index)
{
    paired_names_index.push_back(index);
}
/**
 *Returns of the searched index is inside the paired index list
*@param index: The index number of the paired name in the file
*/
bool Name::newPairedName(int index)
{
    bool new_pair=true;//Create the return variable set by default as true
    vector <int>::const_iterator vector_iterator;//Create an iterator for my vector
    for (vector_iterator=paired_names_index.begin();vector_iterator!=paired_names_index.end();++vector_iterator)//For each member of the vector
    {
        if (*vector_iterator==index)//If the index is already inside
        {
            new_pair=false;//Change the return variable to false
        }
    }
    return new_pair;
}
/**
 * Returns the name value
*/
string Name::getName()
{
    return name;
}
string Name::getInfo()
{
    string line=name;
    for (int i=0;i<paired_names_index.size();i++)
    {
        if (paired_names_index[i]!=-1)
        {
            line+=delimiter+to_string(paired_names_index[i]);
        }
    }
    return line;
}