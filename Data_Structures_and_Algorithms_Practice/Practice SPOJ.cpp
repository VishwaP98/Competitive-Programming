#include <iostream>
#include <stdio.h>

int main() {
	int a,b,c = 0;
	scanf("%d", &a);
	 for(int x=0;x<a;x++){
	 	scanf("%d %d", &b, &c);
	 	if(b == 2){
	 		printf("%d\n",2);
	 	}
	 	else if(b == 3){
	 		printf("%d\n%d\n",2,3);
	 	}
	 	else if(b < 2 && b < 3){
	 		printf("%d\n%d\n",2,3);
	 	}
	 	
 		int n = 5;
	 	while(n <= c){
	 		if(n + 2 <= c){
		 		printf("%d\n%d\n", n, n+2);
	 		}
	 		else{
		 		printf("%d\n",n);
	 		}
	 		n+=6;
	 	}
	 	
	 	if(x + 1 != a){
	 		printf("\n");
	 	}
	 }
	return 0;
}
