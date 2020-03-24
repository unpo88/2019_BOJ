#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string k;
	cin >> k;
	for (int i = 0; i < k.size(); i++)
	{
		if (k[i] >= 97 && k[i] <= 122)
		{
			k[i] -= 32;
		}
		else if (k[i] >= 65 && k[i] <= 90)
		{
			k[i] += 32;
		}
		cout << k[i];
	}
	cout << '\n';

	return 0;
}