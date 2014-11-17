#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long>PLL;
typedef queue<int> QI;
typedef priority_queue<int> maxpq;
typedef priority_queue<int, vector<int>, greater<int> > minpq;

struct edge{int to, cost;};

void begin(){cin.tie(0); ios::sync_with_stdio(false);};
int gcd(int a, int b){if(a%b==0){return(b);}else{return(gcd(b,a%b));}};
int lcm(int m, int n){if((0 == m)||(0 == n)){return 0;} return ((m / gcd(m, n)) * n);};
unsigned long long comb(long n, long m){unsigned long long c = 1; m = (n - m < m ? n - m : m);
    for(long ns = n - m + 1, ms = 1; ms <= m; ns ++, ms ++){c *= ns; c /= ms;} return c;};

void warshallFloyd(int d[100][100], int n){
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(d[i][k] != -1 && d[k][j] != -1){
                    if(d[i][j] == -1){
                        d[i][j] = d[i][k] + d[k][j];
                    }else{
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
};


// d:隣接行列  n:グラフのサイズ  s:始点  dist:始点からの距離が入る配列
void dijkstra(int d[1000][1000], int n, int s, int dist[1000]){
    FOR(i, n) dist[i] = -1;
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push(PII(0, s));
    while (!q.empty()) {
        PII p = q.top(); q.pop();
        int i = p.second;
        if(dist[i] < p.first) continue;
        for(int j = 0; j < n; j++){
            if(d[i][j] == -1) continue;
            if(dist[j] == -1){
                dist[j] = dist[i] + d[i][j];
                q.push(PII(dist[j], j));
            }else if(dist[j] > dist[i] + d[i][j]){
                dist[j] = dist[i] + d[i][j];
                q.push(PII(dist[j], j));
            }
        }
    }
};


// 信号待ちの結果を返す
int main(int argc, const char * argv[]){
    begin();
}