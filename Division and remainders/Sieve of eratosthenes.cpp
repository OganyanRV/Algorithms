// Решето до корня из n
int main() {
  vector<int> v(sqrt(n) + 1, 1);
  set<int> f;
  int lol = n;
  multiset<int> q;
  v[0] = v[1] = 0;
  for (int i = 2; i * i * i * i <= n; ++i)
    if (v[i]) {
      for (int j = i * i; j * j <= n; j += i)
        v[j] = 0;
    }
}