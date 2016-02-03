
#include<iostream>
#include<vector>

using namespace std;
vector<string> decode_string(vector<string> input_string)
{
	vector<string> output_string;

	for(string cur_str : input_string)
	{
		decompress(cur_str);
	}
	return output_string;
} 
