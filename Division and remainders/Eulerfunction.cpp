// Разложение числа на простые множители, умножить (a^pn - a^p(n-1)) и (b^cn-b^c(n-1)) 72=(8-4)*(9-3)
int Eulerfunction(int n) {
  int ans = 1;
  for (int i = 2; i*i <= n; i++) {
    if (n%i == 0) {
      ans *= i - 1;
      n /= i;
      while (n%i == 0) {
        n /= i;
        ans *= i;
      }
    }
  }
  if (n > 1) ans *= n - 1;
  return ans;
}