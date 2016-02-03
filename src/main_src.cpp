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

int main()
{

	unordered_map<string,code_table_glb*> pattern_finder;
	vector<string> input_to_process;
	vector<string> output_to_get;
	vector<string> decoded_output;
	vector<pair<string,string> > word_dict_glb;



	/* func to put values to code table */
	pattern_finder=initialize();	

	/* get inuput data */
	input_to_process=get_file_input();

	/* input processor */
	
	output_to_get=input_processor(input_to_process,pattern_finder,word_dict_glb);

	/* display results */

	display_results(input_to_process,output_to_get);

	/* decode */
	decoded_output=decode_string(output_to_get);
	
	return 0;	
	
}

/* function to display results
*/
void display_results(vector<string> input,vector<string> output)
{
	
	cout<<"=======================================\n";
	cout<<" ---------- RESULTS --------------------\n";
	cout<<"=======================================\n";
	for(int i=0;i<output.size();i++)
	{
		cout<<input[i]<<"\t"<<"---->"<<"\t"<<output[i]<<"\n";
	}
}
/*
* function to initialize code table
*/
unordered_map<string,code_table_glb*> initialize()
{
	
	unordered_map<string,code_table_glb*> pattern_finder;
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

	
	code_table_glb *ob1 = new code_table_glb(code,pattern,length,frequency);	

	pattern_finder.insert(make_pair(pattern,ob1));

	/* init 2 */

	// code init 01
	
	code.assign("01");
	
	// string init xxxx
	pattern.assign("xxxx");

	
	// len=34;
	length=34;
	
	frequency=32.1;

	code_table_glb *ob2= new code_table_glb(code,pattern,length,frequency);

	
	pattern_finder.insert(make_pair(pattern,ob2));
	
	
	/* init 3 */
	
	code.assign("10");
	

	// string init mmmm
	pattern.assign("mmmm");

	
	// len=6;
	length=6;
	
	frequency=7.6;

	code_table_glb *ob3= new code_table_glb(code,pattern,length,frequency);
	
	pattern_finder.insert(make_pair(pattern,ob3));
	
	
	
	/* init 4 */
	
	code.assign("1100");

	// string init mmxx
	pattern.assign("mmxx");

	
	// len=24;
	length=24;
	
	frequency=6.1;

	code_table_glb *ob4= new code_table_glb(code,pattern,length,frequency);

	
	pattern_finder.insert(make_pair(pattern,ob4));
	
	/* init 5 */
	
	code.assign("1101");
	
	// string init zzzx
	pattern.assign("zzzx");

	
	// len=12;
	length=12;
	
	frequency=7.3;

	code_table_glb *ob5= new code_table_glb(code,pattern,length,frequency);

		
	pattern_finder.insert(make_pair(pattern,ob5));
	
	/* init 6 */
	
	code.assign("1110");

	// string init mmmx
	pattern.assign("mmmx");

	
	// len=16;
	length=16;
	
	frequency=7.2;

	code_table_glb *ob6= new code_table_glb(code,pattern,length,frequency);

	
	pattern_finder.insert(make_pair(pattern,ob6));
	
	return pattern_finder;

}
