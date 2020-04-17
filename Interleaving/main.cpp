#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define ll long long
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0);
typedef unsigned long long ull;
int rng(const int before, const int after) { // Generate random base in (before, after]
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed); //remove ^ ull thing for speed
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base; //use steady_clock() for speed, for 64 bit mt19937_64 and lint
}
struct Stopwatch{
    decltype(high_resolution_clock::now()) sTime;
    decltype(high_resolution_clock::now()) eTime;
    inline void start(){
        sTime = high_resolution_clock::now();
    }
    inline void end(){
        eTime = high_resolution_clock::now();
    }
    ll report(){
        return duration_cast<microseconds>(eTime - sTime).count();
    }
    void log(string s=""){
        cout<<"Time taken "<<s<<" : "<<report()/1e6<<" seconds"<<endl;
    }
};
const int N = 100000, M = 1000, K = 1000;
Stopwatch s;
int a[N][K], b[N], p[N][K], pp[N][K];

void solve()
{
    s.start();
    for (int j = 0; j < K; ++j) {
        for (int i = 1; i < N; i++) {
            p[i][j] = p[i - 1][j] + a[b[i]][j];
        }
    }
    s.end();
    s.log();
    cout << "Done Normally" << endl;
}
void solvealt()
{
    s.start();
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < K; ++j) {
            p[i][j] = p[i - 1][j] + a[b[i]][j];
        }
    }
    s.end();
    s.log();
    cout << "Done Interleaved" << endl;
}
int main()
{
    for(int i = 1; i < N; i++)
    {
        a[i][0] = rng(-1, M-1);
        b[i] = rng(0, N-1);
        for(int j = 1; j < K; j++)
        {
            a[i][j] = a[i][0];
        }
    }
    solvealt();
    solve();
 //   solvealt();
}