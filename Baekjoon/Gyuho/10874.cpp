#include <iostream>
using namespace std;

int main() {

	int n, a[11], ans;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		bool c = true;
		for (int j = 1; j <= 10; j++)
		{
			cin >> a[j];
			if (a[j] != (j - 1) % 5 + 1)
				c = false;
		}
		if (c == true)
			cout << i << '\n';
	}
}
