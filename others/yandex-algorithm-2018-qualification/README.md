## [Yandex Algorithm 2018 Qualification Round](https://contest.yandex.ru/algorithm2018/contest/7491)

<br/>

## A - Lottery

### 题意

给出 10 个彩票中奖号码，再给出 $n$ 张彩票，每张彩票有 6 个号码。如果一张彩票上至少有 3 个中奖号码，那么彩票就中奖了，否则没有中奖。问每张彩票是否中奖。

$1 \le n \le 1000$，所有号码范围 [1, 32]。

### 题解

简单题，模拟即可。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/others/yandex-algorithm-2018-qualification/A.c)

<br/>

## B - Permutation Recovery

### 题意

把一个 $1 \sim n^2$ 的排列填入一个 $n \times n$ 的方阵中，第一行是排列的前 $n$ 个数，第二行是排列的第 $(n+1)$ 到第 $2n$ 个数等等。

现在给出 $2n$ 个长度为 $n$ 的序列（不重复），每个序列是方阵中某一行或者某一列的内容，但是序列之间的顺序是随机的。问原来那个 $1 \sim n^2$ 的排列是什么样的。

$1 \le n \le 100$。

### 题解

首先找到第一行。这个很简单：如果有两个序列第一个数字是相同的，那么那个数字就是第一行第一列的数字，在两个序列中随便选一个作为第一行即可。

知道了第一行，也就容易知道每一列：如果有一个序列的第一个数字 $x$ 和第一行第 $j$ 列的数字相同，那一个序列就是第 $j$ 列的内容。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/others/yandex-algorithm-2018-qualification/B.c)

<br/>

## C - Beautiful Tables

### 题意

把 $1 \sim n$ 填入一个 $n \times n$ 的方阵（每种数字可以用无数次），使得每一行以及每一列的和都被 $n$ 整除。求方案数。

$1 \le n \le 1000$。

### 题解

如果前 $(n-1)$ 行每一行的和都能被 $n$ 整除，由于可以填入的数只有 $1 \sim n$，那么为了使每一列的和都能被 $n$ 整除，最后一行只有一种填入方案。

问题就是：这样填入的最后一行也会被 $n$ 整除吗？答案是肯定的：前 $(n-1)$ 行所有数字的和都能被 $n$ 整除，而全部 $n$ 列所有数字的和（就是所有填入的数字的和）也能被 $n$ 整除，那么减一减，最后一行的和当然能被 $n$ 整除啦。

所以问题就变成：在 $1 \sim n$ 中选择 $n$ 个数，使得和能被 $n$ 整除。一开始还在想怎么背包来着- -其实答案就是 $n^{n-1}$，可以自己用背包的转移方程推推看，很简单的...

那么最终答案就是 $n^{(n-1) \times (n-1)}$ 啦。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/others/yandex-algorithm-2018-qualification/C.c)

<br/>

## D - Triangle Construction

### 题意

给出长度为 $n$ 的数组 $a$，有 $q$ 个询问。每次询问能否从下标在 $[l_i, r_i]$ 范围内的元素中选出三个，使得存在一个三角形以这三个元素为边长，如果能则输出一个方案。

$1 \le n, q \le 3 \times 10^5$，$1 \le a_i \le 10^{18}$。

### 题解

无解的最差情况应该是 1, 1, 2, 3, 5, 8, ... 这种斐波那契数列，而斐波那契数列的八十几项就超过 $10^{18}$ 了。所以如果区间长度超过 100 肯定有解，否则就排个序判断一下即可。这样每次询问的复杂度都只有 100 × log100，很稳。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/others/yandex-algorithm-2018-qualification/D.cpp)

<br/>

## E - Good Snippets

### 题意

给出 $n$ 个字符串 $w_1 \sim w_n$，以及 $m$ 个互不相同的字符串 $s_1 \sim s_m$。问有多少个区间 $[l, r]$ 把 $s_1 \sim s_m$ 里的所有字符串全部包含。

字符串 $s_j$ 包含于区间 $[l, r]$，是说存在一个 $i \in [l, r]$，使得 $w_i = s_j$。

$1 \le n, m \le 10^5$，每个字符串长度不超过 10。

### 题解

Two pointers 一下就好了。枚举左端点 $l$，维护右端点 $r$，使得 $[l, r]$ 恰好满足要求，而 $[l, r-1]$ 不满足要求。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/others/yandex-algorithm-2018-qualification/E.cpp)
