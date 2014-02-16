#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

#define MAXN (1010)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))

using namespace std;

struct line{
    int x1, y1, x2, y2;
} h[MAXN], v[MAXN];

int interact(line v, line h)
{
    if (h.x1 >= v.x1 || h.x2 <= v.x1)
        return 0;
    if (v.y1 >= h.y1 || v.y2 <= h.y2)
        return 0;
    return 1;
}

int calc(line v, line h)
{
    int xc = v.x1, yc = h.y1;
    int rst = 123456789;
    rst = min(rst, abs(v.x1 - xc) + abs(v.y1 - yc));
    rst = min(rst, abs(h.x1 - xc) + abs(h.y1 - yc));
    rst = min(rst, abs(v.x2 - xc) + abs(v.y2 - yc));
    rst = min(rst, abs(h.x2 - xc) + abs(h.y2 - yc));
    return rst;
}

int main()
{
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x1 >> v[i].y1 >> tmp;
        v[i].x2 = v[i].x1;
        v[i].y2 = v[i].y1 + tmp;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> h[i].x1 >> h[i].y1 >> tmp;
        h[i].x2 = h[i].x1 + tmp;
        h[i].y2 = h[i].y1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (interact(v[i], h[j]))
                ans = max(ans, calc(v[i], h[j]));
    cout << ans << endl;

    return 0;
}
