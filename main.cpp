#include <iostream>
using namespace  std;

int coinrow(int *monedas,int n) {
    int F[n+1];
    F[0]=0;
    F[1]=monedas[0];
    for (int i=2;i<n+1;i++) {
        int max=F[i-1];
        int aux=monedas[i]+F[i-2];
        if (aux>max) {
            max=aux;
        }
        F[i]=max;
    }
    return F[n];
}
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    int monedas[]{5,1,2,10,6,2};
    int n = sizeof(monedas)/sizeof(monedas[0]);
    cout<<"Valor maximo: "<<coinrow(monedas,n)<<endl;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}