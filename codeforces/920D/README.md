## [Codeforces 920D - Tanks](http://codeforces.com/problemset/problem/920/D)

### 题意

有 $N$ 个水箱，第 $i$ 个水箱里有 $a_i$ 的水。还有一个水瓢，每次能选择两个水箱 $x$ 和 $y$，从第 $x$ 个水箱中舀出 $\min(a_x, K)$ 的水，全部倒入第 $y$ 个水箱中。问能否在某个水箱中凑出恰好 $V$ 的水。

$2 \le N \le 5000, 1 \le K \le 5000, 0 \le V \le 10^9, 0 \le a_i \le 10^5$。

### 题解

反正每次都能舀 $K$ 的水，只要能在某个水箱中凑出 $U$ 的水使得 $U \equiv V (\text{mod } K)$，后面就有希望调整。

首先，如果所有水加起来还不够 $V$ 肯定不行了。如果 $V \text{ mod } K = 0$ 最好还是特判一下，先把所有水弄到一个水箱里，再舀出 $V$ 的水到旁边的水箱即可。

剩下的情况，只要先用背包判断一下能否凑出 $U \equiv V (\text{mod } K)$ 的水，然后把剩下的所有水舀到旁边的水箱里，再把 $U$ 改成 $V$ 即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920D/sol.cpp)
