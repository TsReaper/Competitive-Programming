#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// === Geometry start ===

typedef long double LD;
const LD EPS = 1e-9;

int dcmp(LD x)
{
    if(fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}

LD sqr(LD x) { return x * x; }

LD range(LD x,LD l,LD r) { return x < l ? l : (x > r ? r : x); }

struct Point
{
    LD x,y;
    Point(LD x = 0,LD y = 0):x(x),y(y) {}
};

bool operator == (const Point &A,const Point &B) { return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0; }

Point operator + (const Point &A,const Point &B) { return Point(A.x+B.x,A.y+B.y); }

Point operator - (const Point &A,const Point &B) { return Point(A.x-B.x,A.y-B.y); }

Point operator * (const Point &A,LD k) { return Point(A.x*k,A.y*k); }

Point operator / (const Point &A,LD k) { return Point(A.x/k,A.y/k); }

bool operator < (const Point &A,const Point &B) { return dcmp(A.x-B.x) < 0 || (dcmp(A.x-B.x) == 0 && dcmp(A.y - B.y) < 0); }

LD Dot(const Point &A,const Point &B) { return A.x*B.x + A.y*B.y; }

LD Length(const Point &A) { return sqrt(Dot(A,A)); }

Point Norm(const Point &A) { return A/Length(A); }

Point Rot(const Point &A) { return Point(-A.y,A.x); }

struct Circle
{
    Point c;
    LD r;
    Circle() {}
    Circle(LD x,LD y,LD r):c(Point(x,y)),r(r) {}
    Circle(Point c,LD r):c(c),r(r) {}
};

int CircleIntersect(const Circle &C1,const Circle &C2,vector<Point> &res)
{
    LD r1 = C1.r, r2 = C2.r;
    LD d = Length(C1.c - C2.c);
    if(dcmp(fabs(r1-r2) - d) > 0 || dcmp(r1+r2 - d) < 0) return 0;
    LD l = 0.5*(d+(r1*r1-r2*r2)/d);
    LD h = sqrt(r1*r1-l*l);
    Point O1 = C1.c, O2 = C2.c, A = O1 + Norm(O2-O1)*l, B = Norm(Rot(O2-O1))*h;

    if(dcmp(d - (r1+r2)) == 0 || dcmp(d - fabs(r1-r2)) == 0)
    {
        res.push_back(A);
        return 1;
    }
    else
    {
        res.push_back(A+B); res.push_back(A-B);
        return 2;
    }
}

// === Geometry end ===

int tcase,n,m,ans,X[55],Y[55],R[55];
Circle circle[55];

int root[55];
vector<Point> inter[55];

int findroot(int nod)
{
    if(root[nod] != nod) root[nod] = findroot(root[nod]);
    return root[nod];
}

void merge(int x,int y)
{
    x = findroot(x); y = findroot(y);
    if(x == y) return;
    root[y] = x;
}

int count(vector<Point> &vec)
{
    int i,ret = 0;
    sort(vec.begin(),vec.end());
    for(i=0;i<vec.size();i++)
        ret += (i == 0 || !(vec[i-1] == vec[i]));
    return ret;
}

int main()
{
    int i,j;
    vector<Point> t;

    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d",&m); n = 0;
        for(i=1;i<=m;i++) scanf("%d%d%d",&X[i],&Y[i],&R[i]);
        for(i=1;i<=m;i++)
        {
            for(j=1;j<i;j++) if(X[i] == X[j] && Y[i] == Y[j] && R[i] == R[j]) break;
            if(j < i) continue;
            circle[++n] = Circle(X[i],Y[i],R[i]);
        }
        for(i=1;i<=n;i++) root[i] = i, inter[i].clear();

        for(i=1;i<=n;i++) for(j=i+1;j<=n;j++)
        {
            t.clear();
            if(CircleIntersect(circle[i],circle[j],t)) merge(i,j);
            inter[i].insert(inter[i].end(),t.begin(),t.end());
            inter[j].insert(inter[j].end(),t.begin(),t.end());
        }

        ans = 1; t.clear();
        for(i=1;i<=n;i++) if(findroot(i) == i) ans++;
        for(i=1;i<=n;i++) ans += count(inter[i]), t.insert(t.end(),inter[i].begin(),inter[i].end());
        ans -= count(t);
        printf("%d\n",ans);
    }

    return 0;
}
