#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<queue>
#include<vector>
const long long  INF = 0x3f3f3f3f3f3f3f3f;
#define PI acos(-1.0)
#define N 20025
#define MOD 2520
#define E 1e-12
using namespace std;
int n, a[N], b[N], f[N], vis[N], flag[N], cnt;
/*
a[i]表示bfs判重
b[i]表示现在bfs中第i个点是哪个点（对应哪一个序号）
cnt表示现在bfs中点的个数
f[i]表示第i个点的父亲编号
vis[i]表示i点是否被覆盖
flag[i]表示i点是否属于要求大的点集
*/
vector<int>g[N];
int dfs(int u)//dfs求出每一个点的父亲节点
{
	cnt++;
	a[u] = cnt;
	b[cnt] = u;

	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (a[v] == -1)
		{
			f[v] = u;
			dfs(v);
		}
	}
	return 0;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			g[i].clear();
		memset(a, -1, sizeof(a));
		memset(vis, 0, sizeof(vis));
		memset(flag, 0, sizeof(flag));
		memset(f, 0, sizeof(f));

		for (int i = 1; i < n; i++)
		{

			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
//			g[y].push_back(x);
		}
		cnt = 0;
		dfs(1);
		int ans = 0;
		//贪心求最小支配集

		for (int i = 0; i <= 10; i++)
			//cout << b[i] << "    ";
		cout << endl;
		for (int i = n; i >= 1; i--)//方向序列检查
		{
			int u = b[i];

			if (vis[u] == 0)//当前点未被覆盖，表示当前点既不属于支配集，也不与支配集的点相连
			{
				if (flag[f[u]] == 0)//当前点的父亲不属于支配集
				{
					flag[f[u]] = 1;//加入支配集
					cout << f[u]<< "    ";

					ans++;       //支配集个数加1
				}
				//标记当前点、当前结点的父节点、当前结点的父节点的父节点
				vis[u] = 1;
				vis[f[u]] = 1;
				vis[f[f[u]]] = 1;
			}
		}
		cout << endl;
		printf("%d\n", ans);
	}
	return 0;
}
