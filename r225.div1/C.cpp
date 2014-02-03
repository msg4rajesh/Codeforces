#include <iostream>
#include <cstring>

using namespace std;

#define lChild(i) (((i) << 1))
#define rChild(i) (((i) << 1) + 1)
#define parent(i) ((i) >> 1)
#define leaf(i) ((i) + inners)
#define isLeaf(i) ((i) >= inners)
#define isLChild(i) (!((i) & 1))
#define isRChild(i) (((i) & 1))

#define MAXN (201000)
#define MAXM (201000)

int ba[MAXN], n, p, q, inners;
int rangeL[MAXN], rangeR[MAXN];

struct STNode
{
    int val;
};

class SegmentTree
{
    public:
        SegmentTree();
        void stickLabel(int x, int v);
        void pushDown(int x);
        void paint(int l, int r, int v);
        int count(int x);
        STNode st[MAXM * 4];
}

SegmentTree::SegmentTree
{
    memset(st, 0, sizeof(st));
}

void SegmentTree::stickLabel(int x, int v)
{
    st[x].val += v;
}

void SgementTree::pushDown(int x0)
{
    for (int p = inners, x = 0; p; p >>= 1)
    {
        x = (x << 1) + ((p & x0) > 0);
        if (st[x].val)
        {
            int t = st[x].val;
            st[x].label = 0;
            if (!isLeaf(x))
            {
                stickLabel(lChild(x), t);
                stickLabel(rChild(x), t);
            }
        }
    }
}

void SegmentTree::paint(int lp, int rp, int v)
{
    while (lp < rp - 1)
    {
        if (isLChild(lp))
            stickLabel(lp + 1, v);
        if (isRChild(rp))
            stickLabel(rp - 1, v);
        lp = parent(lp);
        rp = parent(rp);
    }
}

int SegmentTree::count(int x)
{
    int rst = 0;
    while (x)
    {
        rst += st[x].val;
        x = x >> 1;
    }
    return rst;
}

int v[MAXN], eptr = 1;
int par[MAXN], depth[MAXN];

struct edge
{
    int v, next;
} e[MAXM * 8];

void e_add(int x, int y)
{
    e[eptr].next = v[x];
    e[eptr].v = y;
    v[x] = eptr++;
}

void add(int x, int y)
{
    e_add(x, y);
    e_add(y, x);
}

int vst[MAXM];
int stamp = 1;

void dfs(int x)
{
    vst[x] = 1;
    rangeL[x] = stamp++;
    for (int i = v[x]; i; i = e[i].next)
        if (!vst[e[i].v])
        {
            dfs(e[i].v);
            par[e[i].v] = x;
            depth[e[i].v] = depth[x] + 1;
        }
    rangeR[x] = stamp - 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[MAXM], f[MAXM];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    par[1] = 0;
    memset(vst, 0, sizeof(vst));
    dfs(1);

    memset(f, 0, sizeof(f));
    inners = 1;
    while (inners < stamp)
        inners *= 2;
    SegmentTree odd, even;
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int tar, val;
            cin >> tar >> val;
            int lp = leaf(rangeL(tar) - 1);
            int rp = leaf(rangeR(tar) + 1);
            if (depth[tar] % 2 == 0)
            {
                even->pushDown(lp);
                even->pushDown(rp);
                even->paint(lp, rp, val);
                odd->pushDown(lp + 1);
                odd->pushDown(rp);
                odd->paint(lp + 1, rp, -val);
        }
        else
        {
            int tar;
            cin >> tar;
            int ans = a[tar - 1], eff = 1;
            while (tar)
            {
                ans = ans + f[tar] * eff;
                eff *= -1;
                tar = par[tar];
            }
            cout << ans << endl;
        }
    }
    return 0;
}

