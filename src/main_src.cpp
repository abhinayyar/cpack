#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<utility>
#include "dict/code_table.h"
#include "main_src.h"
#include "parser/file_reader.h"
#include "processor/data_process.h"

using namespace std;

#define  CODE_TABLE_LEN 6

class dummy
{
	public:
	int val;
	dummy()
	{
		val=4;
	}
	void fun()
	{
		cout<<"Hello we have made call\n";
	}
};

int main()
{

	unordered_map<string,code_table_glb> pattern_finder;
	vector<code_table_glb> table_ob;
	vector<string> input_to_process;
	vector<string> output_to_get;
	vector<pair<string,string> > word_dict_glb;



	/* func to put values to code table */
	table_ob=initialize();	

	/* initialize pattern fnder to reduce cost of search */
	init_pattern_finder(pattern_finder,table_ob);

	/* get inuput data */
	input_to_process=get_file_input();

	/* input processor */
	
	output_to_get=input_processor(input_to_process,pattern_finder,word_dict_glb);

	/* display results */	
//	code_table_glb ob = pattern_finder["xxxx"];
//	cout<<table_ob[0].code<<"\t"<<table_ob[1].code<<"\t"<<table_ob[5].code<<"\n";
//	if(pattern_finder.find("xxxx")!=pattern_finder.end())
//	cout<<"True\n";

	unordered_map<string,dummy*> test;
	
	dummy g;
	
	test.insert(make_pair("xx",&g));
	test["xx"]->fun();
	cout<<test["xx"]->val<<"\n";
//	test["xx"]=&g;
	
		
}

/*
* function to initialize pattern finder 
*/
void init_pattern_finder(unordered_map<string,code_table_glb>& pattern_finder,vector<code_table_glb> table_op)
{
	pattern_finder.insert(make_pair("zzzz",table_op[0]));
	pattern_finder.insert(make_pair("xxxx",table_op[1]));
	pattern_finder.insert(make_pair("mmmm",table_op[2]));
	pattern_finder.insert(make_pair("mmxx",table_op[3]));
	pattern_finder.insert(make_pair("zzzx",table_op[4]));
	pattern_finder.insert(make_pair("mmmx",table_op[5]));		
}
/*
* function to initialize code table
*/
vector<code_table_glb> initialize(void)
{
	vector<code_table_glb> table_ob;

	string code;
	string pattern;
	int length=0;
	float frequency=0;

	/* init 1*/
	
	// code init 00
	code.assign("00");

	// string init zzzz
	pattern.assign("zzzz");

	// len 2
	length=2;

	// frequency
	frequency=39.7;

	
	code_table_glb ob1(code,pattern,length,frequency);	


	table_ob.push_back(ob1);


	/* init 2 */

	// code init 01
	
	code.assign("01");
	
	// string init xxxx
	pattern.assign("xxxx");

	
	// len=34;
	length=34;
	
	frequency=32.1;

	code_table_glb ob2(code,pattern,length,frequency);

	
	table_ob.push_back(ob2);
	
	/* init 3 */
	
	code.assign("10");
	

	// string init mmmm
	pattern.assign("mmmm");

	
	// len=6;
	length=6;
	
	frequency=7.6;

	code_table_glb ob3(code,pattern,length,frequency);

	
	table_ob.push_back(ob3);
	
	/* init 4 */
	
	code.assign("1100");

	// string init mmxx
	pattern.assign("mmxx");

	
	// len=24;
	length=24;
	
	frequency=6.1;

	code_table_glb ob4(code,pattern,length,frequency);

	
	table_ob.push_back(ob4);
	
	/* init 5 */
	
	code.assign("1101");
	
	// string init zzzx
	pattern.assign("zzzx");

	
	// len=12;
	length=12;
	
	frequency=7.3;

	code_table_glb ob5(code,pattern,length,frequency);

	
	table_ob.push_back(ob5);
	
	/* init 6 */
	
	code.assign("1110");

	// string init mmmx
	pattern.assign("mmmx");

	
	// len=16;
	length=16;
	
	frequency=7.2;

	code_table_glb ob6(code,pattern,length,frequency);

	
	table_ob.push_back(ob6);

	return table_ob;
}
