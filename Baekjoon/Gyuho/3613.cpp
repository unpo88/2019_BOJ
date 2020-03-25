#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string str;

	cin >> str;

	int len = str.size();

	bool error = false;
	bool java = false;
	bool cpp = false;

	string tmp = "";
	
	if (('A' <= str[0] && str[0] <= 'Z') || str[0] == '_')
		error = true;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '_')
		{
			if (i + 1 < len && ('a' <= str[i + 1] && str[i + 1] <= 'z'))
			{
				i++;
				tmp += (str[i] - 'a' + 'A');
				java = true;
			}
			else
				error = true;
		}

		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			tmp += '_';
			tmp += (str[i] - 'A' + 'a');
			cpp = true;
		}

		else
			tmp += str[i];
	}

	if (error)
		cout << "Error!" << endl;
	else if (java && cpp)
		cout << "Error!" << endl;
	else
		cout << tmp << endl;

	return 0;
}
