/* file for processing data input */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
#include<utility>
#include<cmath>

#include "../dict/code_table.h"
#include "../processor/data_process.h"

using namespace std;

#define BIT_WORD 2
#define PATTERN_SIZE 4
#define MAX_DICT_SIZE 32

vector<string> input_processor(vector<string> input_to_process,unordered_map<string,code_table_glb*> pattern_finder,vector<pair<string,string> >& word_dict_glb)
{
	vector<string> output_to_get;

	
	for(string cur_str : input_to_process)
	{
		cout<<"=============================\n";
		cout<<cur_str<<"\n";
		string unmatched,output_string,processed_string;
		string index_of_dict;
		/* process_string_partial will convert input string to only zzzx || zzzz format
		* if none of these are found -> return empty string
		*/
		processed_string=process_string_partial(cur_str,unmatched);
		if((processed_string.compare("zzzz")==0)||(processed_string.compare("zzzx")==0))
		{
			/* patter found in code table , need not to look for dict
			*  code + unmatched_part  
			*/
			cout<<"Type  : (zzzz or zzzx) "<<"\t"<<cur_str<<"\t"<<"Actual: \t"<<processed_string<<"\n";
			if(pattern_finder.find(processed_string)!=pattern_finder.end()) 
			output_string=pattern_finder[processed_string]->code+unmatched;			 
		}
		else
		{
			bool ret=dict_compare(cur_str,index_of_dict,processed_string,word_dict_glb,unmatched,pattern_finder);
			if(ret)
			{
				/* procesed string will contain all values of type mm xx zz *
				 code + index + unmached */
				
				if(pattern_finder.find(processed_string)!=pattern_finder.end()) 
				output_string=pattern_finder[processed_string]->code + index_of_dict + unmatched;
				cout<<"True section \n";	
			}	
			else
			{
				
				if(pattern_finder.find(processed_string)!=pattern_finder.end()) 
				output_string=pattern_finder[processed_string]->code + unmatched;
				/* update the same in dict */
				int index=word_dict_glb.size();
				/* TODO : lock implementation for multi word insert */
				if(index==MAX_DICT_SIZE)
				{
					word_dict_glb.erase(word_dict_glb.begin());
				}
				word_dict_glb.push_back(make_pair(cur_str,get_binary(index)));
				cout<<"False section\n"; 
			}
		}
		output_to_get.push_back(output_string);
	}
		

	return output_to_get;	
}
/* function to convert index to binary */
string get_binary(int index)
{
	string output;
	int max_size=log2(MAX_DICT_SIZE);
	int a=index;	
	while(max_size>0)
	{
		output=to_string(index%2)+output;
		index=index/2;
		max_size--;
	}
	cout<<"---------------------------\n";
	cout<<a<<"\t"<<output<<"\n";
	return output;
}
/* function to return string in code pattern format
*/
string process_string_partial(string cur_str,string& unmatched)
{
	string processed_string;
	int str_sz=cur_str.size();
	for(int i=0;i<cur_str.size()-BIT_WORD;i+=BIT_WORD)
	{
		if(cur_str[i]=='0' && cur_str[i+1]=='0')
		processed_string+="z";
	}

	if(cur_str[str_sz-2]=='0' && cur_str[str_sz-1]=='0')
	processed_string+="z";
	else
	{
		processed_string+="x";	
		unmatched.assign(cur_str.substr(str_sz-2));
	}	
	return processed_string;
}

/* function to compare glb dictonary in condition word is not found in code table
*/

bool dict_compare(string cur_str,string& index_of_dict,string& processed_str,vector<pair<string,string> > word_dict_glb,string& unmatched,unordered_map<string,code_table_glb*> pattern_finder)
{
	
	int val=0,max_val=0,max_index=-1;
	
	for(int i=0;i<word_dict_glb.size();i++)
	{
		
		string local_unmatched,local_processed_str;
		
		string dict_str=word_dict_glb[i].first;
		cout<<"Dict "<<word_dict_glb[i].first<<"\t";
		val=compare_str(dict_str,cur_str,local_unmatched,local_processed_str);
		if(val>max_val)
		{
			max_val=val;
			max_index=i;	
			unmatched.assign(local_unmatched);
			index_of_dict.assign(word_dict_glb[i].second);
			processed_str.assign(local_processed_str);
			cout<<"Actual one "<<cur_str<<"\t"<<processed_str<<"\t"<<unmatched<<"\n";
		}			
	}
	
	// now we need to check for match

	if(max_val==0 || max_val==1)
	{
		cout<<"val erro \n";
		processed_str.assign("xxxx");
		unmatched.assign(cur_str);
		return false;
	}
	
	if(pattern_finder.find(processed_str)==pattern_finder.end())
	{
		cout<<"pattern errroi "<<processed_str<<"\n";
		 return false;	
	}
	else				
	return true;
}

/* function to compare two indiv strings
*/

int compare_str(string dict_str,string cur_str,string& local_unmatched,string& local_processed_str)
{
	int match_count=0;

	cout<<"\n"<<"com "<<dict_str<<"\t"<<cur_str<<"\n";	
	bool is_first_unmatch=true;
	for(int i=0;i<=dict_str.size()-BIT_WORD;i+=BIT_WORD)
	{
		if(dict_str[i]==cur_str[i] && dict_str[i+1]== cur_str[i+1]&& is_first_unmatch==true)
		{
			local_processed_str+="m";
			match_count++;
		}
		else
		{
			local_processed_str+="x";
			is_first_unmatch=false;
			local_unmatched.assign(cur_str.substr(i));
			break;
		}		
	}

	//cout<<"pre "<<local_processed_str<<"\t"<<local_processed_str.size()<<"\n";	
	while(local_processed_str.size()<PATTERN_SIZE)
	{
		//cout<<local_processed_str.size()<<"\t";
		local_processed_str+="x";		
	}

	cout<<"\n M :"<<match_count<<"\n";	
	return match_count;		
}
