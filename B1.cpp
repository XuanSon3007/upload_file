#include<iostream>
#include<math.h>

using namespace std;

void ColorSort(int a[],int n){
   for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            
        }
    }
   }
}

int main(){
    int n;
    cin>>n;
   bool valid=true;
   int a[n];
   cout<<"Color are decoded: 0-red, 1-white, 2-blue"<<endl;
   for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]<0 || a[i]>2){ valid=false;}
   }
    

    if(!valid){
        cout<<"false"<<endl;
        return 0;
    }

    ColorSort(a,n);

    for(int i=0;i<n;i++){
        
        if (a[i] == 0) {
            cout << "red ";
        } else if (a[i] == 1) {
            cout << "white ";
        } else if (a[i] == 2) {
            cout << "blue ";
        }
    }
    
    }
