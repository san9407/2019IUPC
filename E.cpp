#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000000;

struct Node
{
	int x, y, l, r;
};

int board[1000][1000];
bool visit[1000][1000];

int main()
{
	int N, M, L, R;
	scanf("%d %d %d %d", &N, &M, &L, &R);
	int sx, sy;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &board[i][j]);
			if (board[i][j] == 2)
			{
				sx = i;
				sy = j;
			}
		}
	}
	deque<Node> dq;
	dq.push_back({ sx,sy,0,0 });
	int ans = 0;
	while (!dq.empty())
	{
		int cx = dq.front().x;
		int cy = dq.front().y;
		int lcnt = dq.front().l;
		int rcnt = dq.front().r;
		dq.pop_front();
		if (visit[cx][cy])
			continue;
		visit[cx][cy] = true;
		ans++;
		if (0 < cx && board[cx - 1][cy] == 0)
			dq.push_front({ cx - 1,cy,lcnt,rcnt });
		if (cx < N - 1 && board[cx + 1][cy] == 0)
			dq.push_front({ cx + 1,cy,lcnt,rcnt });
		if (0 < cy && board[cx][cy - 1] == 0 && lcnt < L)
			dq.push_back({ cx,cy - 1,lcnt + 1,rcnt });
		if (cy < M - 1 && board[cx][cy + 1] == 0 && rcnt < R)
			dq.push_back({ cx,cy + 1,lcnt,rcnt + 1 });
	}
	printf("%d\n", ans);
	return 0;
}
