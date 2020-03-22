#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int a, b;
	N += (2400 - 2013);
	a = (N + 5) % 12;
	b = (N + 9) % 10;

	cout << char(a + 'A') << char(b + '0');
	return 0;
}