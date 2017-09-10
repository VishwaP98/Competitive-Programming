#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <vector>

int main(){
	int a,b,c = 0;
	scanf("%d %d %d",&a,&b,&c);
	while(a != 0 || b != 0 || c != 0){
		if(c - b == b - a){
			printf("AP %d\n",c + (c-b));
		}
		else if(c/b == b/a){
			printf("GP %d\n",c * (c/b));
		}
		scanf("%d %d %d",&a,&b,&c);
	}

	return 0;
}
