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
	for(int x = 0; x < a; x++){
		int b = 0;
		scanf("%d", &b);
		std::vector<std::pair<int, int> > array;
		for(int y = 0; y < b; y++){
			int c = 0;
			scanf("%d",&c);
			array.push_back(std::make_pair(c,0));
		}
		for(int y = 0; y < b; y++){
			int d = 0;
			scanf("%d",&d);
			array[y].second = d;
		}
		std::sort(array.begin(), array.end());
		// The array is now sorted



		// Must start at the second last index of the array because there will be
		// no one that is taller than the person very last in the array
		int index = b - 2;
		while(index >= 0){
			int temp_index = index;
			while(temp_index < b && array[temp_index].second != 0){
				std::pair<int, int> temp;
				temp = array[temp_index];
				array[temp_index] = array[temp_index + 1];
				array[temp_index + 1] = temp;
				array[temp_index + 1].second = array[temp_index + 1].second - 1;
				temp_index = temp_index + 1;
			}
			index = index - 1;
		}

		printf("%d",array[0].first);
		for(int y = 1; y < b; y++){
			printf(" %d",array[y].first);
		}
		printf("\n");
	}

	return 0;
}
