#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>

int find_len(std::string str){
	int total_len = 0;
	std::stringstream s;
	for(size_t x = 0; x < str.length(); x++){
		int repeat = 1;
		if(str[x+1] == str[x]){
			repeat++;
		}
		else{
			s << repeat;
			std::string num;
			s >> num;
			total_len += (1 + num.length());
			s.clear();
		}
	}
	return total_len;
}

std::string str_compress(std::string str){
	int comp_len = find_len(str);
	std::stringstream s;
	size_t original_len = str.length();
	if(comp_len >= original_len){
		return str;
	}
	else{
		std::string new_str;
		std::string num;
		new_str.reserve(comp_len);
		int repeat = 1;
		for(size_t x = 1; x < original_len; x++){
			if(str[x] == str[x - 1]){
				repeat++;
			}
			else{
				new_str += str[x-1];
				s << repeat;
				s >> num;
				new_str += num;
				s.clear();
				repeat = 1;
			}
		}
		s << repeat;
		s >> num;
		new_str += (str[original_len - 1]);
		new_str += num;
		s.clear();
		return new_str;
	}

}


int main(){
	printf("%s\n",str_compress("vishwa").c_str());
	printf("%s\n",str_compress("viiiiit").c_str());
	printf("%s\n",str_compress("vvviiissshhwa").c_str());
}
