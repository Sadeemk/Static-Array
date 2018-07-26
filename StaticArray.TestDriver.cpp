// Programmer: Sadeem Khan
// Programmer's ID: 1549921

#include <iostream>
using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h" // ifndef test

int main()
{
  // Identification
  cout << "Programmer: Sadeem Khan\n";
  cout << "Programmer's ID: 1549921\n";
  cout << "File: " << __FILE__ << endl;

  // Test using doubles 
  StaticArray<double, 100> a;
  cout << "Testing Array::Array\n";
  for (int i = 0; i < a.capacity(); i++) assert(a[i] == 0);

  cout << "\nTesting the Array::operator[] setter\n";
  a[8] = 3131.32;
  a[9] = 2121.21;
  cout << "\nTesting Array::operator[] setter\n";
  cout << "EXPECTED: 3131.32 for a[8]\n";
  cout << "ACTUAL: " << a[8] << endl;
  assert(3131.32 == a[8]);
  cout << "EXPECTED: 2121.21 for a[9]\n";
  cout << "ACTUAL: " << a[9] << endl;
  assert(2121.21 == a[9]);
  a[-1000] = 1549.49;
  cout << "EXPECTED: 1549.49 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(3131.32 == a[8]);
  assert(2121.21 == a[9]);
  assert(1549.49 == a[-6]); // any out-of-range uses dummy
  assert(1549.49 == a[100]); // checks upper end of range
  assert(1549.49 != a[99]); // checks upper end of range
  assert(1549.49 != a[0]); // checks lower end of range

  cout << "\nTesting the Array::operator[] getter\n";
  const StaticArray<double, 100> b = a;
  for (int i = 0; i < 10; i++) assert(a[i] == b[i]);

  cout << "\nConst object test" << endl;
  const StaticArray<double, 100> c;
  assert(c.capacity());
  assert(c[0] == c[0]);

  StaticArray<string, 100> x;
  
  // Now testing using ints
  StaticArray<int, 100> e;
  cout << "Testing Array::Array\n";
  for (int i = 0; i < e.capacity(); i++) assert(e[i] == 0);

  cout << "\nTesting the Array::operator[] setter\n";
  e[8] = 3131;
  e[9] = 2121;
  cout << "\nTesting Array::operator[] setter\n";
  cout << "EXPECTED: 3131 for e[8]\n";
  cout << "ACTUAL: " << e[8] << endl;
  assert(3131 == e[8]);
  cout << "EXPECTED: 2121 for e[9]\n";
  cout << "ACTUAL: " << e[9] << endl;
  assert(2121 == e[9]);
  e[-1000] = 1549;
  cout << "EXPECTED: 1549 for e[-1000]\n";
  cout << "ACTUAL: " << e[-1000] << endl;
  assert(3131 == e[8]);
  assert(2121 == e[9]);
  assert(1549 == e[-6]); // any out-of-range uses dummy
  assert(1549 == e[100]); // checks upper end of range
  assert(1549 != e[99]); // checks upper end of range
  assert(1549 != e[0]); // checks lower end of range

  cout << "\nTesting the Array::operator[] getter\n";
  const StaticArray<int, 100> f = e;
  for (int i = 0; i < 10; i++) assert(e[i] == f[i]);

  cout << "\nConst object test\n";
  const StaticArray<int, 100> g;
  assert(g.capacity());
  assert(g[0] == g[0]);
}