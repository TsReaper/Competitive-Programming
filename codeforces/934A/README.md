## [Codeforces 934A - A Compatible Pair](http://codeforces.com/problemset/problem/934/A)

### 题意

有两个数组 $a_1, a_2, \dots, a_n$ 和 $b_1, b_2, \dots, b_m$，第一个人从 $a$ 中拿走一个数，第二个人在剩下的 $a$ 中选一个数，$b$ 中也选一个数乘起来得到 $c$。

第一个人想让 $c$ 最小，第二个人想让 $c$ 最大，问两人都用最优策略的情况下 $c$ 是多少。

$2 \le n, m \le 50, -10^9 \le a_i, b_i \le 10^9$。

### 题解

当然有线性的做法，不过要考虑到负负得正什么的。$n$ 只有 50，还是老老实实 $O(n^2m)$ 枚举来得妥...

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/934A/sol.cpp)
