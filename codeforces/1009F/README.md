## [Codeforces 1009F - Dominant Indices](http://codeforces.com/problemset/problem/1009/F)

### 题意

对一棵树中的点 $x$，定义一个无限长的数组 $d_{x, 0}, d_{x, 1}, d_{x, 2} \dots$，其中 $d_{x, i}$ 表示以 $x$ 为根的子树内，深度为 $i$ 的点的数量。

对于一个数组 $a$，定义 dominant index $j$ 为满足以下条件的整数：
* 对于所有 $k < j$，有 $a_k < a_j$；
* 对于所有 $k > j$，有 $a_k \le a_j$。

求这棵树每个点 $d$ 数组的 dominant index。

点数 $\le 10^6$。

### 题解

$d$ 数组后面都是 0，只要维护前面非 0 的元素即可。

使用启发式合并进行维护。设较长的数组长度为 $x$，较短的数组长度为 $y$。我们可以在合并过程中算出结果数组前 $y$ 项的值，以及只考虑前 $y$ 项的 dominant index。

因为结果数组第 $(y+1)$ 到第 $x$ 项不变，所以原数组的 dominant index 只要直接和结果数组前 $y$ 项的 dominant index 比一下元素大小，即可直接确定新的 dominant index。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/1009F/sol.cpp)
