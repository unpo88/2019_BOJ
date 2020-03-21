#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	int len1 = B - A;
	int len2 = C - B;
	int len3;

	if (len1 > len2)	len3 = len1;
	else
	{
		len3 = len2;
	}

	cout << len3 - 1 << "\n";


	return 0;
}