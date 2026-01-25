#include <bits/stdc++.h>
using namespace std;

int main()
{
    //vector<string> act = {"A","B","C","D","E","F","G","H","I"};
    //vector<string> pred = {"-","A","A","B","B","C","E,D","E,F","H,G"};
    //vector<int> dur = {10,15,3,8,7,6,10,15,5};

    vector<string> act = {"A","B","C","D","E","F"};
    vector<string> pred = {"-","A","A","B","C","D,E"};
    vector<int> dur = {5,4,5,6,3,4};

    int n = act.size();

    unordered_map<string,int> idx;

    for(int i = 0; i < n; i++)
        idx[act[i]] = i;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    // Build graph
    for(int i = 0; i < n; i++)
    {
        if(pred[i] == "-") continue;
        stringstream ss(pred[i]);
        string p;
        while(getline(ss, p, ','))
        {
            adj[idx[p]].push_back(i);
            indeg[i]++;
        }
    }

    // Topological sort
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indeg[i] == 0) q.push(i);

    vector<int> topo;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : adj[u])
            if(--indeg[v] == 0) q.push(v);
    }

    // Forward pass
    vector<int> ES(n, 0), EF(n, 0);
    for(int u : topo)
    {
        EF[u] = ES[u] + dur[u];
        for(int v : adj[u])
            ES[v] = max(ES[v], EF[u]);
    }

    int projectTime = *max_element(EF.begin(), EF.end());

    // Backward pass
    vector<int>LS(n, projectTime), LF(n, projectTime);

    for(int i = n - 1; i >= 0; i--)
    {
        int u = topo[i];
        for(int v : adj[u])
            LF[u] = min(LF[u], LS[v]);
        LS[u] = LF[u] - dur[u];
    }

    // Output
    cout << "Activity\tEST\tEFT\tLST\tLFT\tSlack\n";
    for(int i = 0; i < n; i++)
    {
        cout << act[i] << "\t\t"
             << ES[i] << "\t"
             << EF[i] << "\t"
             << LS[i] << "\t"
             << LF[i] << "\t"
             << LS[i] - ES[i] << "\n";
    }

    cout << "\nCritical Path: ";
    for(int i = 0; i < n; i++)
        if(ES[i] == LS[i]) cout << act[i] << " ";

    return 0;
}
