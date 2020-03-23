#include <iostream>
#include <string>
using namespace std;

string fa(string x) {
	string tmp;
	tmp = ((x[0]) - '0' * x.size()) + '0';
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string x;
	cin >> x;

	for (int i = 0; i < x.size(); i++) {
		x = fa(x);
	}

	if (x.size() == 1) {
		cout << "FA";
	}
	else {
		cout << "NFA";
	}

	return 0;
}