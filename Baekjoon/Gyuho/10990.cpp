#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	if (n == 1) { cout << "*" << '\n'; return 0; }
	for (int i = 1; i <= n * 2; i++)
	{
		if (i % 2 == 1)
		{
			if (n % 2 == 0)
			{
				for (int j = 1; j <= n / 2; j++)
					cout << "* ";
				cout << '\n';
			}
			else
			{
				for (int j = 1; j <= (n + 1) / 2; j++)
					cout << "* ";
				cout << '\n';
			}
		}
		else
		{
			if (n % 2 == 0)
			{
				for (int j = 1; j <= n / 2; j++)
					cout << " *";
				cout << '\n';
			}
			else
			{
				for (int j = 1; j <= (n - 1) / 2; j++)
					cout << " *";
				cout << '\n';
			}
		}
	}

	return 0;
}