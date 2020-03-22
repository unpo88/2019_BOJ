#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	double n, t;
	string x;

	cout << fixed;
	cout.precision(2);

	cin >> t;
	while (t--)
	{
		cin >> n;
		getline(cin, x);
		for (int i = 0; i < x.size(); i++)
			switch (x[i])
			{
			case '@':
				n *= 3;
				break;
			case '#':
				n -= 7;
				break;
			case '%':
				n += 5;
				break;
			}
		cout << n << "\n";
	}

	return 0;
}