#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <stack>

int main(){
	int a;
	scanf("%d", &a);
	for(int x=0;x<a;x++){
		char string[400];
		scanf("%399s",string);
		std::stack<char> exp;
		int index = 0;
		char val = string[index];
		while(val != '\0'){
			if(val == ')' && !exp.empty()){
				char popped = exp.top();
				exp.pop();
				printf("%c",popped);
			}
			else if(val == '+' || val == '*' || val == '-' || val == '/' || val == '^'){
				exp.push(val);
			}
			else if(val >= 97 && val <= 122){
				printf("%c",val);
			}
			index++;
			val = string[index];
		}
		printf("\n");

	}
	return 0;
}
