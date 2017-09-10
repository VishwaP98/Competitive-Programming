#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const int x = 3;
const int t = 3;
void print(int array[x][x]){
	for(int y =0; y < x; y++){
		for(int z = 0; z < x; z++){
			printf("%d ",array[y][z]);
		}
		printf("\n");
	}
}
bool rot_matrix(int array[x][t]){
	if(x != t){
		return false;
	}
	for(int i=0; i < x/2; i++){
		printf("bye\n");
		int start = i;
		int end = x - i - 1;
		for(int z = start; z < end; z++){
			printf("hello\n");
			int offset = (z - start);
			if(i == 2){
				printf("%d\n ",array[start][start + offset]);
			}
			int temp = array[end - offset][start];
			array[end - offset][start] = array[end][end - offset];
			array[end][end - offset] = array[start + offset][end];
			array[start + offset][end] = array[start][start + offset];
			array[start][start + offset] = temp;
			if(i == 2){
				printf("%d\n ",array[start][start + offset]);
			}
 		}
	}
	return true;
}

int main(){
	int array[3][3] = {
											{1,2,3},
											{4,5,6},
											{7,8,9},
										};
	rot_matrix(array);
	print(array);

}
