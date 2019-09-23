#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;
#define MAX_TABLE 10007

typedef struct
{
	int cnt;
	char c;
	char data[21];
}Hash;
Hash tb[MAX_TABLE];

unsigned long HASH(const char* str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

char find(char* data)
{
	unsigned long h = HASH(data);
	int cnt = MAX_TABLE;

	while (tb[h].cnt != 0 && cnt--)
	{
		if (strcmp(tb[h].data, data) == 0)
		{
			return tb[h].c;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 'L';
}

void add(char* data,char c)
{
	unsigned long h = HASH(data);

	while (tb[h].cnt != 0)
	{
		if (strcmp(tb[h].data, data) == 0)
		{
			return;
		}

		h = (h + 1) % MAX_TABLE;
	}
	tb[h].cnt = 1;
	tb[h].c = c;
	strcpy(tb[h].data, data);
	return;
}

int main()
{
	int N,P;
	scanf("%d %d", &N,&P);
	for (int i = 0; i < MAX_TABLE; i++)
	{
		tb[i].cnt = 0;
		tb[i].c = 'L';
	}
	int W, L, G;
	scanf("%d %d %d", &W, &L, &G);
	for (int i = 0; i < P; i++)
	{
		char name[21];
		char c;
		scanf("%s %c", name, &c);
		add(name, c);
	}
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		char name[21];
		scanf("%s", name);
		char c=find(name);
		if (c == 'W')
		{
			sum += W;
			if (sum >= G)
				flag = true;
		}
		else
		{
			sum = max(0, sum - L);
		}
	}
	printf("%s\n", flag ? "I AM NOT IRONMAN!!" : "I AM IRONMAN!!");
	return 0;
}
