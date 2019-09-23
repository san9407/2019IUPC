#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main()
{
	int N,M;
	scanf("%d %d", &N, &M);
	int A, B;
	scanf("%d %d", &A, &B);
	int curr = A;
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		if (curr <= num)
		{
			if (cnt % 2)
				curr = A;
			else
				curr = B;
			cnt++;
		}
	}
	printf("%d\n", curr);
	return 0;
}
