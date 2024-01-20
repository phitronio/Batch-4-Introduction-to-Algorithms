#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
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
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    bfs(src);
    return 0;
}