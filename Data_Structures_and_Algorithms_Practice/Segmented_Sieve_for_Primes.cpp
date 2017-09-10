#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

int main(){
	int cases = 0;
	scanf("%d",&cases);
	for(int x=0;x<cases;x++){
		long long int start, end = 0L;
		scanf("%lld %lld", &start, &end);
		bool a[end - start + 1];
		for(int j = 0; j < sizeof(a); j++){
			a[j] = false;
		}
		for(long long int y = 2L; y * y <= end; y++){
			std::cout << y << std::endl;
			long long int c = (start/y);
			if(c == 0 || c == 1){
				c = y * 2;
			}
			else{
				c = c * y;
			}

			while(c <= end){
				if(c >= start and c <= end){
					a[c - start] = true;
				}
				c = c + y;
			}
		}

		for(long long int z = 0L; z < sizeof(a); z++){
			if((a[z] == false) and (z + start != 1)){
				std::cout << z << " Hello " << std::endl;
				printf("%lld\n", z + start);
			}
		}
		if(x + 1 < cases){
			printf("\n");
		}
	}
	return 0;
}
