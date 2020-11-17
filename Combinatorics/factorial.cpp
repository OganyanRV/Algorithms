// Динамика

int fact[10000001] = {0};
int was = 1;

int  factorial (int request) {
  if (!fact[request]) {
    while (was!=request) {
      ++was;
      fact[was] = was * fact[was-1] %1000000007;
    }
  }
  return fact[request];
}

// выисление факториала деревом (Меньшее с меньшим, большее с большим)

int  ProdTree(int l, int r)
{
  if (l > r)
    return 1;
  if (l == r)
    return l;
  if (r - l == 1)
    return l * r;
  int m = (l + r) / 2;
  return ProdTree(l, m)%mod * ProdTree(m + 1, r)%mod;
}

int  FactTree(int n)
{
  if (n < 0)
    return 0;
  if (n == 0)
    return 1;
  if (n == 1 || n == 2)
    return n;
  return ProdTree(2, n)%mod;
}