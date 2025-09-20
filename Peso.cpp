#include <iostream>
using namespace std;

int subconjunto(int *paq,int n,int peso) {
    int dp[n+1][peso+1];
    for (int i=0;i<=n;i++) {
        dp[i][0]=1;
    }

    for (int j=1;j<=peso;j++)
        dp[0][j]=0;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=peso;j++) {
            dp[i][j]=dp[i-1][j];
            if (j-paq[i-1]>=0 and dp[1][j]==0)
                dp[i][j]=dp[i-1][j-paq[i-1]];
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=peso;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][peso];
}


int main() {
    int paq[]={2,3,6};
    int n=sizeof(paq)/sizeof(paq[0]);
    cout<<subconjunto(paq,n,10);

    return 0;
}