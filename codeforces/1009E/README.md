## [Codeforces 1009E - Intercity Travelling](http://codeforces.com/problemset/problem/1009/E)

### 题意

有 $n$ 条边将 $(n+1)$ 个点连成一条链（点 1 - 边 1 - 点 2 - 边 2 ... 边 $n$ - 点 $(n+1)$），第 1 个点是红点，第 2～n 个点每个点有 50% 的概率是红点，50% 的概率是黑点，最后一个点的颜色不重要。

对于第 $i$ 条边，设它左边最靠近它的红点是第 $j$ 个点，那么这条边的代价是 $a_{i-j}$。给出数组 $a$，求所有边代价之和的期望 $\mathbb{E}$。输出 $2^{n-1}\mathbb{E} \mod 998244353$。

$1 \le n \le 10^6, 1 \le a_i \le 10^6$。

### 题解

考虑第 $i$ 条边对答案的贡献。有 $2^{n-2}$ 种情况它的代价是 $a_1$，$2^{n-3}$ 种情况它的代价是 $a_2$，...，$2^{n-i+1}$ 种情况它的代价是 $a_{i-2}$，$2^{n-i}$ 种情况它的代价是 $a_{i-1}$，以及 $2^{n-i}$ 种情况它的代价是 $a_i$。

所以，记 $S_k = \displaystyle\sum_{i=1}^k 2^{n-1-i}a_i$，那么第 $i$ 条边对答案的贡献就是 $S_{i-1} + 2^{n-i}a_i$。把每条边的贡献加起来就是答案。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/1009E/sol.c)
