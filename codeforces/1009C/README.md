## [Codeforces 1009C - Annoying Present](http://codeforces.com/problemset/problem/1009/C)

### 题意

一个长度为 $n$，一开始全是 0 的数组，现在对它进行 $m$ 次操作。每次操作有两个参数 $x_i$ 和 $d_i$，每次要我们自己选一个中心 $c_i$，这样经过这次操作后，数组的第 $k$ 项会增加 $x_i + |c_i - k|d_i$。

问所有操作结束后，数组的最大平均值是多少。

$1 \le n, m \le 10^5$, $-10^3 \le x_i, d_i \le 10^3$。

### 题解

每次操作一定会让数组总大小增加 $nx_i$，所以 $d_i$ 的符号才是选择中心的关键。如果 $d_i > 0$，那我们应该选择 $c_i = 1$；如果 $d_i < 0$，我们应该选择 $c_i = \left\lceil\frac{n}{2}\right\rceil$。这个很容易证明。

最好先用 long long 把数组总大小算出来以后，再除以长度得到均值。否则精度可能会有问题。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/1009C/sol.c)
