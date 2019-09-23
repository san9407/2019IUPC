#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int arr[100000];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", arr + i);
	}
	sort(arr,arr+M);
	int lo = 0, hi = N;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) >> 1;
		bool flag = false;
		int start = arr[0]-mid, end=arr[0]+mid;
		if (start > 0)
			flag = true;
		for (int i = 1; i < M; i++)
		{
			if (end >= arr[i] - mid)
			{
				start = end;
				end = arr[i] + mid;
			}
			else
			{
				flag = true;
			}
		}
		if (end < N)
			flag = true;
		if (flag)
			lo = mid;
		else
			hi = mid;
	}
	printf("%d\n", hi);
	return 0;
}
