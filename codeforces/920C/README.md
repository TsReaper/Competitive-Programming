## [Codeforces 920C - Swap Adjacent Elements](http://codeforces.com/problemset/problem/920/C)

### 题意

给一个 $1 \sim n$ 的排列，再给出 $b_1, b_2, \dots, b_n$，若 $b_i = 1$ 则表示允许第 $i$ 个位置的数和第 $(i+1)$ 个位置的数交换，否则就不允许。问是否能够通过交换把这个排列变成升序的。

$1 \le n \le 2 \times 10^5$。

### 题解

很显然，必须要先把 1 放回第 1 个位置，再把 2 放回第二个位置，再...

所以重点是确定把前 $k$ 个数归位后，第 $(k+1)$ 个数在哪。不难发现，如果原排列中第 $(k+1)$ 个数的后面有 $x$ 个比它小的数，那么前 $k$ 个数归位后，第 $(k+1)$ 个数就会在 $(k+1+t)$ 的位置。这样，只要 $b_{k+1} \sim b_{k+t}$ 都是 1，第 $(k+1)$ 个数也能顺利归位。

用树状数组维护一下原排列中，每个数的后面有几个比它小的数即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920C/sol.cpp)
