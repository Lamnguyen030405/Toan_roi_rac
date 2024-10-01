//chay tren compiler tot hon
//test case
//8 12 1
//1 2
//1 3
//1 8
//2 1
//2 4
//2 8
//3 4
//3 6
//4 5
//5 6
//5 8
//6 7


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100001;

int n, m, r; // n dinh, m canh, r:root

vector<int> adj[maxn];

vector<int> chuaxet(maxn, 1);

vector<pair<int, int> > T;

void nhap()
{
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

}

void Tree_BFS(int r)
{
	queue<int> Q;
	Q.push(r);
	chuaxet[r] = 0;
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for (int u : adj[v])
		{
			if (chuaxet[u] == 1)
			{
				Q.push(u);
				chuaxet[u] = 0;
				T.push_back({ v,u });
			}
		}
	}
}

int main()
{
	nhap();
	Tree_BFS(r);
	for (auto it : T)
	{
		cout << "(" << it.first << ", " << it.second << ")" << ";\t";
	}
	return 0;
}
