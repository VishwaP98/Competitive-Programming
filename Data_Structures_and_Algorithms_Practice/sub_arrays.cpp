#include <stdio.h>
#include <deque>

int main(){
	int a = 0;
	scanf("%d", &a);
	std::deque<int> queue;
	int array[a];
	for(int x = 0;x < a;x++){
		int b = 0;
		scanf("%d",&b);
		array[x] = b;
	}

	int slide_factor = 0;
	scanf("%d",&slide_factor);
	for(int x = 0; x < a;x++){
		while(!queue.empty() && queue.back() < array[x]){
			queue.pop_back();
		}
		queue.push_back(array[x]);
		if(x >= slide_factor - 1 && x < a - 1){
			printf("%d ", queue.at(0));
			if(queue.at(0) == array[x - slide_factor + 1]){
				queue.pop_front();
			}
		}

	}
	printf("%d",queue.at(0));
	return 0;
}
