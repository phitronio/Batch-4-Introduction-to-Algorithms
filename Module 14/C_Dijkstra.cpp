#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
using namespace std;
const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];
ll par[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};
void dijkstra(ll s)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();
        ll parentNode = parent.first;
        ll parentCost = parent.second;
        for (pi child : v[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
                par[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        par[i] = -1;
    }
    dijkstra(1);
    if (dis[n] == 1e18)
        cout << -1 << endl;
    else
    {
        ll x = n;
        vector<ll> path;
        while (x != -1)
        {
            path.push_back(x);
            x = par[x];
        }
        reverse(path.begin(), path.end());
        for (ll val : path)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}