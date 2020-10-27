#include "Namer.h"
//Programado por Diego Reyna Reyes
string changeToRoman(int arab)
{
    int single=0, ten=0, hundred=0;
    string roman="";
    string single_roman[9]={"I","II","III","IV","V","VI","VII","VIII","IX"},
            ten_roman[9]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            hunderd_roman[9]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};

    hundred=arab-(arab%100);
    ten=arab-hundred-(arab%10);
    single=arab-hundred-ten;
    if (hundred>0)
    {
        roman+=hunderd_roman[(hundred/100)-1];
    }
    if (ten>0)
    {
        roman+=ten_roman[(ten/10)-1];
    }
    if (single>0)
    {
        roman+=single_roman[single-1];
    }
    if (roman=="")
    {
        roman="0 does not exists";
    }
    return roman;
}
Namer::Namer()
{

}
Namer::~Namer()
{

}
void Namer::readFile(string file_name)//Reads a file and creates the name classes with that info
{
    ifstream file;
    file.open(file_name);
    string line;
    int num_franchises;
    getline(file,line);//Get the number which is the first line
    number=atoi(line.c_str());
    getline(file,line);//Get the number of franchises from the second line
    num_franchises=stoi(line.c_str());//Change from str to int
    for (int j=0;j<num_franchises;j++){
        getline(file,line);//Get the frase
        franchise_frase.push_back(line);//Add it to the vector
    }
    while (getline(file,line))
    {
        available_names.push_back(new Name(line, delimiter));
    }
    file.close();
}
void Namer::run()//Starts the application
{
    string file_name="names.txt";
    readFile(file_name);
    srand(time(NULL));
    string given_name;
    bool invalid_name=true;
    while (invalid_name)
    {
        int first=rand()%available_names.size();
        int second=rand()%available_names.size();
        if (first!=second && available_names[first]->newPairedName(second))
        {
            invalid_name=false;
            given_name=available_names[first]->getName()+" "+available_names[second]->getName()+" "+changeToRoman(number);
            available_names[first]->addPairedName(second);
            number++;
            cout<<franchise_frase[available_names[first]->getFranc()]<<" x "<<franchise_frase[available_names[second]->getFranc()]<<endl;//Print franchise crossover
            cout<<endl<<available_names[first]->getFrase()<<endl<<available_names[second]->getFrase()<<endl;//Print characters frases
        }
    }
    cout<<"Your new amazing project is:"<<endl<<given_name<<endl;
    saveChanges(file_name);
}
void Namer::saveChanges(string file_name)//Rewrites the file with the changed info
{
    ofstream file (file_name);
    file<<number<<endl;
    file<<franchise_frase.size();
    vector<Name*>::const_iterator iterator;
    vector<string>::const_iterator frase_iterator;
    for (frase_iterator=franchise_frase.begin();frase_iterator!=franchise_frase.end();++frase_iterator)
    {
        file<<endl<<(*frase_iterator);//Add the frases to the file
    }
    for (iterator=available_names.begin();iterator!=available_names.end();++iterator)
    {
        file<<endl<<(*iterator)->getInfo();
    }
    file.close();
}