#include <iostream>
using namespace std;

int L;
unsigned long long num;
long long R = 1;
long long M = 1234567891;
char str[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> L >> str;

	for (int i = 0; i < L; i++) {
		num += (str[i] - 'a' + 1) * R;
		num %= M;
		R *= 31;
		R %= M;
	}

	cout << num;

	return 0;
}