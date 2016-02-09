/* header for file parser */
#ifndef _FILE_READER_H_
#define _FILE_READER_H_

#define TIME 0
#define SM_ID 1
#define DATA_SIZE 2
#define DATA 3
#define MAX_TABLE_ENT 4

vector<string> get_file_input(int index,int& data_size);

int open_file(string file_name);

#endif
