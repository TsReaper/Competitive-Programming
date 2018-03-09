## [Codeforces 949B - A Leapfrog in the Array](http://codeforces.com/problemset/problem/949/B)

### 题意

一个长度为 $(2n-1)$ 的数组，奇数位放着 $1, 2, \dots, n$，偶数位空白。每一次操作选择最靠右的非空白元素 $x$，并把它移动到 $x$ 左边而且最靠近 $x$ 的空白位中。持续进行操作，直到最前面 $n$ 个位置都被占据。

现在进行 $q$ 个询问，每次询问所有操作完成后，某个位置 $m$ 里是什么元素。

$1 \le n 10^{18}$, $1 \le q \le 2 \times 10^5$。

### 题解

不难发现，在一个元素填入从右往左数第 $i$ 个空白（也就是数组中第 $2(n-i)$ 位）之前，第 $(2(n-i)+1)$ 到第 $(2(n-i)+i)$ 位全部都有元素占据，而且这个空白接下来会被第 $(2(n-i)+i)$ 位上的元素占据。

那么我们反推这个过程：第 $m$ 个位置如果是空白，那么就找到 $(2n-m)$ 的位置，如果有元素那么我们就找到了答案，否则继续按这个规律往下找。容易发现，每次询问的复杂度是 $O(\log n)$。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/949B/sol.cpp)
