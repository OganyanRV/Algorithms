//Euclidian algorithm for greatest common divisor ( NOD)
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
  /*
  if (b == 0)
      return a;
  else
      return gcd(b, a % b);
      */
}