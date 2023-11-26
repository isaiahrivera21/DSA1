// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, FALL 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.

void LetterLoad(list<Data *> &l); 
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);
  sortDataList(theList); 
  //LetterLoad(theList); 

/*
  cout << "Data loaded.\n";


  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList); 
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);
*/
  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.


Data* inputarr[1010000]; //stirng 
Data* outputarr[1010000]; 
int countarr[10]; //26 letters in the alphabet  
int sizet = 3;


void sortDataList(list<Data *> &l) {
  auto it = l.begin();
  int size = l.size();  
  int letterposition = 9;
  for (int i = 0; i < size; i++) {
		inputarr[i] = *it;
        //cout << inputarr[i] -> ssn[3] << "\n"; 
		it++;
	}



  for(letterposition; letterposition >= 0; letterposition --)
  {
    for (int j = 0; j< 9; j++)
    {
      countarr[j] = 0; //filled with "0's" at first 
      //cout << countarr[j] << "\n"; 
    }
    for(int k = 0; k < sizet; k++) //have to have another condition that shifts through the position  
    {
        if(inputarr[k] -> ssn[letterposition] == '-')
        {
            letterposition--;  
        }
      countarr[((inputarr[k] -> ssn[letterposition]) - 48)]++; //seems to be working 
    }
    for (int m = 0; m < 9; m++)
    {
      countarr[m] = countarr[m] + countarr[m-1]; 
    }
    for(int n = (size - 1); n >= 0; n--)
    {
      outputarr[countarr[((inputarr[n] -> ssn[letterposition]) - 48) -1]] -> ssn = inputarr[n]-> ssn;  
    }
    for(int o = 0; o < sizet; o++)
    {
      inputarr[o] = outputarr[o]; 
      cout << inputarr[o] << "\n"; 
    }
  }
}
//count arr should not be 25 
/*
void LetterLoad(list<Data *> &l){
    //make an array and populate it with strings 

    int size = l.size();
    //int size = 12; 
    int letterposition = 11; //possible using this for multiple things could be bad?????
    //--------------------------------------------
    //sort the string backwards 
    for(letterposition; letterposition >= 0; letterposition --) //loop string backwards 
    {
      for (int j = 0; j< 10; j++)
    {
      countarr[j] = 0; //filled with "0's" at first 
      //cout << countarr[j] << "\n"; 
    }

    for(int k = 0; k < size; k++) //have to have another condition that shifts through the position  
    {
      //letter position will shift the letter position. Concern: WHEN to increment  
      //check each letter in the located letter position and preform the count thing

      countarr[((inputarr[k][letterposition]) - 65)]++; //seems to be working 
      //cout << countarr[24] << "\n"; 
    }
    //-----------------------------------
    for (int m = 0; m < 10; m++)
    {
      countarr[m] = countarr[m] + countarr[m-1]; 
    }
    for(int n = (size -1); n >= 0; n--)
    {
      outputarr[countarr[((inputarr[n][letterposition]) - 65) - 1]] = inputarr[n];  
    }
    for(int o = 0; o < size; o++)
    {
      inputarr[o] = outputarr[o]; 
      cout << inputarr[o] << "\n"; 
    }
    //happens for the first letter then you shift to the next. Wanna avoid the double for loop 

    }
    
}
*/