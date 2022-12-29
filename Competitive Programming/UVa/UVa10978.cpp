#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(){
	int n;

	while(scanf("%d", &n) == 1 && n){
		string cards[n];
		string id, card;
		int Flag = 0;
		for(int i=0; i<n; i++){
			cin >> id >> card;
			int len = card.length();
			while(len){
				if(cards[Flag] == "")
					len--;
				Flag++;
				if(Flag >= n) Flag = 0;
			}
			//Flag += len;
			/*if(Flag >= n){
				Flag = Flag % n;
			}*/

			cards[(Flag-1+n)%n] = id;
		}
		for(int i = 0; i < n; i++) {
            if(i)   putchar(' ');
            cout <<cards[i];
        	}
		puts("");
	}
}