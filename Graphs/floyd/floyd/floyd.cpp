#include <iostream>
#include <vector>
using namespace std;
vector<vector <int>> g;
int m,n;
void floyd() {
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
}

int main() {
freopen("floyd.in", "r", stdin);
freopen("floyd.out", "w", stdout);
cin>>n;
g.resize(n);
for ( int i=0; i<n;++i) {
  g[i].resize(n);
  for (int j=0; j<n;++j) cin>>g[i][j];
}
floyd();
  for ( int i=0; i<n;++i) {
    for (int j=0; j<n;++j) cout<<g[i][j]<< " ";
    cout <<"\n";
  }
  return 0;

}
