## [Codeforces 949A - Zebras](http://codeforces.com/problemset/problem/949/A)

### 题意

称以 0 开头，以 0 结尾，中间 01 相间的序列为 zebra。现在给一个 01 串，问能否把这个 01 串拆成若干个 zebra，每个元素必须且只能用一次。

序列长度不超过 $2 \times 10^5$。

### 题解

每次都接在一个尽量靠左的元素的后面即可。用两个队列维护一下后面可以接元素的 0 和 1 的位置即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/949A/sol.cpp)
