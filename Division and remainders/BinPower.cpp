// raise x to the power of y and % m
int binpower(int x, int y, int m) {
  int ans = 1 % m;
  while (y) {
    if (y % 2) ans = ans * x % m;
    y /= 2;
    x *= x % m;
  }
  return ans % m;
}