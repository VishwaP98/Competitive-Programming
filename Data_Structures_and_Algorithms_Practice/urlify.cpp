#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char * urlify(char * str, int len){
	int index = 0; int spaces = 0;
	while(index < len){
			if(str[index] == ' '){
				spaces++;
			}
			index++;
	}
	int new_len = len + (spaces * 2) - 1;
	len = len - 1;
	if(new_len == len){
			return str;
	}
	else{
		while(len >= 0){
			if(str[len] == ' '){
					str[new_len] = '0';
					str[new_len - 1] = '2';
					str[new_len - 2] = '%';
					new_len = new_len - 2;
			}
			else{
				str[new_len] = str[len];
			}
			len--;
			new_len--;
		}
	}
	return str;

}

int main(){
	char * a = (char *) malloc(19);
	strcpy(a,"vishwa is cool    ");
	a = urlify(a, 14);
	printf("%s",a);
	return 0;
}
