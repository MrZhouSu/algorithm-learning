#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

struct point
{
    int x, y, z;
};

int l, r, c;

point a, b;

const int N = 110;

queue<point> q;

char g[N][N][N];

int d[N][N][N];

int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs()
{
    memset(d, -1, sizeof d);

    q.push({a.x, a.y, a.z});

    d[a.z][a.x][a.y] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int x = t.x;
        int y = t.y;
        int z = t.z;

        for (int i = 0; i < 6; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int zz = z + dz[i];

            if (xx < r && xx >= 0 && yy < c && yy >= 0 && zz < l && zz >= 0 && d[zz][xx][yy] == -1 && g[zz][xx][yy] != '#')
            {
                d[zz][xx][yy] = d[z][x][y] + 1;
                q.push({xx, yy, zz});
            }
        }
    }
    return d[b.z][b.x][b.y];
}

int main(void)
{
    while (~scanf("%d%d%d", &l, &r, &c) && l + r + c)
    {
        // getchar();

        // for(int i=0;i<l;i++)
        // {
        //     for(int j=0;j<r;j++)
        //     {
        //         fgets(g[i][j],N,stdin);
        //     }
        //     getchar();
        // }
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> g[i][j][k];
                    if (g[i][j][k] == 'S')
                        a = {j, k, i};
                    if (g[i][j][k] == 'E')
                        b = {j, k, i};
                }
            }
        }

        // for(int i=0;i<l;i++)
        // {
        //     for(int j=0;j<r;j++)
        //     {
        //         for(int k=0;k<c;k++)
        //         {
        //             cout<<g[i][j][k];
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        int t = bfs();

        if (t == -1)
            cout << "Trapped!" << endl;
        else
            printf("Escaped in %d minute(s).\n", t);
    }

    return 0;
}
