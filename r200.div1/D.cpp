#include <iostream>
#include <deque>

using namespace std;

const int MAXN = 500100;
int size[MAXN] = {0}, depth[MAXN];
int father[MAXN], heavy[MAXN], tot[MAXN] = {0}, ord[MAXN], up[MAXN], h_ptr[MAXN];
deque< pair<int, int> > h_info[MAXN];

int v[MAXN] = {0}, m_cnt = 1;
struct edge
{
    int next, tar;
} e[MAXN * 2];
inline void add_edge(int x, int y)
{
    e[m_cnt].next = v[x];
    e[m_cnt].tar = y;
    v[x] = m_cnt;
}

int n;

int visit[MAXN] = {0};
void make_tree(int x)
{
    visit[x] = 1;
    heavy[x] = 0;
    if (x == 1)
        depth[x] = 0;
    size[x] = 1;
    for (int i = v[x]; i != 0; i = e[i].next)
    {
        int y = e[i].tar;
        if (!visit[y])
        {
            depth[y] = depth[x] + 1;
            father[y] = x;
            make_tree(y);
            size[x] += size[y];
        }
        if (heavy[x] == 0)
            heavy[x] = y;
        else
            if (size[y] > size[heavy[x]])
                heavy[x] = y;
    }
}

int vec_cnt = 0;
int make_new_vec()
{
    vec_cnt++;
    h[vec_cnt].clear();
    return vec_cnt;
}

void heavy_up(int x)
{
    if (x == 1 || heavy[father[x]] != x)
    {
        ord[x] = 0;
        up[x] = x;
        h_ptr[x] = make_new_vec();
        return;
    }
    heavy_up(father[x]);
    ord[x] = ord[father[x]] + 1;
    up[x] = up[father[x]];
    h_ptr[x] = h_ptr[father[x]];
}

int main()
{
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    make_tree(1);
    for (int i = 1; i <= n; i++)
        if (size[i] == 1) // leaf
        {
            heavy_up(i);
        }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        
