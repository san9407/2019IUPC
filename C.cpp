#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

int N;
char board[6][6];
int maxx = -INF;
int minn = INF;

void dfs(int x, int y, int curr,char c)
{
	if (x > N || y > N)
		return;
	if (x == N && y == N)
	{
		maxx = max(maxx, curr);
		return;
	}
	if ('0' <= board[x][y] && board[x][y] <= '9')
	{
		dfs(x + 1, y, curr, board[x + 1][y]);
		dfs(x, y + 1, curr, board[x][y + 1]);
	}
	if (board[x][y] == '+')
	{
		dfs(x + 1, y, curr + (int)(board[x + 1][y]-'0'), c);
		dfs(x, y + 1, curr + (int)(board[x][y + 1]-'0'), c);
	}
	else if (board[x][y] == '-')
	{
		dfs(x + 1, y, curr - (int)(board[x + 1][y]-'0'), c);
		dfs(x, y + 1, curr - (int)(board[x][y + 1]-'0'), c);
	}
	else if (board[x][y] == '*')
	{
		dfs(x + 1, y, curr * (int)(board[x + 1][y]-'0'), c);
		dfs(x, y + 1, curr * (int)(board[x][y + 1]-'0'), c);
	}
}

void dfs2(int x, int y, int curr, char c)
{
	if (x > N || y > N)
		return;
	if (x == N && y == N)
	{
		minn = min(minn, curr);
		return;
	}
	if ('0' <= board[x][y] && board[x][y] <= '9')
	{
		dfs2(x + 1, y, curr, board[x + 1][y]);
		dfs2(x, y + 1, curr, board[x][y + 1]);
	}
	if (board[x][y] == '+')
	{
		dfs2(x + 1, y, curr + (int)(board[x + 1][y] - '0'), c);
		dfs2(x, y + 1, curr + (int)(board[x][y + 1] - '0'), c);
	}
	else if (board[x][y] == '-')
	{
		dfs2(x + 1, y, curr - (int)(board[x + 1][y] - '0'), c);
		dfs2(x, y + 1, curr - (int)(board[x][y + 1] - '0'), c);
	}
	else if (board[x][y] == '*')
	{
		dfs2(x + 1, y, curr * (int)(board[x + 1][y] - '0'), c);
		dfs2(x, y + 1, curr * (int)(board[x][y + 1] - '0'), c);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf(" %c", &board[i][j]);
			
		}
	}
	dfs(1, 1, board[1][1] - '0', '0');
	dfs2(1, 1, board[1][1] - '0', '0');
	printf("%d %d\n", maxx,minn);
	return 0;
}
