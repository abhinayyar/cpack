
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
#include<utility>
#include "data_process.h"
#include<cmath>
#include "../dict/code_table.h"

#define MAX_DICT_SIZE 32

using namespace std;


vector<string> decode_string(vector<string> input_string,unordered_map<string,code_table_glb*>& code_finder,vector<pair<string,string> > word_dict_glb)
{
	vector<string> output_string;
	for(string cur_str : input_string)
	{
		string output;
		output=decompress_val(cur_str,code_finder,word_dict_glb);
		output_string.push_back(output);
	}
	return output_string;
}

/* function to decode each */

string process_string_pattern(string pattern_str,string cur_str,int index,vector<pair<string,string> > word_dict_glb)
{
	string dict_index;
	if(pattern_str.compare("zzzz")==0)
	{
		return "00000000";
	}
	else if (pattern_str.compare("xxxx")==0)
	{
		return cur_str.substr(index);

	}
	else if (pattern_str.compare("mmmm")==0)
	{

		dict_index= cur_str.substr(index);
		return search_dict(dict_index,word_dict_glb);	
	}
	else if ( pattern_str.compare("mmxx")==0) 
	{
		string rem_str=cur_str.substr(index);
		dict_index=rem_str.substr(0,log2(MAX_DICT_SIZE));
		
		return search_dict(dict_index,word_dict_glb).substr(0,4)+rem_str.substr(log2(MAX_DICT_SIZE));
	}
	else if ( pattern_str.compare("zzzx")==0) 
	{
		return "000000"+cur_str.substr(index);
	}
	else if(pattern_str.compare("mmmx")==0)
	{
		string rem_str=cur_str.substr(index);
		dict_index=rem_str.substr(0,log2(MAX_DICT_SIZE));
		
		return search_dict(dict_index,word_dict_glb).substr(0,6)+rem_str.substr(log2(MAX_DICT_SIZE));
	
	}
	else
	{
		cout<<"Debug : Not correctly decoded 2\n";
		return " ";	
	}
			
		
}


/* functio to search word in dict */

string search_dict(string dict_index,vector<pair<string,string> > word_dict_glb)
{
	for(pair<string,string> p : word_dict_glb)
	{
		if(dict_index.compare(p.second)==0) return p.first;
	}

	cout<<" Debug  : Not correctly decoded 3\n";
	return " ";
}


/*function to decompress the string*/

string decompress_val(string cur_str,unordered_map<string,code_table_glb*> code_finder,vector<pair<string,string> > word_dict_glb) 
{
	int str_sz=cur_str.size();

	string primcheck=cur_str.substr(0,2);	
	string pattern_str;	//may have zzzz; xxxx;mmmm

	if(code_finder.find(primcheck)!=code_finder.end())
	{
		// success  zzzz xxxx mmmm
		pattern_str=code_finder[primcheck]->pattern;
		return process_string_pattern(pattern_str,cur_str,2,word_dict_glb);
	}
	else
	{
		primcheck.assign(cur_str.substr(0,4));
		if(code_finder.find(primcheck)!=code_finder.end())
		{
			// success  mmxx zzzx mmmx
			pattern_str=code_finder[primcheck]->pattern;
			return process_string_pattern(pattern_str,cur_str,4,word_dict_glb);
		}
		
		
	}
	
	cout<<"Debug : Wrong output \n";
	return " ";	

}



