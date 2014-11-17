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


int n, m, s, d, a[100000], b[100000], c[100000];

// 信号待ちの結果を返す
ull traffic(int place, ll time){
    if(time <= c[place]){
        return c[place];
    }else{
        ll _time = time - c[place];
        _time = _time % (a[place] + b[place]);
        if(_time < a[place]){
            // 信号待ちがなかったとき
            return time;
        }else{
            // 信号待ちしたとき
            return time - _time + a[place] + b[place];
        }
    }
    return 0;
};


int main(int argc, const char * argv[]){
    cin >> n >> m >> s >> d;
    s--; d--;
    FOR(i, n) cin >> a[i] >> b[i] >> c[i];
    
    
    vector<edge> g[100000];
    FOR(i, m){
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        edge e1; e1.to = y; e1.cost = t;
        g[x].push_back(e1);
        edge e2; e2.to = x; e2.cost = t;
        g[y].push_back(e2);
    }
    
    ll time[100000]; // ついた瞬間
    ll dist[100000]; // 信号待ちも含めた時間
    FOR(i, n){
        dist[i] = -1;
        time[i] = -1;
    }
    
    // ダイクストラ法で探していく
    dist[s] = traffic(s, 0);
    time[s] = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL> > q;
    q.push(PLL(dist[s], s));
    while (!q.empty()) {
        PLL p = q.top(); q.pop();
        ll i = p.second; // iは基点
        
        // iから行ける信号について調べる
        for(int k = 0; k < g[i].size(); k++){
            edge e = g[i][k];
            // 早くついた場合は信号待ちを考える
            if(time[e.to] > dist[i] + e.cost || time[e.to] == -1){
                time[e.to] = dist[i] + e.cost;
                // 信号待ちを考えても早い場合は更新する
                if(dist[e.to] > traffic(e.to, time[e.to]) || dist[e.to] == -1){
                    dist[e.to] = traffic(e.to, time[e.to]);
                    q.push(PLL(dist[e.to], e.to));
                }
            }
            
        }
    }
    cout << time[d] << endl;

}