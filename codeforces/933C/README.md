## [Codeforces 933C - A Colourful Prospect](http://codeforces.com/problemset/problem/933/C)

### 题意

给出平面上 $n$ 个圆的圆心和半径，问这些圆把平面分成几个部分。保证没有相同的圆。

$1 \le n \le 3$，坐标绝对值不超过 10，半径不超过 10。

### 题解

比赛的时候看到 $n \le 3$ 而且坐标范围只有 10，打算瞎搞过去，不过数据特别强，甚至还有面积小于 1e-6 的区域，很猛...可惜的是这个题是 [Timus 1429](http://acm.timus.ru/problem.aspx?space=1&num=1429) 和 [ZOJ 2589](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2589) 的简化版，开场 3 分钟就有人过了。

欧拉公式的应用，学完离散之后就不记得这个东西了...

平面图的欧拉公式就是 $F+V-E-C = 1$，其中 $F$ 是平面图把平面分成的区域数，$V$ 是平面图的点数，$E$ 是平面图的边数，$C$ 是平面图的连通块数。

我们先 $O(n^2)$ 地求出圆之间的交点。容易发现，如果一个圆和别的圆有 $k$ 个交点，那么这个圆给平面图贡献了 $k$ 条边。要注意的是，交点可能有重复，所以统计每个圆上的交点数量，以及整张平面图的点数时需要去重。连通块数用并查集维护一下就好了。

似乎分类讨论也是可以的，不过感觉更麻烦...

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/933C/sol.cpp)
