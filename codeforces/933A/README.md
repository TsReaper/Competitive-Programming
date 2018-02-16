## [Codeforces 933A - A Twisty Movement](http://codeforces.com/problemset/problem/933/A)

### 题意

给出一个只含 1 和 2 的序列，允许颠倒一段连续的区间，问颠倒后最长的不降子序列的长度是多少。

### 题解

很显然，不降子序列是形如 1 1 ... 1 2 2 ... 2 的。

比赛的时候写了 $O(n^2)$ 的做法。如果遇到 1 就 +1，遇到 2 就 -1，那么最佳答案就是 2 的数量加上最大的前缀和。那么枚举要颠倒的区间，分情况求一下区间最大值即可。区间最大值可以在一开始 $O(n^2)$ 预处理一下。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/933A/sol_n2.cpp)

赛后发现一个更优美的做法，甚至还是 $O(n)$ 的。

最优答案在颠倒前无非就是四种情况：
1 1 ... 1，
1 1 ... 1 2 2 ... 2，
1 1 ... 1 2 2 ... 2 1 1 ... 1，
1 1 ... 1 2 2 ... 2 1 1 ... 1 2 2 ... 2，
DP 一下每种序列的最大长度，由于后面的序列包含前面的序列，那么答案就是最后一种序列的最大长度。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/933A/sol_n.cpp)
