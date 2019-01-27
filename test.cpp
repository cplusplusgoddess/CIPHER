// -------------------------------------------
// main driver for cipher - Use CTRL-C to quit
// author: Amber Rogowicz 
// Jan 2019

#include <iostream> 
#include <string> 
#include "cipher.cpp"
using namespace std;

const char E_STR[]  = " are EQUAL";
const char NE_STR[] = " are NOT EQUAL";  
int main(int argc, char ** argv)
{

  string str1, str2;
  while (1)
  {
	cout << "Please enter 2 strings: " << endl; 
    cin >> str1 >> str2 ;

    bool cmp = isEqual( str1, str2 );
    cout << str1 << " and "<< str2 << ((cmp==TRUE)?E_STR:NE_STR)  << endl;
  }
}
