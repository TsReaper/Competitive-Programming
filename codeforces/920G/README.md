## [Codeforces 920G - List of Integers](http://codeforces.com/problemset/problem/920/G)

### 题意

令 $L(x, p)$ 表示一个无穷长的递增数组，里面的元素都大于 $x$，且都和 $p$ 互质。给出 $x$, $p$ 和 $k$，求 $L(x, p)$ 中的第 $k$ 项。

$1 \le x, p, k \le 10^6$，30000 个询问。

### 题解

二分答案。问题就变成了：小等于 $x$ 的数里，有几个数和 $p$ 互质。

本来以为一个数的质因数是 log 级的，后来打个表发现 $10^6$ 以内的数质因数至多只有 7 个，那就随便容斥了。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920G/sol.cpp)
