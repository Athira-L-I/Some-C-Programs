#include <bits/stdc++.h>

using namespace std;

int maximizeProfit(vector <int> a, vector <int> b, int m, int k) {
    // Complete this function
    vector <int> arr; int j=0, n=a.size();
    for(int i=0; i<n; i++)
    {
        arr.push_back(m*b[i]*a[i]);
    }
    arr.push_back(m*k);
    for(int i=0; i<=n; i++)
        if(j<arr[i]) j=arr[i];
    return j;
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(n);
    for(int b_i = 0; b_i < n; b_i++){
       cin >> b[b_i];
    }
    int result = maximizeProfit(a, b, m, k);
    cout << result << endl;
    return 0;
}
