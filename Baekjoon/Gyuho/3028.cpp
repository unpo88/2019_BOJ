#include <iostream>
#include <string>
using namespace std;

bool check[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s;
	
	check[1] = true;

	for (int i = 0; i < s.length(); i++) {
		bool temp;
		if (s[i] == 'A') {
			temp = check[1];
			check[1] = check[2];
			check[2] = temp;
		} 
		else if (s[i] == 'B') {
			temp = check[2];
			check[2] = check[3];
			check[3] = temp;
		}
		else {
			temp = check[3];
			check[3] = check[1];
			check[1] = temp;
		}
	}

	for (int i = 1; i <= 3; i++) {
		if (check[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}