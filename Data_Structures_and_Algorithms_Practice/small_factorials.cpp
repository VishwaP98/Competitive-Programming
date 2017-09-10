#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>

int main(){
	int a = 0;
	scanf("%d", &a);
	for(int x=0;x<a;x++){
		int b = 0;
		int array[160];
		scanf("%d", &b);
		int new_b = b;
		int index = 0;
		for(int t = 0; t <= 158; t++){
			array[t] = 0;
		}
		while(b != 0){
			array[index] = b % 10;
			index++;
			b = b/ 10;
		}

		for(int y = 1; y <= new_b - 1; y++){
			for(int z = 0; z < index; z++){
				array[z] *= y;
			}

			for(int z = 0; z < index; z++){
				if(array[z] >= 10){
					int temp = array[z];
					array[z] = array[z] % 10;
					array[z + 1] += temp/10;
					if(z + 1 >= index){
						index = index + 1;
					}
				}
			}

		}
		if(new_b == -1){
			array[0] = 1;
			index = 1;
		}


		// Now just reverse the string
		std::reverse(array, array + index);

		for(int g = 0; g < index; g++){
			std::cout << array[g];
		}
		printf("\n");
	}
	return 0;
}
