#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;
const int MOD = 987654321;

long long dp[10001];

int main()
{
	int N;
	scanf("%d", &N);
	dp[0] = 1;
	for (int i = 2; i <= N; i += 2)
	{
		for (int j = 0; j < i; j+=2)
		{
			dp[i] += dp[j] * dp[i - j - 2];
			dp[i] %= MOD;
		}
	}
	printf("%lld\n", dp[N]);
	return 0;
}
