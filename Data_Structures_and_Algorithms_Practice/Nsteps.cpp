#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <stack>

int main(){
	int a;
	scanf("%d", &a);
	for(int x=0;x<a;x++){
		int b,c = 0;
		scanf("%d %d", &b, &c);
		if(b != c && (b-2)!=c){
			printf("%s\n","No Number");
		}
		else if(b == c){
			if(b % 2 == 0){
				printf("%d\n",b*2);
			}
			else{
				printf("%d\n",b*2 - 1);
			}
		}
		else if(b - 2 == c){
			if(b%2 == 0){
				printf("%d\n",b+c);
			}
			else if (b > 2){
				printf("%d\n",b + (c-1));
			}
			else{
				printf("%d\n",0);
			}
		}
	}
	return 0;
}
