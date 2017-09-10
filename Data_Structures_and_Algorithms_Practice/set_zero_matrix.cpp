#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const int m = 3;
const int n = 4;

void print(int array[m][n]){
	for(int y =0; y < m; y++){
		for(int z = 0; z < n; z++){
			printf("%d ",array[y][z]);
		}
		printf("\n");
	}
}
void set_zero_matrix(int array[m][n]){
		char top_row = 'f';
		char left_col = 'f';
		for(int x=0;x<n;x++){
			if(array[0][x] == 0){
				top_row = 't';
			}
		}
		for(int x=0;x<m;x++){
			if(array[x][0] == 0){
				left_col = 't';
			}
		}
		for(int x=1; x < m; x++){
			for(int y=1;y < n;y++){
				if(array[x][y] == 0){
					array[0][y] = 0;
					array[x][0] = 0;
				}
			}
		}

		for(int x = 1; x < n;x++){
			if(array[0][x] == 0){
				for(int y = 1; y < m;y++){
					array[y][x] = 0;
				}
			}
		}

		for(int x = 1; x < m; x++){
			if(array[x][0] == 0){
				for(int y = 1; y < n; y++){
					array[x][y] = 0;
				}
			}
		}
		if(top_row == 't'){
			for(int x=0;x<n;x++){
				array[0][x] = 0;
			}
		}
		if(left_col == 't'){
			for(int x=0;x<m;x++){
				array[x][0] = 0;
			}
		}

}

int main(){
	int array[3][4] = {
											{1,0,4,0},
											{5,6,7,8},
											{0,9,10,11}
										};
	set_zero_matrix(array);
	print(array);

}

//{1,2,3,4,5,6,7},
//{8,9,10,11,12,13,14},
//{15,16,17,18,19,20,21},
//{22,23,24,25,26,27,28},
//{29,30,31,32,33,34,35},
//{36,37,38,39,40,41,42},
//{43,44,45,46,47,48,49}
