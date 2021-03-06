#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const int MOD = 100000;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
	int u, v;
	ll cost;
};

int main() {
	int h, w;
	char mas[50][50];
	cin >> h >> w;
	int cntw = 0;
	REP(i, h) {
		REP(j, w) {
			cin >> mas[i][j];
			if (mas[i][j] == '.') cntw++;
		}
	}
	int d[50][50];
	REP(i, 50) REP(j, 50) d[i][j] = INF;

	queue<P> que;
	que.push(P(0, 0));
	d[0][0] = 1;

	while (!que.empty()) {
		P p = que.front();
		que.pop();
		if (p.first == h - 1 && p.second == w - 1) break;
		REP(i, 4) {
			int nx = p.first + dx[i]; int ny = p.second + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w && mas[nx][ny] == '.' && d[nx][ny] == INF) {
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	if (d[h - 1][w - 1] == INF) cout << -1 << endl;
	else cout << cntw - d[h - 1][w - 1] << endl;
}
