#include <stdio.h>
#include <vector>
#include <math.h>

int main(){
	int a;
	scanf("%d", &a);
	for(int x = 0; x < a; x++){
		int b = 0;
		scanf("%d",&b);		// Size of the main vector - # of towns on map
		std::vector< std::vector<int> > graph(b);
		// Graph initialization is done
		for(int y = 0; y < b; y++){
			for(int z = 0; z < b; z++){
				int c = 0;
				scanf("%d",&c);
				graph[y].push_back(c);
			}
		}

		// Now let's dive into finding the neighbouring towns
		for(int y = 0; y < b; y++){
			for(int z = y+1; z < b; z++){
				if(y != z){
					int vt = 1;
					for(int t = 0; t < b; t++){
						if(t != y && t!= z){
							if((graph[y][z] == graph[y][t] + graph[t][z])){
									vt = 0;
									break;
							}
						}
					}
					if(vt == 1){
						printf("%d %d\n",y+1,z+1);
					}
				}
			}
		}

		// Once checking for pairs is done

	}
	return 0;
}
