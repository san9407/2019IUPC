#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

int a[200000];
int b[200000];
int q[200000];
int cntTree[2097152];
int maxTree[2097152];
map<int, int> mp;
map<int, int> mp2;
int dap[200000];

void maxUpdate(int node, int start, int end, int index, int val)
{
	if (index<start || index>end)
		return;
	maxTree[node] = max(maxTree[node], val);
	if (start != end)
	{
		int mid = (start + end) >> 1;
		maxUpdate(node * 2, start, mid, index, val);
		maxUpdate(node * 2 + 1, mid + 1, end, index, val);
	}
}

void cntUpdate(int node, int start, int end, int index, int diff)
{
	if (index<start || index>end)
		return;
	cntTree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) >> 1;
		cntUpdate(node * 2, start, mid, index, diff);
		cntUpdate(node * 2 + 1, mid + 1, end, index, diff);
	}
}

int maxFind(int node, int start, int end, int left, int right)
{
	if (right<start || left>end)
		return -1;
	if (left <= start && end <= right)
		return maxTree[node];
	int mid = (start + end) >> 1;
	int m1 = maxFind(node * 2, start, mid, left, right);
	int m2 = maxFind(node * 2 + 1, mid + 1, end, left, right);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return max(m1, m2);
}

int cntFind(int node, int start, int end, int left, int right)
{
	if (right<start || left>end)
		return 0;
	if (left <= start && end <= right)
		return cntTree[node];
	int mid = (start + end) >> 1;
	return cntFind(node * 2, start, mid, left, right) + cntFind(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> vt;
	for (int i = 0; i < N; i++)
	{
		int ai, bi;
		scanf("%d %d", &ai, &bi);
		a[i] = ai;
		b[i] = bi;
		vt.push_back(ai);
		vt.push_back(bi);
	}
	for (int i = 0; i < M; i++)
	{
		int K;
		scanf("%d", &K);
		q[i] = K;
		vt.push_back(K);
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());
	for (int i = 0; i < vt.size(); i++)
	{
		mp[vt[i]] = i;
	}
	for (int i = 0; i < N; i++)
	{
		mp2[mp[a[i]]] = a[i];
		a[i] = mp[a[i]];
	}
	for (int i = 0; i < N; i++)
	{
		mp2[mp[b[i]]] = b[i];
		b[i] = mp[b[i]];
	}
	for (int i = 0; i < M; i++)
	{
		mp2[mp[q[i]]] = q[i];
		q[i] = mp[q[i]];
	}
	for (int i = 0; i < M; i++)
	{
		maxUpdate(1, 0, 599999, q[i], i);
	}
	vector<pair<int,int> > vt1;
	for (int i = 0; i < N; i++)
	{
		int minn = min(a[i], b[i]);
		int maxx = max(a[i], b[i]);
		if (a[i] != b[i])
		{
			int t = maxFind(1, 0, 599999, minn, maxx - 1);
			vt1.emplace_back(t, i);
		}
		else
			dap[i] = mp2[a[i]];
	}
	sort(vt1.begin(), vt1.end());
	int idx = vt1.size() - 1;
	for (int i = M - 1; i >= 0; i--)
	{
		cntUpdate(1, 0, 599999, q[i], 1);
		while (1)
		{
			if (idx == -1)
				break;
			if (vt1[idx].first != i)
				break;
			int cur = vt1[idx].second;
			int t = cntFind(1, 0, 599999, max(a[cur], b[cur]), 599999);
			if (t % 2)
				dap[cur] = mp2[(i == 0 ? b[cur] : min(a[cur], b[cur]))];
			else
				dap[cur] = mp2[(i == 0 ? a[cur] : max(a[cur], b[cur]))];
			idx--;
		}
	}
	while (1)
	{
		if (idx == -1)
			break;
		int cur = vt1[idx].second;
		int t = cntFind(1, 0, 599999, b[cur], 599999);
		if (t % 2)
			dap[cur] = b[cur];
		else
			dap[cur] = a[cur];
		idx--;
	}
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += dap[i];
	}
	printf("%lld\n", sum);
	return 0;
}
//좌표압축 + 세그먼트트리 + 오프라인 쿼리
//어렵다 ㅠ.ㅠ
//여러 사람들의 코드를 참고함
