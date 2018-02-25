## [Codeforces 935C - Fifa and Fafa](http://codeforces.com/problemset/problem/935/C)

### 题意

给出一个圆心为 $A(x_1, y_1)$，半径为 $R$ 的圆，再给出另一个点 $B(x_2, y_2)$。现在要求画一个圆 $C$，使得圆 $C$ 内含或内切于圆 $A$，且 $B$ 不在圆 $C$ 内部。求圆 $C$ 的最大半径以及相应的圆心位置。

$1 \le R \le 10^5$，其它坐标绝对值不超过 $10^5$。

### 题解

很显然，$C$ 应该位于 $A$ 与 $B$ 的连线上，并且 $B$ 与 $C$ 分别处于 $A$ 的两侧，而且圆 $C$ 内切于圆 $A$。

![935C 举例](https://github.com/TsReaper/Competitive-Programming/raw/master/codeforces/935C/img/sample.png)

注意特判一下 $A$ 与 $B$ 重合的情况。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/935C/sol.c)
