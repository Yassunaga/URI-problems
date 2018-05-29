#include<bits/stdc++.h>
#define max 500

using namespace std;

vector<int>graph[max];
bool visited[max];
void dfs(int source);
int ilhas=0;
int m, n;

int main()
{
    int caso = 1;
    int T;

    cin >> T;

    while(T--)
    {
        memset(visited, false, sizeof(visited));
        ilhas=0;
        for(int k=1; k<=max; k++)
        {
            graph[k].clear();
        }
        cin >> n >> m;
        for(int i=1; i<=m; i++)
        {
            int inicio, fim;
            cin >> inicio >> fim;
            graph[inicio].push_back(fim);
            graph[fim].push_back(inicio);
        }
        for(int i=1; i<=n; i++)
        {
            if(not visited[i])
            {
                dfs(i);
                ilhas++;
            }
        }
        if(ilhas-1 == 0)
        {
            cout << "Caso #"<< caso <<": a promessa foi cumprida" << endl;
        }
        else
        {
            cout << "Caso #"<< caso <<": ainda falta(m) " << ilhas-1 << " estrada(s)" << endl;
        }
        caso++;
    }
    return 0;
}

void dfs(int source)
{
    visited[source] = true;
    for(auto vertice : graph[source])
    {
        if(not visited[vertice])
        {
            dfs(vertice);
        }
    }
}
