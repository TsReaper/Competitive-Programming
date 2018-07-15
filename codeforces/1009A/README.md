## [Codeforces 1009A - Game Shopping](http://codeforces.com/problemset/problem/1009/A)

### 题意

有 $n$ 件物品和 $m$ 张钞票，按顺序给出。

现在尝试按从第一件到最后一件的顺序购买物品。首先拿出第一张钞票。若当前钞票的面额不小于当前尝试购买的物品的价值，则购买成功，钞票消失（不找零），拿出下一张钞票并尝试购买下一件物品；否则购买失败，直接尝试购买下一件物品，当前钞票不变。

问一共能买几件物品。

$1 \le n, m \le 1000$，物品价格和钞票面额不超过 1000。

### 题解

按题意模拟即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/1009A/sol.c)
