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

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;

int gcd(int a,int b){
	if (a%b==0){
		return(b);
    }else{
		return(gcd(b,a%b));
    }
};

int lcm( int m, int n ){
	if((0 == m)||(0 == n))
		return 0;
	return ((m / gcd(m, n)) * n);
};

unsigned long long comb( long n, long m ) {
    unsigned long long c = 1;
    m = ( n - m < m ? n - m : m );
    for( long ns = n - m + 1, ms = 1; ms <= m; ns ++, ms ++ ) {
        c *= ns;
        c /= ms;
    }
    return c;
};

int main(int argc, const char * argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);
}

