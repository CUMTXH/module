#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const ll maxn = 6e6 + 7;
// 使用printf输出
// 需要当作ll输出，会越界
struct modint{
	ll x;
	modint(ll o=0){x=o;}
	modint &operator = (ll o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator ^=(ll b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
	modint &operator +=(ll o){return x=x+o>=mod?x+o-mod:x+o,*this;}
	modint &operator -=(ll o){return x=x-o<0?x-o+mod:x-o,*this;}
	modint &operator *=(ll o){return x=1ll*x*o%mod,*this;}
	modint &operator /=(ll o){return *this *= ((modint(o))^=mod-2);}
	template<class I>friend modint operator +(modint a,I b){return a+=b;}
	template<class I>friend modint operator -(modint a,I b){return a-=b;}
	template<class I>friend modint operator *(modint a,I b){return a*=b;}
	template<class I>friend modint operator /(modint a,I b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
};
modint fac[maxn+7];
void init(ll n) {
	fac[0] = 1;
    for(ll i = 1; i <= n; i ++) {
        fac[i] = fac[i - 1] * i;
    }
}
modint C(ll n, ll m) {
	return fac[n] / fac[m] / fac[n-m];
}
int main() {
    init(maxn - 1);
    ll m,n;
    while(cin>>n>>m){
    	printf("%d\n",C(n,m)); 
    }
}
