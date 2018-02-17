## [Codeforces 920B - Tea Queue](http://codeforces.com/problemset/problem/920/B)

### 题意

有 $n$ 个人排队喝茶，每一秒队头的人可以打到茶水，然后离开队伍。

第 $i$ 个人会在第 $l_i$ 秒加入队尾（若两人同时加入队尾，则编号小的人排在前面），如果第 $r_i$ 秒他还没打到茶水，就会直接离开队伍。

问每个人是否打到茶水，以及打到茶水的时间。

$1 \le n \le 1000, 1 \le l_i \le r_i \le 5000$。

### 题解

$n$ 只有 1000，时间范围 $l_i, r_i$ 只有 5000。那么从第 1 秒开始枚举到第 5000 秒。

每一秒枚举所有人，把要加入队伍的人加到队尾。再看看这一秒是哪个人打茶水。如果队头的人已经超时了，那就直接踢出队伍，直到找到一个不超时的人让他打水，结束枚举。

由于每个人只会被加入或踢出队伍一次，时间复杂度主要集中在前面的枚举上，是 $O(n\max(r_i))$。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/920B/sol.cpp)
