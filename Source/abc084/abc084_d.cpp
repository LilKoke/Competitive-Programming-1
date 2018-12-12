/*
 * test.cpp
 *
 *  Created on: 2018/01/10
 *      Author: joi
 */




#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

// int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
// int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){
	int q;
	cin >> q;
	int d[100010];
	for(int i = 1; i < 100010; i += 2){
		if(i == 1){
			d[1] = 0;
		}else{
			int flag = 1;
			for(int j = 2; j < sqrt(i) + 1; j++){
				if(i % j == 0) flag = 0;
			}
			for(int j = 2; j < sqrt((i + 1) / 2) + 1; j++){
				if((i + 1) / 2 == 2){
					break;
				}
				if(((i + 1) / 2) % j == 0) flag = 0;
			}
			d[i] = d[i - 2] + flag;
		}
	}
	REP(i, q){
		int l, r;
		cin >> l >> r;
		if(l == 1) l = 3;
		cout << d[r] - d[l - 2] << endl;
	}
}

