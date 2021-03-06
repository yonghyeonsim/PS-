//https://www.acmicpc.net/problem/2493

#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <tuple>
#include <list>
#include <set>
#include <cmath>
#include <stack>
#include <map>
//#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

#define For(i, n) for(int i = 0; i < n; i++)
#define IOS  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl  "\n";
#define IF(ny, nx, n, m) if(0 <= ny && ny < n && 0 <= nx && nx < m)
#define P pair<int, int> 
typedef  long long ll;
int dx[] = { 1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 0, 1, 0, -1, -1, -2, -2, -1, 1, 2, 2, 1 };
int hx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int hy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };


void solve() {
    IOS;
    int n;
    cin >> n;
    vector<int> a(n);

    For(i, n) cin >> a[i];

    priority_queue<P, vector<P>, greater<P>> lager;

    vector<int> ans(n, 0);

    for (int i = n - 1; i >= 0; i--) {

        while (!lager.empty()) {
            auto k = lager.top();
            if (k.first <= a[i]) {
                ans[k.second] = i + 1;
                lager.pop();
            }
            else break;
        }

        lager.push(P(a[i], i));
    }

    for (auto k : ans) cout << k << " ";
}
