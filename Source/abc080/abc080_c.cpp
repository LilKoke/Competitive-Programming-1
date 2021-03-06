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
	int n;
	cin >> n;
	int f[101][10];
	REP(i, n){
		REP(j, 10){
			cin >> f[i][j];
		}
	}
	int p[101][11];
	REP(i, n){
		REP(j, 11){
			cin >> p[i][j];
		}
	}
	int ans = -1 * 1 << 31;
	for(int t = 1; t < 1 << 10; t++){
		bitset<10> bs = t;
		int sum = 0;
		REP(i, n){
			int cnt = 0;
			REP(j, 10){
				if(bs[j] && f[i][j]) cnt++;
			}
			sum += p[i][cnt];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

