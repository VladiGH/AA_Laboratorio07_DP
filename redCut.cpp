#include <iostream>

using namespace std;
/*
    Se tiene una cuerda de 𝑛 pulgadas y una tabla con los precios 𝑝𝑖,𝑖=1,2,...,𝑛 según 
    la longitud. Determinar la venta máxima𝑟𝑛que se puede obtener al cortar la cuerda 
    y vender los trozos.Si el precio 𝑝𝑛es suficientemente elevado, no es necesario cortar la cuerda.
*/

//  n  es la longitud
int memoizedCutRodAux(int p[], int n, int r[]){
    int q = 0;
    if (r[n] >= 0) return r[n];
    if (n == 0) q = 0; 
    else {
        q = -1000;
        for (int i = 1; i<= n; i++){
            //cout<<"valor q: "<<q<<"\n";
            //cout<<"valor pi + MCRA "<<p[i] + memoizedCutRodAux(p, n-i, r)<<"\n";            
            q = max(q, p[i] + memoizedCutRodAux(p, n-i, r));
            
        }
    }
    r[n] = q;
    //cout<<"\n"<<"r[n]: "<<r[n]<<endl;
    return q;
}


int memoizedCutRod(int p[], int n, int r[]){
    for (int i = 0; i <= n; i++){
        r[i] = -1000;
    }
    return memoizedCutRodAux(p, n, r);
}



int main(){
    //int i[] = {1,2,3,4,5,6,7,8,9,10};       //longitud
    int pi[] = {1,5,8,9,10,17,17,20,24,30}; //precios
    int n = 4;
    int r[n];
    
    memoizedCutRod(pi, n-1, r);
    for (int j = 0; j <= n-1; j++){
        cout<<r[j]<<endl;
    }
    return 0;
}