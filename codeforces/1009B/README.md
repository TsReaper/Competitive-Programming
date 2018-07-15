## [Codeforces 1009B - Minimum Ternary String](http://codeforces.com/problemset/problem/1009/B)

### 题意

给出一个由 0, 1, 2 组成的字符串。相邻的 0 和 1 可以互换，相邻的 1 和 2 也可以互换。求经过若干次交换后（也可以不进行任何交换）获得的字典序最小的字符串。

字符串长度不超过 $10^5$。

### 题解

1 可以在字符串里随意移动，而 0 和 2 的相对位置则不能互换。所以我们先找出原字符串去掉 1 之后的子序列，然后把所有的 1 插到第一段连续的 0 之后即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/1009B/sol.c)
