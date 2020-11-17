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
  cout << n << "=";
  vector<int> v(sqrt(n)+1, 1);
  set<int>f;
  int lol=n;
  multiset<int>q;
  v[0] = v[1] = 0;
  for (int i = 2; i*i*i*i <= n; ++i)
    if (v[i]) {
      for (int j = i * i; j*j <= n; j += i)
        v[j] = 0;
    }
  bool d = false, k = false;
  for (int i = 2; i*i <= n; ++i) if (v[i]) f.insert(i);
  while (n > 1) {
    k = false;
    for (auto it : f) {
      if (n > 1) {
        if (n%it == 0) {
          n /= it;
          q.insert(it);
          k = true;
        }
      }
      else break;
    }
    if (k == false) break;
  }
  if (q.size() == 0) q.insert(n);
  int qo=1;
  for (auto it : q) {
    if (d == false) {
      cout << it;
      d = true;
    }
    else     {cout << "*" << it;}
    qo*=it;
  }
  if (qo!=lol) cout << "*" << lol/qo;

}