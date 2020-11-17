#define mod 1e7
signed main() {
  int m;
  cin >> m;
  vector <vector<int>> C(m+1);
  for (int n = 0; n <= m; n++) {
    C[n].resize(m + 1);
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
      C[n][k] = (C[n - 1][k - 1] + C[n - 1][k])%mod;
  }
  forll(m + 1) {
    forll2(m + 1)
    if (C[i][j]) cout << C[i][j] << ' ';
    ou(' ');
  }
  return 0;

}