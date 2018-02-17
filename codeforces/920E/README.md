## [Codeforces 920E - Connected Components?](http://codeforces.com/problemset/problem/920/E)

### 题意

给出一张 $n$ 个点的无向图，这张无向图是一张完全图去掉 $m$ 条边后得到的。问这张图里有几个连通块，每个连通块有几个点。

$1 \le n \le 2\times 10^5, 0 \le m \le \min(\frac{n(n-1)}{2}, 2\times 10^5)$。

### 题解

我自己的做法如下：维护一个 vector（一开始是空的），从点 1 枚举到点 n。枚举第 $i$ 个点时和 vector 里所有的点比较，如果与 vector 里的点有连边就用并查集把边连上，如果与 vector 里的点都没有连边就把点 $i$ 加入 vector。

由于只有 $m$ 条边不在图里，vector 里至多只有 $\sqrt{m}$ 个点，那么枚举并维护 vector 的复杂度是 $O(n\sqrt{m})$。

假设 vector 里有 $k$ 个点，我们已经知道至多有 $k$ 个连通块了。但是这 $k$ 个连通块之间还会不会有连边呢？我们暴力枚举每对连通块，假设枚举到第 $i$ 和第 $j$ 个连通块，我们就枚举第 $i$ 个连通块里的点 $x$ 和第 $j$ 个连通块里的点 $y$。如果 $x$ 和 $y$ 之间有连边，说明连通块 $i$ 和 $j$ 其实是连通的，我们就可以检查下一对连通块了。由于至多只有 $m$ 条边不在图中，而 $k$ 至多为 $\sqrt{m}$，所以这部分的复杂度是 $O(m)$。

所以总复杂度就是 $O(n\sqrt{m} + m)$。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920E/sol_my.cpp)

不过官方题解里的做法更漂亮：用一个 set 维护还没有 visit 的点，dfs 的时候每次从 set 里按编号从小到大取点。由于至多只有 $m$ 条边不在图中，取到的点不能走的情况至多只会发生 $m$ 次。那么复杂度就是 $O((n+m)\log n)$。

写代码的时候注意不要用 `for` 循环来枚举 set，而是每次都用 `upper_bound` 取出比当前元素大的下一个元素。因为枚举过程中 set 会改变，如果用 `for` 循环那么可能会跑到非法内存中去。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920E/sol_std.cpp)
