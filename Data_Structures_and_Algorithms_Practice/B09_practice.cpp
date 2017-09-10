#include<unistd.h>
#include<stdio.h>

int main(){
	int i;
	int child;
	for(i = 0; i < 2; i++){
		child = fork();
		if(child == 0){
			printf("Round %d\n",i);
		}
	}
	return 0;
}
