## [Codeforces 936A - Save Energy!](http://codeforces.com/problemset/problem/936/A)

### 题意

一个炉子每煮饭 $k$ 分钟就会自动关闭（关闭以后炉子还有余温），一个人每 $d$ 分钟来看一下，如果炉子是关的就会开起来。如果炉子一直开着，饭煮熟要 $t$ 分钟，如果炉子一直关着，饭煮熟要 $2t$ 分钟。问饭多久才熟。

$1 \le k, d, t \le 10^{18}$。

### 题解

以 $d \left \lceil \frac{k}{d} \right \rceil$ 为周期，计算一下一个周期内炉子开着多少时间，关闭多少时间。再特判一下最后一个周期要煮饭多久即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/936A/sol.c)
