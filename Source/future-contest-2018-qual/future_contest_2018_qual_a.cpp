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
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
static const int INF = 1000010000;
static const int MOD = 100000;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
	int u, v;
	ll cost;
};

int a[100][100];

void deca(int x, int y, int h) {

	int left = max(0, y - h + 1);
	int right = min(99, y + h - 1);

	FOR(i, left, right + 1) {
		int mid = h - abs(y - i);
		int j = 0;
		while (mid > 0) {
			if (x - j < 0 && x + j > 99) break;
			if (x - j >= 0) a[x - j][i] -= mid;
			if (x + j <= 99 && j != 0) a[x + j][i] -= mid;
			mid--; j++;
		}
	}
}

int main() {

	clock_t start = clock();

	const int n = 100;
	REP(i, n) REP(j, n) cin >> a[i][j];

	int x[1010], y[1010], h[1010];
	int cnt = 0;

	while ((clock() - start) < 5900000) {
		REP(hoge, 10) {
			int mx, my, mh = 0;
			REP(i, n) REP(j, n) {
				if (a[i][j] > mh) {
					mx = i; my = j; mh = a[i][j];
				}
			}
			if (mh <= 0) break;
			else {
				deca(mx, my, min(mh, 100));
				x[cnt] = mx; y[cnt] = my; h[cnt] = min(mh, 100);
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	REP(i, cnt) cout << x[i] << " " << y[i] << " " << h[i] << endl;

}

