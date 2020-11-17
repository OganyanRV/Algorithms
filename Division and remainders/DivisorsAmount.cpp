using namespace std;
void fastOutput() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
}


signed main() {
  fastOutput();
  int n;
  in(n);
  map <int, int> v;
  int b = 1;
  int tmp;
  forll(n) {
    cin >> tmp;
    v[tmp]++;

  }
  for (auto it : v) {
    b *= (it.second + 1);
    b %= 1000000007;
  }
  ou(b);
}