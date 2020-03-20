#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	int arr[101];
	stack<int> s;
	stack<int> tmp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		for (int j = 0; j < arr[i]; j++)
		{
			tmp.push(s.top());
			s.pop();
		}

		s.push(i + 1);

		for (int j = 0; j < arr[i]; j++)
		{
			s.push(tmp.top());
			tmp.pop();
		}
	}

	while (!s.empty())
	{
		tmp.push(s.top());
		s.pop();
	}
	
	while (!tmp.empty())
	{
		printf("%d ", tmp.top());
		tmp.pop();
	}

	return 0;
}