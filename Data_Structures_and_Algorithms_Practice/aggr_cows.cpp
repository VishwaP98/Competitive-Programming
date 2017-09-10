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
	for(int x =0 ; x<a;x++){
		int n, c = 0;
		scanf("%d %d", &n, &c);
		long long int array[n];
		for(int y = 0; y < n ; y++){
			long long int val = 0L;
			scanf("%lld",&val);
			array[y] = val;
		}

		// Now sort the array
		std::sort(array, array + n);

		int placed = 0;
		long long int low = array[0];
		long long int high = (array[n-1])/(c - 1);
		long long int dis_constraint = 0L;
		int rec_placed_index = 0;
		long long int original_constraint = dis_constraint;

		while(low < high){
			dis_constraint = low + (high - low)/2;
			placed++;
			// Now traverse through the array by placing the cows
			for(int z = 1; z < n; z++){
				if((array[z] - array[rec_placed_index]) >= dis_constraint){
					placed++;
					rec_placed_index = z;
				}
			}

			if(placed < c){
				high = dis_constraint;
			}
			else{
				low = dis_constraint + 1;
				original_constraint = dis_constraint;
			}

			rec_placed_index = 0;
			placed = 0;
		}
		printf("%lld\n",original_constraint);
	}
	return 0;
}
