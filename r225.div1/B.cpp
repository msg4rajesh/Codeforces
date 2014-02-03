#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAXM (100100)

using namespace std;

struct voc
{
    int x, y, id;
} a[MAXM];

struct edge
{
    int v, next;
} e[MAXM * 8];

int v[MAXM], eptr = 1;

void e_add(int x, int y)
{
    e[eptr].next = v[x];
    e[eptr].v = y;
    v[x] = eptr++;
}

void add(int x, int y)
{
    //cout << x << ' ' << y << endl;
    e_add(x, y);
    e_add(y, x);
}

int cmp1(voc a, voc b)
{
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

int cmp2(voc a, voc b)
{
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
}

int cmp3(voc a, voc b)
{
    return (a.y + a.x < b.y + b.x || (a.y + a.x == b.y + b.x && a.x < b.x));
}

int cmp4(voc a, voc b)
{
    return (a.y - a.x < b.y - b.x || (a.y - a.x == b.y - b.x && a.x < b.x));
}

int src, tar;
int vst[MAXM];
int findpath(int x)
{
    vst[x] = 1;
    if (x == tar) return 1;
    for (int i = v[x]; i; i = e[i].next)
        if (!vst[e[i].v])
            if (findpath(e[i].v)) return 1;
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(v, 0, sizeof(v));
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
    }
    //for (int i = 0; i < m; i++) cout << a[i].x << ' ' << a[i].y << ' ' << a[i].id << endl;
    sort(a, a + m, cmp1);
    for (int i = 0; i < m - 1; i++)
        if (a[i].x == a[i + 1].x && a[i].y + 1 == a[i + 1].y)
            add(a[i].id, a[i + 1].id);
    //for (int i = 0; i < m; i++) cout << a[i].x << ' ' << a[i].y << ' ' << a[i].id << endl;
    sort(a, a + m, cmp2);
    for (int i = 0; i < m - 1; i++)
        if (a[i].y == a[i + 1].y && a[i].x + 1 == a[i + 1].x)
            add(a[i].id, a[i + 1].id);
    //for (int i = 0; i < m; i++) cout << a[i].x << ' ' << a[i].y << ' ' << a[i].id << endl;
    sort(a, a + m, cmp3);
    for (int i = 0; i < m - 1; i++)
        if (a[i].x == a[i + 1].x - 1 && a[i].y - 1 == a[i + 1].y)
            add(a[i].id, a[i + 1].id);
    //for (int i = 0; i < m; i++) cout << a[i].x << ' ' << a[i].y << ' ' << a[i].id << endl;
    sort(a, a + m, cmp4);
    for (int i = 0; i < m - 1; i++)
        if (a[i].x == a[i + 1].x - 1 && a[i].y + 1 == a[i + 1].y)
            add(a[i].id, a[i + 1].id);
    //for (int i = 0; i < m; i++) cout << a[i].x << ' ' << a[i].y << ' ' << a[i].id << endl;
    src = m + 1, tar = m + 2;
    m += 2;
    for (int i = 0; i < m; i++)
    {
        if (a[i].y == n || a[i].x == 1)
            add(src, a[i].id);
        if (a[i].y == 1 || a[i].x == n)
            add(tar, a[i].id);
    }
    memset(vst, 0, sizeof(vst));
    if (!findpath(src))
        cout << (n - 1) * 2 << endl;
    else
        cout << -1 << endl;
    return 0;
}
