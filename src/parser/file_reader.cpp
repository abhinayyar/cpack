// functions to read data from the file

#include<iostream>
#include<vector>


using namespace std;

vector<string> get_file_input(void)
{

	/* need to add code for reading input from the file */
	
	/* tmp method */

	vector<string> res;
	res.push_back("00000000");
	res.push_back("000000AB");
	res.push_back("BBBB2022");
	res.push_back("123456AA");
	res.push_back("AAAAAAAA");
	res.push_back("AAAAAAAA");

	res.push_back("123456AA");

	res.push_back("BBBB2022");
	
	res.push_back("000000AB");
	res.push_back("BB111111");
	res.push_back("BBBB1111");
	return res;
}
