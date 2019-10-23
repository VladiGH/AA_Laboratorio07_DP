#include <iostream>
using namespace std;

int cutRod(int pi[], int n, int r[]) {   
    
    for (int i = 1; i <= n; i++){
        int q = -1;
        for(int j = 0; j < i; j++){
            q = max(q, pi[j] + r[i-j-1]); 
        }
        r[i] = q;   
    }
    return r[n]; 
} 

int main() 
{     
    int pi[] = {1,5,8,9,10,17,17,20}; //precios 
	int n = 4;
    int r[n+1];
    r[0] = 0;
    //r[1] = 1;
    for (int i = 1; i <= n; i++){
            r[i] = -1;
    }
	cout<<"Max: "<< cutRod(pi, n, r)<<endl; 
    for (int i = 0; i <= n; i++){
        cout<<r[i]<<endl;
    }
    
	return 0; 
} 
