#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


bool is_palin_perm(char * str){
		int check = 0;
		int index = 0; int val = 0;
		while(str[index] != '\0'){
			if(str[index] >= 'A' && str[index] <= 'Z'){
					val = int(str[index]) - int('A');
			}
			else if(str[index] >= 'a' && str[index] <= 'z'){
					val = int(str[index]) - int('a');
			}
			else{
				return false;
			}
			// now just set the val th bit in check
			if((check & (1 << val)) == 0){
				check = (check | (1 << val));
			}
			else{
				check = (check & (~(1 << val)));
			}
			index++;
		}


		return (check==0 || (check - 1 & check) == 0);
}

int main(){
	printf("%d\n",is_palin_perm("accarer"));
	printf("%d\n",is_palin_perm("dad"));
	printf("%d\n",is_palin_perm("daad"));
	printf("%d\n",is_palin_perm("1"));
	printf("%d\n",is_palin_perm("hi1"));
	printf("%d\n",is_palin_perm("h"));
	return 0;
}
