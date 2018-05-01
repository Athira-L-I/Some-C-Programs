#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

int maxDifference(int startVal, int endVal) {
    // Complete this function
    int i,j;
    for(i=startVal;i<=endVal; i++)
        if(isPrime(i)) break;
    for(j=endVal;j>=startVal; j--)
        if(isPrime(j)) break;
    if((i>endVal)&&(j<startVal))
        return 0;
    return j-i;
    
}

int main() {
    int q, temp;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int startVal;
        int endVal;
        cin >> startVal >> endVal;
        if(startVal>endVal)
        {
            temp=startVal; startVal=endVal; endVal=temp;
        }
        int result = maxDifference(startVal, endVal);
        cout << result << endl;
    }
    return 0;
}
