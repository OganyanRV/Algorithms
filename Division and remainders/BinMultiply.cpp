int binmultiply(int a, int b, int m)
{
  int ans = 0;
  while (b) {
    if (b % 2) ans = (ans + a) % m;
    b /= 2;
    a = (a + a) % m;
  }
  return (ans%m);
  /*
  if (!a || !b) return 0;
  if (a & 1) return (b + binmultiply(a - 1, b, m)) % m;
  return (binmultiply(a / 2, b,m) * 2) % m;
  */
}