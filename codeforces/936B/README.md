## [Codeforces 936B - Sleepy Game](http://codeforces.com/problemset/problem/936/B)

### 题意

给一张 $n$ 个点 $m$ 条边的有向图，问是否存在一条经过奇数条边的路径能从起点 $S$ 走到一个没有出边的点（出度为 0 的点）。如果存在输出 Win 并输出方案，如果不存在，则问是否能从 $S$ 走到一个有向环上。如果存在输出 Draw，不存在输出 Lose。

$2 \le n \le 10^5$，$0 \le m \le 2 \times 10^5$。

### 题解

维护两种标记：一种 `visit[i][0]` 表示能否从 $S$ 经过偶数条边走到点 $i$，`visit[i][1]` 表示能否从 $S$ 经过奇数条边走到点 $i$，这个用来判断是否 Win；另一种 `instack[i]` 表示点 $i$ 是否在当前 DFS 的栈内，用来判环。

DFS 一下，如果一个没有出度的点 $t$ 有 `visit[t][1] = true` 就 Win 了，否则就看看判环的结果。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/936B/sol.cpp)
