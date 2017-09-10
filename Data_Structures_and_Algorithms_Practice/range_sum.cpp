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
	long long int array[a];
	std::vector<long long int> rev_array;
	for(long long int x=a-1; x>=0;x--){
		long long int b = 0L;
		scanf("%lld",&b);
		array[x] = b;
	}

	for(int x = 0; x < a;x++){
		if(x == 0){5
			rev_array.push_back(array[x]);
		}
		else{
			rev_array.push_back(array[x] + rev_array[x - 1]);
		}
	}
	int c = 0;
	scanf("%d", &c);
	for(int x = 0; x < c; x++){
		int d = 0;
		scanf("%d", &d);
		long long int g = 0L;
		if(d == 1){
			long long int e, f = 0L;
			scanf("%lld %lld", &e, &f);
			a - f - 1 < 0 ? g = 0 : g = rev_array[a - f - 1];
			printf("%lld\n", rev_array[a - e] - g);
		}
		else{
			scanf("%lld",&g);
			rev_array.push_back(g + rev_array[a - 1]);
			a = a + 1;
		}
	}
	return 0;
}
