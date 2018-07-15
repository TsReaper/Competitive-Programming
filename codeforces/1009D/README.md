## [Codeforces 1009D - Relatively Prime Graph](http://codeforces.com/problemset/problem/1009/D)

### 题意

构造一张 $n$ 个点（点的编号从 1 到 $n$）$m$ 条边的连通图，使得每一条边连接的两个点编号的 gcd 为 1，或输出 Impossible 表示无法构造。

$1 \le n, m \le 10^5$。

### 题解

为了保证连通性，要求 $m \ge n - 1$，不满足的直接 Impossible。

因为 1 和其它数的 gcd 都是 1，所以先把 1 和其它所有点连上，这样连通性问题就解决了。

接下来就是怎样凑够剩下的 $(m - n + 1)$ 条边。写个 $n^2\log n$ 的暴力很容易发现，当 $n = 1000$ 的时候，所有符合要求的边已经超过 $10^5$ 条了。所以如果 $n \le 1000$ 就暴力统计满足要求的边是否有 $(m - n + 1)$ 条，$n > 1000$ 就只要暴力枚举 $(u, v)$ 的边（$2 \le u, v \le 1000$），肯定够 $(m - n + 1)$ 条。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/1009D/sol.cpp)
