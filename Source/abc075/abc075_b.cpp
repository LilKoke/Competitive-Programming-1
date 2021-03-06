/*
 * test.cpp
 *
 *  Created on: 2018/01/10
 *      Author: joi
 */




#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){
	int h, w;
	cin >> h >> w;
	char s[51][51];
	REP(i, h){
		cin >> s[i];
	}
	REP(i, h){
		REP(j, w){
			if(s[i][j] == '#') continue;
			int cnt = 0;
			REP(k, 8){
				int nx = i + dx[k];
				int ny = j + dy[k];
				if(s[nx][ny] == '#') cnt++;
			}
			s[i][j] = (char)((int)'0' + cnt);
		}
	}
	REP(i, h){
		cout << s[i] << endl;
	}
}

