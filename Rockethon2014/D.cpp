#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAXN (350010)
#define RAWN (90010)
#define linf (2147483647)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))

#define lChild(i) (((i) << 1))
#define rChild(i) (((i) << 1) + 1)
#define parent(i) ((i) >> 1)
#define leaf(i) ((i) + inners)
#define isLeaf(i) ((i) >= inners)
#define isLChild(i) (!((i) & 1))
#define isRChild(i) (((i) & 1))

using namespace std;

struct line{
    int x1, y1, x2, y2;
} h[RAWN], v[RAWN];

int n, p, q, m, inners;
int rn, rm, tmp;

struct STNode
{
    int cnt; 
} st[MAXN];

inline void refresh(int x)
{
    if (!isLeaf(x))
        st[x].cnt = st[lChild(x)].cnt + st[rChild(x)].cnt;
}

void insert(int xp, int val)
{
    while (xp > 0)
    {
        st[xp].cnt += val;
        xp = xp >> 1;
    }
}

int count(int lp, int rp)
{
    int rst = 0;
    while (lp < rp - 1)
    {
        if (isLChild(lp))
            rst += st[lp + 1].cnt;
        if (isRChild(rp))
            rst += st[rp - 1].cnt;
        lp = parent(lp);
        rp = parent(rp);
    }
    return rst;
}

inline void st_init(int nd)
{
    n = nd;
    inners = 1;
    while (inners < n + 2)
        inners *= 2;
    memset(st, 0, sizeof(st));
}

struct event{
    int l, r, h;
    int type; // I Q O
} eve[MAXN];
int ne = 0;
int xs[MAXN];
int clr[MAXN];
int nx = 0, nd = 0;

inline void add_x(int x)
{
    xs[nx++] = x;
}

inline void add_eve(int l, int r, int h, int type)
{
    eve[ne].l = l;
    eve[ne].r = r;
    eve[ne].h = h;
    eve[ne].type = type;
    ne++;
}

int get_clr(int x)
{
    int lb = 0, rb = nx, mid;
    while (lb < rb - 1)
    {
        mid = (lb + rb) / 2;
        if (xs[mid] < x)
            lb = mid;
        else if (xs[mid] > x)
            rb = mid;
        else
            return clr[mid];
    }
    return clr[lb];
}

int eve_cmp(event a, event b)
{
    if (a.h < b.h)
        return true;
    if (a.h > b.h)
        return false;
    if (a.type < b.type)
        return true;
    if (a.type > b.type)
        return false;
    if (a.l < b.l)
        return true;
    if (a.l > b.l)
        return false;
    if (a.r < b.r)
        return true;
    return false;
}

int check(int ans)
{
    ne = 0;
    nx = 0;
    for (int i = 0; i < rn; i++)
    {
        if (v[i].y2 - v[i].y1 >= ans + ans)
        {
            add_eve(v[i].x1, v[i].x1, v[i].y1 + ans, 0);
            add_eve(v[i].x1, v[i].x1, v[i].y2 - ans, 2);
            add_x(v[i].x1);
        }
    }
    for (int i = 0; i < rm; i++)
    {
        if (h[i].x2 - h[i].x1 >= ans + ans)
        {
            add_eve(h[i].x1 + ans, h[i].x2 - ans, h[i].y1, 1);
            add_x(h[i].x1 + ans);
            add_x(h[i].x2 - ans);
        }
    }
    sort(xs, xs + nx);
    xs[nx] = linf;
    nd = 1;
    clr[0] = 1;
    for (int i = 1; i <= nx; i++)
    {
        if (xs[i] != xs[i - 1])
            nd++;
        clr[i] = nd;
    }
    nd++;
    st_init(nd);
    for (int i = 0; i < ne; i++)
    {
        eve[i].l = get_clr(eve[i].l);
        eve[i].r = get_clr(eve[i].r);
    }
    sort(eve, eve + ne, eve_cmp);
    for (int i = 0; i < ne; i++)
    {
        if (eve[i].type == 0)
        {
            insert(leaf(eve[i].l), 1);
        }
        else if (eve[i].type == 1)
        {
            if (count(leaf(eve[i].l - 1), leaf(eve[i].r + 1)) > 0)
                return 1;
        }
        else
        {
            insert(leaf(eve[i].l), -1);
        }
    }
    return 0;
}

int main()
{
    cin >> rn >> rm;
    for (int i = 0; i < rn; i++)
    {
        cin >> v[i].x1 >> v[i].y1 >> tmp;
        v[i].x2 = v[i].x1;
        v[i].y2 = v[i].y1 + tmp;
    }
    for (int i = 0; i < rm; i++)
    {
        cin >> h[i].x1 >> h[i].y1 >> tmp;
        h[i].x2 = h[i].x1 + tmp;
        h[i].y2 = h[i].y1;
    }

    int lb = 0, rb = 200000000, mid;
    while (lb < rb - 1)
    {
        mid = (lb + rb) / 2;
        if (check(mid))
            lb = mid;
        else
            rb = mid;
    }
    cout << lb << endl;

    return 0;
}
