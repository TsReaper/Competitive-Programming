## [Codeforces 950B - Intercepted Message](http://codeforces.com/problemset/problem/950/B)

### 题意

有 $k$ 个文件，大小分别为 $l_1, l_2, \dots, l_k$。每个文件在网络上传输时，可能会被拆成很多包 $b_{i, 1}, b_{i, 2}, \dots, b_{i, m_i}$，当然包大小的总和等于这个文件。

现在给出两个长度为 $n$ 和 $m$ 的文件传续的包序列。每个文件的分包方式可能不同，但是文件传输顺序是不变的。问最多可能有多少文件。

$1 \le n, m \le 10^5$，包大小总和不超过 $10^6$。

### 题解

每个序列维护一个“当前”指针，哪个指针的前缀和小，那个指针就前进一步。当两个指针的前缀和相同时，说明都传输了一个文件，答案 + 1。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/950B/sol.c)
