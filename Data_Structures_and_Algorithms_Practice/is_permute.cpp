#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <unordered_map>


bool is_permute(const char * char1, const char * char2){
		std::unordered_map<char,int> characters;
		int index = 0;
		while(char2[index] != '\0'){
			std::unordered_map<char,int>::const_iterator got = characters.find(char2[index]);
			if(got != characters.end()){
				characters.at(char2[index]) += 1;
			}
			else{
				characters.insert({char2[index],1});
			}
			index++;
		}

		int index_first = 0;
		while(char1[index_first] != '\0'){
			std::unordered_map<char,int>::const_iterator got = characters.find(char1[index_first]);
			if(got != characters.end() && characters.at(char1[index_first]) > 0){
				characters.at(char1[index_first]) -= 1;
			}
			else{
				return false;
			}
			index_first++;
		}
		return (index_first == index);
}


int main(){
	char a[10];
	char b[10];
	scanf("%s %s",a,b);
	printf("%d",is_permute(a,b));
	printf("%d",is_permute("dog ","god"));
	return 0;
}
