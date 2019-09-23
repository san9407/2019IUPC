#include <cstdio>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
int alpa[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	char A[101], B[101];
	scanf("%s %s", A, B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int temp1[201], temp2[201];
	int i, j, idx = 0;
	for (i = 0, j = 0; i < lenA && j < lenB; i++, j++)
	{
		temp1[idx++] = alpa[A[i] - 'A'];
		temp1[idx++] = alpa[B[j] - 'A'];
	}
	while (i < lenA)
		temp1[idx++] = alpa[A[i++] - 'A'];
	while (j < lenB)
		temp1[idx++] = alpa[B[j++] - 'A'];

	for (i = 0, j = 0; i < lenA && j < lenB; i++, j++)
	{
		temp2[idx++] = alpa[B[i] - 'A'];
		temp2[idx++] = alpa[A[j] - 'A'];
	}
	while (i < lenB)
		temp2[idx++] = alpa[B[i++] - 'A'];
	while (j < lenA)
		temp2[idx++] = alpa[A[j++] - 'A'];


	int add[201];
	for (i = 0; i < lenA + lenB - 2; i++)
	{
		for (j = 0; j < lenA + lenB - 1 - i; j++)
		{
			add[j] = temp1[j] + temp1[j + 1];
			add[j] %= 10;
		}
		for (j = 0; j < lenA + lenB - 1 - i; j++)
			temp1[j] = add[j];
	}
	int ans = temp1[0] * 10 + temp1[1];
	printf("%d", ans);
	puts("%");
	return 0;
}
