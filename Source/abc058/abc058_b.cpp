#include <iostream>
#include <string>

using namespace std;

int main() {
	string o;
	string e;
	cin >> o;
	cin >> e;
	int len = (int)e.size();
	int i;
	for (i = 0; i < len; i++) {
		cout << o.substr(i, 1) + e.substr(i, 1);
	}
	if ((int)o.size() - (int)e.size()) {
		cout << o.substr(i , 1);
	}
	cout << "\n";
	cin >> e;
	return 0;
}
