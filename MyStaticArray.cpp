// Programmer: Sadeem Khan
// Programmer's ID: 1549921

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

#include "StaticArray.h"

int main()
{
  // Identification
  cout << "Programmer: Sadeem Khan\n";
  cout << "Programmer's ID: 1549921\n";
  cout << "File: " << __FILE__ << endl;

  StaticArray<double, 100> a;
  StaticArray<bool, 100> indexesEntered;
  int totalValuesStored = 0;

  while (true)
  {
    string index;
    string value;
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q") break;
    cin >> value;
    cin.ignore(1000,10);

    a[atof(index.c_str())] = atof(value.c_str()); // converts
    indexesEntered[atof(index.c_str())] = 1; // indexes entered == true
  }

  cout << endl; // for spacing

  for(int i = 0; i < 100; i++)
  {
    if(indexesEntered[i] == 1) 
      totalValuesStored++;
  }

  cout << "You stored this many values: " << totalValuesStored << endl;
  cout << "The index-value pairs are:" << endl;

  for(int i = 0; i < 100; i++)
  {
    if(indexesEntered[i] > 0) cout << i << " => " << a[i] << endl;
  }

  cout << endl; // for spacing
  while (true)
  {
    string index;
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> index;
    if (index == "Q" || index == "q") break;
    
    if (atof(index.c_str()) >= 0 && atof(index.c_str()) < 100 && indexesEntered[atof(index.c_str())] == 1) cout << "Found it -- the value stored at " << index << " is " << a[atof(index.c_str())] << endl;
    else cout << "I didn't find it" << endl;
  }
}