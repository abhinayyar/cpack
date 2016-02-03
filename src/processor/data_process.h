/* header file for data process.cpp */
vector<string> input_processor(vector<string> input_to_process,unordered_map<string,code_table_glb*> pattern_finder,vector<pair<string,string> >& word_dict_glb);

string process_string_partial(string cur_str,string& unmatched);

bool dict_compare(string cur_str,string& index_of_dict,string& processed_str,vector<pair<string,string> > word_dict_glb,string& unmatched,unordered_map<string,code_table_glb*> pattern_finder);


int compare_str(string dict_str,string cur_str,string& local_unmatched,string& local_processed_str);

string get_binary(int index);

