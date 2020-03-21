#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n;
char ans[101];
int g[3];
vector<vector<pair<string, string>>> v(3);

int checkAnswer(int p)
{
	int grade = 0;
	int i = 0;
	int pos = 0;
	int size = v[p].front().first.size();
	while (i < n)
	{
		if (ans[i] == v[p].front().first[pos])
		{
			grade++;
		}

		i++;
		pos++;
		if (pos == size)
		{
			pos = 0;
		}
	}

	return grade;
}
int main()
{
	int grade = -1;
	scanf("%d", &n);
	scanf("%s", &ans);

	v[0].push_back({ "ABC","Adrian" });
	v[1].push_back({ "BABC","Bruno" });
	v[2].push_back({ "CCAABB","Goran" });

	for (int i = 0; i < 3; i++)
	{
		g[i] = checkAnswer(i);

		if (grade < g[i])
		{
			grade = g[i];
		}
	}

	printf("%d\n", grade);
	for (int i = 0; i < 3; i++)
	{
		if (grade == g[i])
		{
			cout << v[i].front().second << endl;
		}
	}

	return 0;
}
