// main.cpp
#include <iostream>
import Example;

using namespace std;

int main()
{
   cout << "myrand() returned " << NsExample::myrand() << endl; // 42
   int i = NsExample::internal_func(); // C2039
   int j = RANDVAL; //C2065
}
