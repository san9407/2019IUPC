#include <cstdio>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

int main()
{
	int N;
	scanf("%d", &N);
	int ans = -INF;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		ans = max(ans, num);
	}
	printf("%d\n", ans);
	return 0;
}
