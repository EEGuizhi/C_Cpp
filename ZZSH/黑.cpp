
#include <iostream>
#include <string>
using namespace std;
int main() 
{
  int length;
  string s;
  string D;
  cout<<"輸入並解密:";
  while (cin >> s)
  {
    length=s.length();
    for(int i=0;i<length;i++)
	{
      cout << char(s.at(i) - 2 );        
    }
    cout << endl;
	break;          
  }
  cout<<"輸入並加密:";
  while (cin >> D)
  {
    length=D.length();
    for(int i=0;i<length;i++)
	{
      cout << char(D.at(i) + 2 );        
    }
    cout << endl;
	break;          
  }
  system("PAUSE");
  return 0;
}
	 

