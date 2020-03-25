#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;

int friendMap[51][51];

void DFS()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j || j == k || i == k)
                {
                    continue;
                }
                else if (friendMap[i][j] > friendMap[i][k] + friendMap[k][j])
                {
                    friendMap[i][j] = friendMap[i][k] + friendMap[k][j];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.size(); j++)
        {
            if (i == j)
            {
                friendMap[i][j] = 0;
            }
            else
            {
                friendMap[i][j] = temp[j] == 'Y' ? 1 : 3;
            }
        }
    }

    DFS();

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            else if (friendMap[i][j] <= 2)
            {
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }

    cout << answer << "\n";

    return 0;
}