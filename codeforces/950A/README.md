## [Codeforces 950A - Left-handers, Right-handers and Ambidexters](http://codeforces.com/problemset/problem/950/A)

### 题意

有 $l$ 个人打球只用左手，$r$ 个人只用右手，$a$ 个人双手均可。现在要选出一支球队，使得队内用左手的人等于用右手的人（一个双手均可的人要么用左手，要么用右手），问球队最大人数多少。

$0 \le l, r, a \le 100$。

### 题解

若 $l+a \le r$ 则答案是 $2(l+a)$；若 $r+a \le l$ 则答案是 $2(r+a)$，否则答案是 $2\left\lfloor \frac{l+r+a}{2} \right\rfloor$。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/950A/sol.c)
