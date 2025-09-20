#include <iostream>
#include <cmath>
using namespace  std;

int mochila(int*pesos,int valor,int n,int capa) {
    int dp[n+1][capa+1];

    for (int i=0; i<=n; i++)
        dp[i][0]=0;
    for (int i=0; i<=capa; i++)
        dp[0][i]=0;

    for (int j=1; j<=capa; j++) {
        for (int i=1; i<=n; i++) {
            if (j-pesos[i-1]>=0) {
                dp[i][j] = max(dp[i-1][j],valor[i-1]+dp[i-1][j-pesos[i-1]]);
            }else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for (int j=1; j<=capa; j++) {
        for (int i=1; i<=n; i++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int pesos[]={2,1,3,2};
    int n = sizeof(pesos)/sizeof(pesos[0]);
    int valor[]={12,10,20,15};
    int peso=5;
    cout<<"Valor maximo: "<<mochila(pesos,peso,n,peso)<<endl;
    return 0;
}