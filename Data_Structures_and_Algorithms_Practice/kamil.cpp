#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <vector>


int main(){
	for(int x = 0; x < 10; x++){
		char input;
		int total = 1;
		scanf("%c",&input);
		while(input != '\n'){
			if(input == 'D' || input == 'L' || input == 'F' || input == 'T'){
				total *= 2;
			}
			scanf("%c",&input);
		}
		printf("%d\n",total);
	}

	return 0;
}
