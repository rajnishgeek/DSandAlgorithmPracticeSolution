#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;


vector<int> inTime;
vector<int> outTime;
int timer = 1;

void resize(int n) {
    inTime.resize(n + 1);
    outTime.resize(n + 1);
}

void dfs(int src, int par, vector<int> g[]) {
    inTime[src] = timer++;
    for (auto x : g[src]) {
        if (x != par) {
            dfs(x, src, g);
        }
    }
    outTime[src] = timer++;
}

bool check(int x, int y) {
    if (inTime[x] > inTime[y] and outTime[x] < outTime[y])
        return true;
    return false;
}



int32_t main()
{
    int n;
    cin >> n;
    timer = 1;
    resize(n);
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, g);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        if (!check(x, y) and !check(y, x)) {
            cout << "NO\n";
            continue;
        }
        if (type == 0) {
            if (check(y, x))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (type == 1) {
            if (check(x, y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    }

    return 0;
}

// vector<int> inTime, outTime;
// int timer = 1;

// void resize(int n)
// {
//  inTime.resize(n);
//  outTime.resize(n);
// }

// void dfs(vector<int> adj[], int src, int parent)
// {
//  inTime[src] = timer++;
//  for (auto it : adj[src])
//      if (src != parent)
//          dfs(adj, it, src);
//  outTime[src] = timer++;
// }


// bool isSubtree(int x, int y)
// {
//  //x is subtree of y
//  return (inTime[y] < inTime[x] && outTime[y] > outTime[x]);
// }

// int main()
// {
//  int n;
//  cin >> n;
//  vector<int> adj[n + 1];
//  for (int i = 1; i < n; i++)
//  {
//      int u, v;
//      cin >> u >> v;
//      adj[u].push_back(v);
//      adj[v].push_back(u);
//  }
//  dfs(adj, 1, 0);
//  int q;
//  cin >> q;
//  while (q--)
//  {
//      int type, x, y;
//      cin >> type >> x >> y;
//      if (isSubtree(x, y) == false && isSubtree(y, x) == false)
//      {
//          cout << "NO" << endl;
//          continue;
//      }
//      if (type == 0)
//      {
//          if (isSubtree(y,x))
//              cout << "YES" << endl;
//          else
//              cout << "NO" << endl;
//      }
//      else if (type == 1)
//      {
//          if (isSubtree(x,y))
//              cout << "YES" << endl;
//          else
//              cout << "NO" << endl;
//      }
//  }
//  return 0;
// }