## [Codeforces 920F - SUM and REPLACE](http://codeforces.com/problemset/problem/920/F)

### 题意

令 $D(x)$ 表示 $x$ 的因数个数。有一个 $n$ 个元素的数组 $a$，要求支持以下操作：
1. `REPLACE l r`：对于 $i \in [l, r]$，把 $a_i$ 都变成 $D(a_i)$；
2. `SUM l r`：求 $\displaystyle\sum_{i=l}^r a_i$。

$1 \le n \le 3 \times 10^5$，操作数至多 $3 \times 10^5$，$1 \le a_i \le 10^6$。

### 题解

经典套路了。一个数的因数个数是根号级的，不用 `REPLACE` 几次这个数就变成 1 或者 2 了。

用线段树维护数组，`REPLACE` 就暴力进行，如果一个区间里只有 1 或者 2 就不用继续递归下去了。查询就普通地线段树查询即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920F/sol.cpp)
