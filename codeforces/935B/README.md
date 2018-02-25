## [Codeforces 935B - Fafa and the Gates](http://codeforces.com/problemset/problem/935/B)

### 题意

一个人从 (0, 0) 出发，如果从 $y > x$ 的位置穿过 $y = x$ 走到 $y < x$（或者反过来）则加 1 分。这个人每次只会向上走一步 ($y + 1$) 或者向右走一步 ($x + 1$)。给出他 $n$ 步的行走序列，问这个人得了多少分。

$2 \le n \le 10^5$。

### 题解

从第 3 步开始判，如果第 $i$ 步和第 $(i-2)$ 步结束位置都不在 $y = x$ 上，且两步结束位置分别位于 $y = x$ 两边则得 1 分。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/935B/sol.c)
