#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int coin[8], p;
	string c;

	cin >> p;
	while (p--)
	{
		cin >> c;
		for (int i = 0; i < 8; i++)
			coin[i] = 0;
		for (int i = 0; i < 38; i++)
		{
			if (c[i] == 'H')
			{
				if (c[i + 1] == 'H')
				{
					if (c[i + 2] == 'H')
						coin[7]++;
					else
						coin[6]++;
				}
				else
				{
					if (c[i + 2] == 'H')
						coin[5]++;
					else
						coin[4]++;
				}
			}
			else
			{
				if (c[i + 1] == 'H')
				{
					if (c[i + 2] == 'H')
						coin[3]++;
					else
						coin[2]++;
				}
				else
				{
					if (c[i + 2] == 'H')
						coin[1]++;
					else
						coin[0]++;
				}
			}
		}
		for (int i = 0; i < 8; i++)
			cout << coin[i] << ' ';
		cout << '\n';
	}
}