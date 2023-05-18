#include <bits/stdc++.h>
#define pii pair<int, int>;
#define pib pair<int, bool>;
#define pis pair<int, string>;
#define pic pair<int, char>;

using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int start, int target, bool distance)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(start);

    if(!distance)
    {
        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto& v : graph[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);

                    if(v == target)
                    {
                        vector<int> path;
                        int node = v;
                        while(node != start)
                        {
                            path.push_back(node);
                            node = parent[node];
                        }
                        path.push_back(start);
                        reverse(path.begin(), path.end());
                        return path;
                    }
                }
            }
        }
        return {};
    }

    else
    {
        vector<int> dist(n, 0);
        dist[start] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto& v : graph[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    dist[v] = dist[u] +1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
}

int main()
{
    int n, m, start, target;
    bool distance = true;
    cin >> n >> m;

    vector<vector<int>> graph(m+1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> start >> target;

    vector<int> path = bfs(graph, start, target, distance);

    if(!distance)
    {
        for(int i : path)
            cout << i << " ";
    }

    else
        cout << path.at(target);
}
