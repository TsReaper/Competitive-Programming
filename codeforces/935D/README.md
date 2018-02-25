## [Codeforces 935D - Fafa and Ancient Alphabet](http://codeforces.com/problemset/problem/935/D)

### 题意

给出两个长度为 $n$ 的序列 $a$ 和 $b$，序列中的元素范围是 $1 \sim m$。如果 $a_i = 0$ 则表示 $a_i$ 会随机取一个 $1 \sim m$ 的数（$b_i = 0$ 也类似）。问序列 $a$ 字典序大于序列 $b$ 的概率是多少。

$1 \le n, m \le 10^5$。

### 题解

分类讨论：
* 如果 $a_i \ne 0$ 且 $b_i \ne 0$，那就直接判断，结束；
* 如果 $a_i \ne 0$ 且 $b_i = 0$，那么有 $\frac{a_i-1}{m}$ 的概率 $a$ 比 $b$ 大，另外有 $\frac{1}{m}$ 的概率 $a_i$ 和 $b_i$ 一样，此时要往下看一位继续判断；
* 如果 $a_i = 0$ 且 $b_i \ne 0$，那么有 $\frac{m-b_i}{m}$ 的概率 $a$ 比 $b$ 大，另外有 $\frac{1}{m}$ 的概率 $a_i$ 和 $b_i$ 一样，此时要往下看一位继续判断；
* 如果 $a_i = b_i = 0$，那么有 $\frac{1 + 2 + \dots + (m-1)}{m^2} = \frac{m-1}{2m}$ 的概率 $a$ 比 $b$ 大，另外有 $\frac{1}{m}$ 的概率 $a_i$ 和 $b_i$ 一样，此时要往下看一位继续判断。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/935D/sol.c)
