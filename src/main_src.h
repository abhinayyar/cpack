/* ************************** */
/* header file for main func */
/* *************************** */
unordered_map<string,code_table_glb*> initialize(unordered_map<string,code_table_glb*>& code_finder);

void display_results(vector<string> input,vector<string> output,int& input_count,int& output_cont);

void compare_results(vector<string> input,vector<string> output,vector<string> compressed);


void print_dict(vector<pair<string,string> > word_dict_glb);
