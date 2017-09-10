#include <stdio.h>
#include <unordered_map>

int main(){
	int a = 0;
	scanf("%d",&a);
	for(int x= 0 ;x < a;x++){
		int b = 0;
		scanf("%d",&b);
		std::unordered_map<char word[],int> hash_table;
		for(int y = 0; y < b; y++){
			char c[3];
			char m;
			char string[16];
			string[15] = '\0';
			scanf(" %3c",c);
			scanf(" %c",&m);
			scanf(" %s",string);
			int index = 0;
			int key = 0;
			while(string[index] != '\0'){
				key += (int(string[index]) * (index + 1));
				index++;
			}
			key *= 19;
			key = key % 101;
			if(c == "ADD"){
				hash_table.insert(std::make_pair<string,key>);
			}
			else{
				hash_table.erase(string);
			}
		}

		//
	}
	return 0;
}
