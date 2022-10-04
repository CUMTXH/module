#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 二位数点问题
// 给定点和矩形，问矩形内有多少点
// 树状数组+扫描线 
const int N = 2e5+7;

vector<int> vx;
vector<array<int,4> > event;
int n, q, m;

int c[N], ans[N];

int query(int x) {
	int s = 0;
	for(; x; x-= x&(-x)) 
		s+=c[x];
	return s;
}

void modify(int x,int s) {
	for(; x <= m ; x += x&(-x)) {
		c[x] += s;
	}
}

int main() {
	cin >> n >> q; 
	for (int i = 1 ; i <= n ; i++) {
		int x, y;
		cin >> x >> y;
		vx.push_back(x);
		event.push_back({y,0,x});
	}
	for(int i = 1 ; i <= q ; i++) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
		event.push_back({y2, 2, x2, i});
		event.push_back({y1-1,2,x1-1,i});
		event.push_back({y2,1,x1-1,i});
		event.push_back({y1-1,1,x2,i});
	}
	sort(event.begin(),event.end());
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()) ,vx.end());
	m = vx.size();
	for (auto &evt : event) {
		if (evt[1] == 0) {
			int y = lower_bound(vx.begin(),vx.end(), evt[2]) - vx.begin() +1;
			modify(y,1);
		} else {
			int y = upper_bound(vx.begin(), vx.end(), evt[2]) - vx.begin();
			int tmp = query(y);
			if(evt[1] == 1)
				ans[evt[3]] -= tmp;
			else ans[evt[3]] += tmp;
		}
	}
	for(int i = 1 ; i <= q ; i++)
		printf("%d\n",ans[i]);
}
