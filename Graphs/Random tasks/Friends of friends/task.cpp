#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <utility>
#define int long long
#define endl "\n"
#define forll(n) for(long long i = 0; i < (n); i++)
#define forllr(n) for(long long i = (n); i >= 0; i--)
#define forll2(m) for(long long j = 0; j < (m); j++)
#define fori(n) for(int i = 0; i < (n); i++)
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define ou(x) cout<<x<<' '
#define in(x) cin>>x
using namespace std;
void fastOutput() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
}

signed main() {
  int a, b;
  cin >> a >> b;
  vector<vector<int> > v(a, vector<int>(a, 0));
  forll(b) {
    int n, m;
    cin >> n >> m;
    m--; n--;
    v[m][n] = v[n][m] = 1;
  }
  vi ans;
  forll(a) {
    vi temp;
    forll2(a) { if (v[i][j] && i!=j) temp.push_back(j);}
    set<int> cur;
    for (int j=0; j<temp.size(); ++j) {
      for (int k=0; k<a; ++k) {
        if (v[temp[j]][k]) {
          if (k!=i && k!=temp[j] && find(temp.begin(), temp.end(), k) == temp.end())
            cur.insert(k);
        }
      }
    }
    ans.push_back(cur.size());
  }
  for (int i=0; i<a; ++i) {
    cout<<ans[i]<<" ";
  }
}