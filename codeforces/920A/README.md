## [Codeforces 920A - Water The Garden](http://codeforces.com/problemset/problem/920/A)

### 题意

有一个长度为 $n$ 的花圃，其中有 $k$ 个位置有水龙头。打开位于 $x_i$ 水龙头后 $t$s，$[x_i-t+1, x_i+t-1]$ 的位置都会被浇到水。问同时打开所有水龙头后，至少多久才能把所有位置都浇到水。

$1 \le k \le n \le 200$。

### 题解

枚举每个位置，找一下离每个位置最近的水龙头，取个 max 即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920A/sol.cpp)
