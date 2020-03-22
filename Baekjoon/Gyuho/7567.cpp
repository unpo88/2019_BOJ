#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string k;
	int sum = 10;
	cin >> k;
	for (int i = 0; i < k.size(); i++)
	{
		if ((k[i] == ')' && k[i + 1] == '(')
			|| (k[i] == '(' && k[i + 1] == ')')
			&& i + 1 < k.size())
		{
			sum += 10;
		}
		else if ((k[i] == ')' && k[i + 1] == ')')
			|| (k[i] == '(' && k[i + 1] == '(')
			&& i + 1 < k.size())
		{
			sum += 5;
		}
	}
	cout << sum << '\n';

	return 0;
}