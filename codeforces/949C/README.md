## [Codeforces 949C - Data Center Maintenance](http://codeforces.com/problemset/problem/949/C)

### 题意

有 $n$ 个数，第 $i$ 个数的值是 $u_i$。还有 $m$ 个限制，第 $i$ 个限制 $(a_i, b_i)$ 表示 $u_{a_i} \ne u_{b_i}$。一开始所有限制都是满足的。

现在要选择 $k$ ($1 \le k \le n$) 个数，让这些数都 +1 后 mod $h$，并且限制还都要满足。求 $k$ 的最小值。

$1 \le n, m, h \le 10^5$。

### 题解

如果 $u_i$ 改变后，$u_j$ 也得跟着改变，那么在点 $i$ 和点 $j$ 之间连一条边，这样构成一个有向图。显然，如果一个点改变了，那么它所能到达的点都要跟着改变。

我们把强连通分量都缩成点，有向图就变成了 DAG，每个强连通分量的大小就是点权。找到 DAG 里没有出度的点中点权最小的，它的点权就是最小的 $k$。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/949C/sol.cpp)
