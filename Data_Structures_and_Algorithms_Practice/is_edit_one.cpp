#include <stdio.h>
#include <string>
#include <math.h>
#include <stdlib.h>


bool is_edit_one(std::string s1, std::string s2){
	char bool_val = 'f';
	int index = 0;
	int index2 = 0;
	if(abs(s1.length() - s2.length()) > 1){
		return false;
	}
	else if(abs(s1.length() - s2.length()) <= 1){
		while(index < s1.length() && index2 < s2.length()){
			if(s1.at(index) != s2.at(index2)){
				if(s1.length() < s2.length()){
					index--;
				}
				else if(s1.length() > s2.length()){
					index2--;
				}
				if(bool_val == 't'){
					return false;
				}
				bool_val = 't';
			}
			index++;
			index2++;
		}

		return true;
	}
}

int main(){
	printf("%d\n",is_edit_one("place","pace"));
	printf("%d\n",is_edit_one("place","pce"));
	printf("%d\n",is_edit_one("cool","co"));
	printf("%d\n",is_edit_one("","h"));
	printf("%d\n",is_edit_one("plce","place"));
	printf("%d\n",is_edit_one("","tw"));
	printf("%d\n",is_edit_one("pale","bake"));
	printf("%d\n",is_edit_one("pale","pale"));
	printf("%d\n",is_edit_one("",""));
	return 0;
}
