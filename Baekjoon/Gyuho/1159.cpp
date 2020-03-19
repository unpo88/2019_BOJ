#include <iostream>
#include <map>
#include <string>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	map<char, int> basketball;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		basketball[name[0]]++;
	}

	int flag = false;
	for (auto pair : basketball) {
		if (pair.second >= 5) {
			flag = true;
			cout << pair.first;
		}
	}

	if (!flag) {
		cout << "PREDAJA";
	}

	return 0;
}