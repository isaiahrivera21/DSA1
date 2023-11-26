//Name: Isaiah Rivera 
//Description: The following program takes in 'foobars' from a text file and outputs a text file with the strenth of the foobar next to its name. 

#include<iostream>
#include<vector>
#include<sstream>
#include<fstream> 
#include<string>

using namespace std; 
class foobars {
    private: 
        int position;
        string name;
    public: 
        int poobar =77; 
        foobars(string d)
        {
            name = d; 
            //position = p; 
        }
    string getname(); 
    int setposition(int); 
    virtual int setstrength(int); //takes in position number and uses it to generate strength 
    int getposition(); 

}; 

string foobars :: getname(){
    return name; 
}


int foobars :: setposition(int poobar){
    position = poobar; 
    return poobar; 
}

int foobars :: setstrength(int obj_position)
{
    int strenth = obj_position; 
    return strenth; 
}

int foobars :: getposition()
{
    return position; 
}

class foo: public foobars
{
    private: 
        //string fooname; 
        int foo_position; 
        string fooname;
    public:  
    foo(string fs, int fp=0): foobars(fs)  {
        fooname = fs;
    } 
    virtual int setstrength(int); 

}; 

int foo :: setstrength(int obj_position){
    int foo_strength = obj_position * 3; 
    return foo_strength; 

}

class bar: public foobars
{
    private: 
        string barname;
        int bar_positon; 
    public: 
    bar(string bn) : foobars(bn){
        barname = bn; 
    }
    virtual int setstrength(int); 
};

int bar :: setstrength(int obj_position){
    int bar_strength = obj_position + 15; 
    return bar_strength;  
}


void ProcessFooBar(string,string,vector <foobars*>& vect);
void LoadFoobars (vector <foobars*>& vect); 
void FoobarStrength (vector <foobars*>& vect, string); 

int main () {
vector <foobars*> list; 
string fileName;
string outputName; 
string foobar; 
cout << "Type your input filename: \n";
cin >> fileName; 
cout << "Type in your output filename \n";
cin >> outputName; 

ProcessFooBar(fileName,foobar, list); 
LoadFoobars(list); 
FoobarStrength(list, outputName); 
}

void ProcessFooBar (string fileName,string name, vector <foobars*>& vect){
ifstream inputFile; 
inputFile.open(fileName); //allows to open the file name
string foobar_type, foobar_name; 
int i = 0; 
while(getline(inputFile, name))
{
    stringstream sso (name);
    sso >> foobar_type >> foobar_name; 
    if (foobar_type.compare("foo") == 0)
    {
        foo* ptr_foo = new foo(foobar_name); 
        vect.push_back(ptr_foo);
    }
    else if(foobar_type.compare("bar") == 0)
    {
        bar* ptr_bar = new bar(foobar_name); 
        vect.push_back(ptr_bar);
    } 
    else if (foobar_type.compare("foobar") == 0)
    {
        foobars* ptr_fb  = new foobars(foobar_name); //object is a foobar (base class)
        vect.push_back(ptr_fb); 
    }
}
}
void LoadFoobars (vector <foobars*>& vect){

    int j = 0; 
    for(int i = vect.size(), j =0; i > 0 && j < vect.size(); i--,j++ )
    {   

       //cout << vect.at(j)->getname() << " " << vect.at(j)->setposition(i) << endl;; //want reverse order 
       vect.at(j)->setposition(i); 
       
    }
}

void FoobarStrength (vector <foobars*>& vect, string outputname){

    ofstream output; 
    output.open(outputname); 
    for(int j =0; j < vect.size(); j++ )
    {     
       output << vect.at(j)->getname() << " " << vect.at(j) -> setstrength(vect.at(j)->getposition())<< endl;

    }
    output.close(); 
}



