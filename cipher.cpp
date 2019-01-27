// ROT(n, s) is defined as the rotation by n characters of string:
// ROT(“abc”) = “bcd”
// ROT(“zabc”) = “abcd”
// ROT(“rot”) = “tqv”
// Etc.
// We define two strings a, b, to be equivalent if there exists m such that applying rot(n) m times on a gives b.
// For example:
// “abc”, “bcd”, “def”, “zab” are all equivalent in rot1.
// “abc”, “cde”, “efg” are all equivalent in rot2.
// 
// Given n, and a list of strings, provide the list of all equivalent strings.
// For example, for n = 1
// “abc”, “cde”, “aaa”, “ddd”, “efg” has two sets of strings:
// “abc”, “cde”, “efg”
// “aaa” , “ddd”

// evannier@
//
// 1. int getDiff(char c1, char c2)
//    compute an n such that c2 = ROT(int n, c1)
//
// 2. isEqual( string str1, string str2 )  
//    checks the strlen() of str1.strlen() = str2.strlen() 
//    then calls getDiff() on the first letter
//    of the two strings and testing the rest of the characters of the strings 
//    with subsequent calls to getDiff() and comparing the returns
using namespace std;

const bool TRUE = 1;
const bool FALSE = 0;

int tolower( const char c)
{
  int char_num = (int)(c) - 97;
  return((char_num ) % 26 + 97);
}

int getDiff( char c1, char c2 )
{
  //make them lower case
  int char_num1 = tolower(c1);
  int char_num2 = tolower(c2);
  return ((26 - (char_num1-char_num2))%26 );

}

char ROTCHAR( int n, char c )
{
  if(n == 0)
	return c;
  int char_num = (int)(c) - 97;
  return((char_num + n) % 26 + 97);

}

string ROT(int n, string str)
{
    string temp = str; 
    int length; 

    length = (int)temp.length(); 

    for (int i = 0; i < length; i++)
    {
		if (isalpha(temp[i]))
        {
			temp[i] = ROTCHAR(n, temp[i]);
		}
				
	}
    return temp;
}
bool isEqual( int n, char c1, char c2)
{
    cout << "diff of " << c1 << " and " << c2  <<" : " 
		<< getDiff( c1, c2 ) << endl;
   return ( (n == getDiff( c1, c2 ))?TRUE:FALSE );	
   //return( (c2 == ROTCHAR(n, c1))?TRUE:FALSE ) ;
}

bool  isEqual( string str1, string str2 )
{

	int len;
	bool last_cmp = FALSE;

	if( (len = str1.length()) != str2.length() )
		return FALSE;
	int	n = getDiff( str1[0] , str2[0] );
    cout << "diff of " << str1 << " and " << str2 <<" : " << n << endl;
	// get the difference of the first character of the
	// strings to be compared and see if that n difference
	// is maintained the rest of the strings
	int i = 1;
	while( (last_cmp = isEqual(n, str1[i], str2[i])) && (i < (len-1)) )
	{
		i++;
	}
	return last_cmp;
}

//  TODO: Scale to accept a list of strings to be compared and return 
//        ordered set lists i.e. sets that have indexes of:
//				1. equal strlen() 
//				2. equal N's (where N is the rotation/shift diff 
//                 between strings)
//EqSets & findEqualSets ( int n, StrList & strlist )
//{
//}
