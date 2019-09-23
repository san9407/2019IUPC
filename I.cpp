#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;
const int MOD = 1000000007;

long long dp[10001];

int main()
{
	int N,M;
	scanf("%d %d", &N,&M);
	dp[1] = 1;
	dp[M] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] += dp[i - 1];
		if (i - M >= 0)
			dp[i] += dp[i - M];
		dp[i] %= MOD;
	}
	printf("%lld\n", dp[N]);
	return 0;
}
