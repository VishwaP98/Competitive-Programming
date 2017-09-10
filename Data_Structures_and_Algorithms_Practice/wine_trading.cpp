#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <vector>

int main(){
	int a = 0;
	scanf("%d",&a);
	while(a != 0){
		long long int tol = 0;
		long long int total_mov = 0;
		scanf("%lld",&tol);
		for(int x = 1; x < a; x++){
			int b = 0;
			scanf("%d", &b);
			total_mov += abs(tol);
			tol += (b);
		}
		printf("%lld\n",total_mov);
		scanf("%d",&a);
	}

	return 0;
}
