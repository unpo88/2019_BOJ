#include <iostream>
using namespace std;

int M, N, a[101][101], t, ans, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> M >> N;

		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				a[i][j] = 0;

		ans = 0;
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				cin >> a[i][j];

		for (int j = 1; j <= N; j++)
		{
			for (int i = M; i >= 1; i--)
			{
				cnt = 0;
				if (a[i][j] == 1)
				{
					for (int k = i + 1; k <= M; k++)
					{
						if (a[k][j] == 1) { break; }
						else
							cnt++;
					}
					ans += cnt;
					swap(a[i + cnt][j], a[i][j]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}