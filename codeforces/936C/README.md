## [Codeforces 936C - Lock Puzzle](http://codeforces.com/problemset/problem/936/C)

### 题意

定义在字符串上操作 `shift(x)`：设操作前的字符串 $s = \alpha\beta$，其中 $\beta$ 长度为 $x$；则操作后 $s$ 变为 $\beta^R\alpha$，其中 $\beta^R$ 表示把 $\beta$ 反过来。比如在 abcacb 上 `shift(4)` 则获得 bcacab。

给出一个初始字符串，要求使用至多 6100 次操作把它变成目标串。

字符串长度不超过 2000。

### 题解

我们先考虑一个简单点的问题，如果想要把一个字符放到一个已经构造好的前缀后面，应该怎么操作呢？

![936C 构造](https://github.com/TsReaper/Competitive-Programming/raw/master/codeforces/936C/img/shift.png)

如上图所示进行操作即可。但要注意的是，原来的前缀被倒了过来。

如果我们能把字符这样一个一个接上去，我们就能构造出答案了（每接一个字符至多 3 步，这样只要 $3n = 6000$ 步就解决了，在限制范围内）。问题是：每一步应该接哪个字符呢？

我们只要考虑，每一步接进去的那个字符，最终会在哪个位置就知道了。按照类似的方法，我们不难发现，$n = 2$ 时，位置数组是 1 2；$n = 3$ 时，位置数组是 2 1 3；$n = 4$ 时，位置数组是 3 1 2 4... 用 $O(n^2)$ 的复杂度把位置数组算出来就可以了。

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/936C/sol.c)
