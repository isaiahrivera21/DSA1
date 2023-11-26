//Name: Isaiah Rivera 
//Description: A user input a text file that contains commands to create, push, or pop a stack or queue. 

#include<iostream>
#include<sstream>
#include<fstream> 
#include<string>

using namespace std;  

template<typename Object> 
class SimpleList {
    private: 
        string name;
        class Node 
        {
            T data; 
            Node *next; //pointer to the adress of the next
        }; 

    public: 
    string getname() {return name;}
    SimpleList(string n){ name = n;}
    virtual void fun() = 0; 
    protected:
    Node *head = NULL;  
}; 

class DerivedList : public SimpleList<Object> {

    public: 
    DerivedList(string n): SimpleList(n){}
    void fun() {"Generic Text";}

}; 

 

void ProcessList(string); 
 
int main() { 
    DerivedList L1("ngng"); 
    string s = L1.getname(); 
    cout << s << endl; 
    string fileName; 
    

    cout << "Name of file: " << endl; 
    cin >> fileName;
    ProcessList(fileName); 
}


//template function to parse through input 
//template <typename T> //instead of if statements for deciding whether it should be an int,string, or double can use template instead 
void ProcessList (string fileName) {
    ifstream inputFile; 
    inputFile.open(fileName); 
    string command; 
    string line;
    string s2; 
    
    while (getline(inputFile, line))
    {
        stringstream sso (line);
        sso >> command >> s2; 
        
        //cout << command << endl; 
        
        //compare to see if its create push or pop. Impleent the check first. Preform a push pop or create 
        if (command.compare("create") == 0)
        {
            cout << "c" << endl;
            //create check --> has do with s2 --> see if s2 matches with anything else. Compare everything else 
            //to create push a ptr to stack/queue into the linked list of the respective data type 

        }
        if (command.compare("push") == 0)
        {
            cout << "push" << endl; 
        }
        if (command.compare("pop") == 0)
        {
            cout << "pop" << endl; 
        }
    }
}
