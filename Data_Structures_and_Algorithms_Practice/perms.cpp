#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <vector>

void swap(char * str, int ind1, int ind2){
	char temp = str[ind1];
	str[ind1] = str[ind2];
	str[ind2] = temp;
}

// 0(n * n!) Time complexity and space complexity
void perms(char * str, int l, int r){
	if(l == r){
		printf("%s\n",str);
	}
	else{
		for(int j = l; j <= r; j++){
			swap(str,j,l);
			perms(str,l+1,r);
			swap(str,l,j);
		}
	}
}


int main(){
	 char str[] = "ABC";
	 int len = strlen(str);
	 perms(str, 0, len -1);
	 return 0;
}
