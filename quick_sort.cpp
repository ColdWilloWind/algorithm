#include<iostream>

using namespace std;

const int  N = 1e5 + 10;

int n;
int q[N];

void quick_sort(int l, int r){
    
    if(l >= r) return ;
    
    int x = q[(l + r) >> 1 ], i = l - 1, j = r + 1;
    
    while(i < j) {
        do{
            i++;
        }while(q[i] < x);
        
        do{
            j--;
        }while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    
    quick_sort(l, j);
    quick_sort(j+1, r);
    
    
}

int main()
{
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &q[i]);
    }
    
    quick_sort(1, n);
    
    for(int i = 1; i <= n; i++){
        printf("%d ", q[i]);
    }
    
    exit(0);
}
