#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], tmp[N];

void merge_sort(int l, int r) {
    
    if(l >= r) return ;
    
    int mid = l + r >> 1;
    
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    
    for(int i = l; i <= r; i++) {
        tmp[i] = q[i];
    }
    
    int i, j, k;
    
    for(i = l, j = mid+1, k = l; i <= mid && j <= r; k++) {
        if(tmp[i] <= tmp[j])
            q[k] = tmp[i++];
        else q[k] = tmp[j++];
    }
    
    while(i <= mid) q[k++] = tmp[i++];
    while(j <= r) q[k++] = tmp[j++];
}



int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
    }
    
    merge_sort(1, n);
    
    for(int i = 1; i <= n; i++) {
        printf("%d ", q[i]);
    }

    exit(0);
}
