## [Codeforces 937B - Vile Grasshoppers](http://codeforces.com/problemset/problem/937/B)

### 题意

求 $1 \sim y$ 中最大的数，使得该数不能被 $2 \sim p$ 中的任何一个数整除。

### 题解

从 $y$ `for` 到 $(p+1)$，一个个检查一下就好了。每次检查的复杂度是 $O(y)$，而且质数是很密集的，至多检查几百个就会碰到答案了。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/937B/sol.c)
