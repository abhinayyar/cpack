#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>


using namespace std;

#define CODE_TABLE_SIZE 6

class code_table_glb
{
public:
	string code;
	string pattern;
	int code_word_len;
	float code_word_fre;

	code_table_glb(string cd,string pt,int len,float fre)
	{
	//	cout<<"Init code table\n";

		code.assign(cd);
		pattern.assign(pt);
		code_word_len=len;
		code_word_fre=fre;
	}
	~code_table_glb()
	{
		//cout<<"detructor called\n";
	}
};
