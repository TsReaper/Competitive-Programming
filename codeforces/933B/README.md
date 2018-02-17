## [Codeforces 933B - A Determined Cleanup](http://codeforces.com/problemset/problem/933/B)

### 题意

给出 $p$ 和 $k$，求一个多项式 $f(x)$，满足所有系数均非负，且所有系数均严格小于 $k$，并且 $f(x)$ 除以 $x+k$ 的余项是 $p$。

$1 \le p \le 10^{18}, 2 \le k \le 2000$。

### 题解

瞎推了半天式子总算是过了，果然数学还是不太行...

设 $f(x)$ 是一个 $d$ 次多项式，设 $f(x)$ 除以 $x+k$ 的商是 $g(x)$，显然 $g(x)$ 是一个 $d-1$ 次多项式。

令 $$f(x) = a_dx^d + a_{d-1}x^{d-1} + \dots + a_1x + a_0 \\ g(x) = b_{d-1}x^{d-1} + b_{d-2}x^{d-2} + \dots + b_1x + b_0$$ 我们有 $$b_{d-1} = a_d \\ b_{d-2} = a_{d-1} - ka_d \\ b_{d-3} = a_{d-2} - ka_{d-1} + k^2a_d \\ \dots \\ b_1 = a_1 - ka_2 + \dots + (-k)^{d-1}a_{d-1} \\ p = a_0 - ka_1 + \dots + (-k)^da_d$$

也就是说，多项式的系数是 $p$ 在 $-k$ 进制下的表示。发现这个事情以后就很简单了...

#### [AC 代码](https://github.com/TsReaper/Competitive-Programming/blob/master/codeforces/933B/sol.c)
