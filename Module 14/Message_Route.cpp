#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int dis[N];
int parent[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[par] + 1;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(parent, -1, sizeof(parent));
    bfs(1);
    if (dis[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        int x = n;
        vector<int> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int val : path)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}