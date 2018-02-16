## [Codeforces 934B - A Prosperous Lot](http://codeforces.com/problemset/problem/934/B)

### 题意

给定 $k$，求一个不超过 $10^{18}$ 的正数，使得这个数的十进制表示恰有 $k$ 个封闭区域。

例如，0 有一个封闭区域，8 有两个，6 有一个等等...

### 题解

一个数码最多只有两个封闭区域，超过 36 个就无解了；否则看一下 $k$ 是奇数还是偶数，输出 88...88 还是 88...89。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/934B/sol.c)
