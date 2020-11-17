int long_divison(string a, int n) {
  int ans = 0;
  for (int i = 0; i < a.length(); i++) {
    ans *= 10;
    ans += int(a[i])-48;
    ans %= n;
  }
  return ans;
}
