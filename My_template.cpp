#ifdef OganyanRv
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Вычисление факториала

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
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// remainder for really big numbers
int remainder(string a, int n) {
  int ans = 0;
  for (int i = 0; i < a.length(); i++) {
    ans *= 10;
    ans += int(a[i]) - 48;
    ans %= n;
  }
  return ans;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//Euclidian algorithm for greatest common divisor ( NOD)
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
  /*
  if (b == 0)
      return a;
  else
      return gcd(b, a % b);*/
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//Extended Euclidean algorithm
int gcd (int a, int b, int & x, int & y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd (b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// raise x to the power of y and % m
int bigpower(int x, int y, int m) {
  int ans = 1 % m;
  while (y) {
    if (y % 2) ans = ans * x % m;
    y /= 2;
    x *= x % m;
  }
  return ans % m;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// multiplication
int bigmultiply(int a, int b, int m)
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
  if (a & 1) return (b + bigmultiply(a - 1, b, m)) % m;
  return (bigmultiply(a / 2, b,m) * 2) % m;
  */
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

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

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Cnk по модулю с помощью малой теоремы Ферма
int  solve(int n, int k)
{
  if (n < k)
    return 0;
  int up = 1, down = 1;
  int down2=1;
  up = factorial(n);
  down = factorial(k);
  down2= factorial(n-k);
  int res=0;
  down = (down*down2) %1000000007 ;
  // Обратное число в поле с помощью малой теоремы Ферма
  res = ((up * bigpower(down, 1000000005, 1000000007)) %1000000007 + 1000000007) % 1000000007;
  return res;
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void floyd() {
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void Deixtra(vector < vector < pair<int,int> > > & graph, int &size, vector<int> &distance, int start) {
  distance[start] = 0;
  vector<bool> u (size);
  for (int i=0; i<size; ++i) {
    int v = -1;
    for (int j=0; j<size; ++j)
      if (!u[j] && (v == -1 || distance[j] < distance[v]))
        v = j;
    if (distance[v] == INT_MAX)
      break;
    u[v] = true;

    for (size_t j=0; j<graph[v].size(); ++j) {
      int to = graph[v][j].first,
          len = graph[v][j].second;
      if (distance[v] + len < distance[to]) {
        distance[to] = distance[v] + len;
        // p[to] = v;
      }
    }
  }
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void dfs(int start, vector<bool> & visited)
{
  visited[start] = true;
  for (auto u : g[start]) {
    if (!visited[u]) {
      dfs(u, visited);
    }
  }
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void dfs(int start, vector<bool> & visited, vector<int> &ans) {
  stack<int> s;
  s.push(start);
  visited[start] = true;
  ans[start] = q;
  while (!s.empty()) {
    int v = s.top();
    s.pop();
    for (auto neighbor : g[v]) {
      if (!visited[neighbor]) {
        s.push(neighbor);
        visited[neighbor] = true;
        ans[neighbor] = q;
      }
    }
  }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

vector<int> dst(101, -1); // массив для дистанций
vector<int> pr(101, -1); // массив для записи путя
// Находит наибольшее расстояние от корня до вершин
void bfs (int start, vector <bool>& visited) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  dst[start] = 0;
  //pr[start] = -1;   //Пометка, означающая, что у вершины 0 нет предыдущей.
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto neighbor: g[cur]) {
      if (!visited[neighbor]) {
        q.push(neighbor);
        visited[neighbor] = true;
        dst[neighbor] = dst[cur] + 1;
        mmax = max(dst[cur] + 1, mmax);
        //pr[neighbor] = cur;   //сохранение предыдущей вершины
      }
    }
  }
}}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

vector<int> prefix_function (string s) { // Префикс-функция Кнута
  int n = (int) s.length();
  vector<int> pi (n);
  pi[0]=0;
  for (int i=1; i<n; ++i) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j])  ++j;
    pi[i] = j;
  }
  return pi;
}
cin>>t>>s;
t = s + '#' + t;
auto pref = prefix_function(t);
vi ans;
forll(pref.size()) {
if (pref[i]==s.size()) ans.push_back(i-2*s.size() + 1);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
vector<int> z_function (string s) {
  int n = (int) s.length();
  vector<int> z (n);
  for (int i=1, l=0, r=0; i<n; ++i) {
    if (i <= r)
      z[i] = min (r-i+1, z[i-l]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      ++z[i];
    if (i+z[i]-1 > r)
      l = i,  r = i+z[i]-1;
  }
  return z;
}

cin>>t>>s;
t = s + '#' + t;
auto zf = z_function(t); // реализация через z функцию
vi ans;
forll(zf.size()) {
if (zf[i]==s.size()) ans.push_back(i-s.size());
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Дп для матрицы из верхнего-левого угла в правый нижний
int dp(int p1, int p2) {
	if (p1 < 0 || p2 > n) return 100001;
	if (p1 == 0 && p2 == n) { // конец
		return a[0][n];
	}
	if (was[p1][p2])return val[p1][p2];
	int ans = val[p1][p2];
	//направления
	vector<int> dx = { 0, 1, 1 };
	vector<int> dy = { 1, 1, 0 };
	for (int i = 0; i < 3; ++i) {
		int tmp = dp(p1 - dx[i], p2 + dy[i]) + a[p1][p2];
		ans = min(tmp, ans);
	}
	val[p1][p2] = ans;
	was[p1][p2] = true;
	return ans;
};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#endif