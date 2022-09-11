/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test1;
  string str1 = "one";
  string str2 = "two";
  string str3 = "three";
  string str4 = "four";
  string str5 = "five";
  test1.push_back(str3);
  test1.push_back(str4);
  test1.push_front(str2);
  test1.push_front(str1);
  //Breakpoint 1: head should point to one two, tail points to three four
  test1.pop_back(); // should pop str2
  test1.pop_front(); // should delete the first node and change head
// Breakpoint 2: head points to two, tail points to three.
  cout << test1.get(0)<< ' '<< test1.get(1)<< endl; //should print two three .
  test1.pop_front();
//Breakpoint 3 head and tail points to array with "three", prev and next point to 0
  test1.push_back(str1);
  test1.push_back(str2);
  test1.push_back(str3);
  test1.push_back(str4);
  test1.push_back(str5);
  test1.push_back(str1);
  test1.push_back(str2);
  test1.push_back(str3);
  test1.push_back(str4);
  test1.push_back(str5);
  //Breakpoint 4, head: 3123451234, tail: 5
  cout << test1.get(0)<< " "<< test1.get(10)<< endl;
  //Breakpoint 5, should print three five
  test1.set(0,str1);
  test1.set(10,str1);
  //Breakpoint 6, head: 1123451234, tail: 1
  cout << test1.size() << endl;
  //Breakpoint 7, should return 11;
  return 0;
}
