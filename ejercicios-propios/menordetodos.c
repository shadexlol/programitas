#include <stdio.h>

float aproximacion (float x, float v[], int n);

int main (){

float v[4]={3.1,2,5,6.4};
float x;
int a;

x = 3.6;

a = 4;

printf("%f",aproximacion(x,v,a));


return 0;

}

float aproximacion(float x, float v[], int n){
    
    int i,menortotal,less,less2;
    
        for  (i=0;i<n-1;i++){
        
            less = v[i]-x;
            less= abs(less);
            
            less2 = v[i+1]-x;
            less2 = abs (less2);
            
            if (less<less2){
                menortotal=v[i];
                }
            if else (less2<less){
                menortotal=v[i+1];
                }
            }
            
    return menortotal;
    
}
            
