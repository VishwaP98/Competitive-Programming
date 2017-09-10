#include <stdio.h>

void update(long long int x, long long int BIT[], int size, long long int value){
	for(; x <= size; x+=(x&-x)){
		BIT[x - 1] += value;
	}
}

long long int query(long long int x, long long int BIT[]){
	long long int sum = 0L;
	for(;x>=1;x-=(x&-x)){
		sum += BIT[x-1];
	}
	return sum;
}

int main(){
	int a = 0;
	scanf("%d", &a);
	long long int BIT[a];
	for(int x = 0; x < a;x++){
		BIT[x] = 0L;
	}
	for(int x = 1 ; x <= a; x++){
		long long int b = 0L;
		scanf("%lld",&b);
		update(x,BIT,a,b);
	}


	int c = 0;
	scanf("%d",&c);
	for(int x = 0; x < c; x++){
		char b = 'a';
		long long int d,e = 0L;
		scanf(" %c %lld %lld", &b, &d, &e);
		if(b == 'q'){
			printf("%lld\n",query(e,BIT) - query(d - 1,BIT));
		}
		else{
			update(d,BIT,a,e);
		}
	}
	return 0;
}
