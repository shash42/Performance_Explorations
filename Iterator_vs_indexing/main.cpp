#include <bits/stdc++.h>
#include <chrono>
#define ll long long
using namespace std;
using namespace std::chrono;
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0);
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
const int N = 1000000;
Stopwatch s;
int a[N][2], b[N][2], p[N][2], pp[N][2];

int main()
{
    for(int i = )
}