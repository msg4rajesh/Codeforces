#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))

#define MAXN (1010)
#define MAXP (100000)

#define eps 1e-8

#define mi met[i]

struct line{
    long long x0, y0, z0, tx, ty, tz;
} met[MAXN];

struct plane{
    long long nx, ny, nz, x0, y0, z0;
} pla[MAXP];

long long cross(long long x1, long long y1, long long x2, long long y2)
{
    return (x1 * y2 - x2 * y1);
}

long long dot(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2)
{
    return (x1 * x2 + y1 * y2 + z1 * z2);
}

int colla(int i, int j)
{
    line m1 = met[i];
    line m2 = met[j];
    long long nx = cross(m1.ty, m1.tz, m2.ty, m2.tz);
    long long ny = cross(m1.tz, m1.tx, m2.tz, m2.tx);
    long long nz = cross(m1.tx, m1.ty, m2.tx, m2.ty);
    int qx = m2.x0 - m1.x0;
    int qy = m2.y0 - m1.y0;
    int qz = m2.z0 - m1.z0;
    if (dot3(nx, ny, nz, qx, qy, qz) == 0))
        return 1;
    else
        return 0;
}

plane norm(int i, int j)
{
    line m1 = met[i];
    line m2 = met[j];
    long long nx = cross(m1.ty, m1.tz, m2.ty, m2.tz);
    long long ny = cross(m1.tz, m1.tx, m2.tz, m2.tx);
    long long nz = cross(m1.tx, m1.ty, m2.tx, m2.ty);
    plane rst;
    rst.x0 = m1.x0;
    rst.y0 = m1.y0;
    rst.z0 = m1.z0;
    rst.nx = nx;
    rst.ny = ny;
    rst.nz = nz;
}

int main()
{
    using namespace std;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mi.x0 >> mi.y0 >> mi.z0 >> mi.tx >> mi.ty >> mi.tz;
        mi.tx = mi.x0 - mi.tx;
        mi.ty = mi.y0 - mi.ty;
        mi.tz = mi.z0 - mi.tz;
    }
    int p = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (colla(i, j))
                pla[p++] = norm(i, j);
