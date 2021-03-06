#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const int MOD = 1000000007;

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
	int to, cost;
};

int main() {
	int n;
	cin >> n;
	cout << 0 << endl;
	string z;
	cin >> z;
	if (z == "Vacant") {
		return 0;
	}
	int head = -1;
	int tail = n;
	int tmp = 0;
	bool flag = true;
	/*
	if (n < 20) {
	FOR(i, 1, n) {
	cout << i << endl;
	string s;
	cin >> s;
	if (s == "Vacant") {
	return 0;
	}
	}
	}
	*/
	while (1) {
		int mid = (head + tail) / 2;
		cout << mid << endl;
		string s;
		cin >> s;
		if (s == "Vacant") {
			return 0;
		}
		if (s == z) {
			if (abs(tmp - mid) % 2 == 0) {
				if (flag) {
					head = mid;
				}
				else {
					tail = mid + 1;
				}
			}
			else {
				if (flag) {
					tail = mid + 1;
					flag = false;
				}
				else {
					head = mid;
					flag = true;
				}
			}
		}
		else {
			if (abs(tmp - mid) % 2 == 0) {
				if (flag) {
					tail = mid + 1;
					flag = false;
				}
				else {
					head = mid;
					flag = true;
				}
			}
			else {
				if (flag) {
					head = mid;
				}
				else {
					tail = mid + 1;
				}
			}
		}
		tmp = mid;
		z = s;
	}
}

