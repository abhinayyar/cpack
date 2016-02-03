
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
#include<utility>

#include<cmath>
#define MAX_DICT_SIZE 32

using namespace std;
vector<string> decode_string(vector<string> input_string)
{
	vector<string> output_string;
	unordered_map<string,string> pattern_finder_decompress;
	for(string cur_str : input_string)
	{
		decompress(cur_str,pattern_finder_decompress);
	}
	return output_string;
}

/*function to decompress the string*/

string decompress(string cur_str,unordered_map<string,string> pattern_finder_decompress) 
{
	int str_sz=cur_str.size();
	string code_string;	//for first 2 bits
	//string code_string2;	//for first 4 bits
	string pattern_str;	//may have zzzz; xxxx;mmmm
	int index_ct;		//index count of cur_str thats read
	int i=0;
	string dic_index;	// get index from dictionary if there is some matchof packet 
	string out_str;
	unmatched_str;
	code_string=cur_str[i]+cur_str[i+1];
	if(pattern_finder_decompress.find(code_string)!=pattern_finder_decompress.end())
	{
		pattern_str=pattern_finder_decompress[code_string];
		index_ct=2;
	} 
	else 
	{
		code_string=code_string+cur_str[i+2] +cur_str[i+3];
		if(pattern_finder_decompress.find(code_string)!=pattern_finder_decompress.end()) {
			pattern_str=pattern_finder_decompress[code_string];
			index_ct=4;
		}
		else {
			cout <<"Debug::"<<endl;
		}
	}
	
	if(pattern_str.compare("zzzz")==0){
		out_str="00000000";
	}
	else if (pattern_str.compare("xxxx")==0){
		out_str=remaining_string(cur_str,index_ct);

	}
	else if (pattern_str.compare("mmmm")==0){
		dic_index= remaining_string(cur_str,index_ct);
		//TODO give dic_index to dictionary to find out_str
	}
	else if ( pattern_str.compare("mmxx")==0) {
		dic_index=get_dic_index(cur_str,index_ct);
		//TODO join unmatched string
		//unmatched_str=;
	}
		else if ( pattern_str.compare("zzzx")==0) {
		//dic_index=get_dic_index(cur_str,index_ct);
		//TODO join unmatched string
		//unmatched_str=;
	}

		else if ( pattern_str.compare("mmmx")==0) {
		dic_index=get_dic_index(cur_str,index_ct);
		//TODO join unmatched string
		//unmatched_str=;
	}


return out_str;
}


// function that gives remaining unmatched string
string remaining_string(string cur_str, int index)
	string out_str;
	for(int i=index;i<str_sz;i++)
	{
		out_str+=cur_str[i];
		
	}
return out_str;

}

//function that gives index of dictionary
string get_dic_index(string cur_str, int index){
	string out_str;	
	int max_size=log2(MAX_DICT_SIZE);
	for(int i=0;i<max_size;i++)
	{
		out_str+=cur_str[i+index];
		
	}
return out_str;

}

//function that converts binary string to decimal
int binary_str_to_decimal(string num) {

	int i = std::stoi("01000101", nullptr, 2)
	return i;
}

/*
* function to initialize code table for decompression
*/
unordered_map<string,string> initialize_decompress()
{
	unordered_map<string,string> pattern_finder_decompress;
	string code;
	string pattern;
	
	//first pattern code=00; pattern=zzzz;
	code.assign("00");
	pattern.assign("zzzz");
	pattern_finder_decompress.insert(make_pair(code,pattern));
	

	//second pattern code=01; pattern=xxxx;
	code.assign("01");
	pattern.assign("xxxx");
	pattern_finder_decompress.insert(make_pair(code,pattern));


	//third pattern code=10; pattern=mmmm;
	code.assign("10");
	pattern.assign("mmmm");
	pattern_finder_decompress.insert(make_pair(code,pattern));
	

	//fourth pattern code=1100; pattern=mmxx;
	code.assign("1100");
	pattern.assign("mmxx");
	pattern_finder_decompress.insert(make_pair(code,pattern));


	//fifth pattern code=1101; pattern=zzzx;
	code.assign("1101");
	pattern.assign("zzzx");
	pattern_finder_decompress.insert(make_pair(code,pattern));

	
	//sixth pattern code=1110; pattern=mmmx;
	code.assign("1110");
	pattern.assign("mmmx");
	pattern_finder_decompress.insert(make_pair(code,pattern));

	return pattern_finder_decompress;
}


