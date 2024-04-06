#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int n, q, k;

int findleft(int l, int r) {
    
    if(l >= r) return l;
    
    int mid = (l + r) >> 1;
    
    if(a[mid] >= k) r = mid;
    else l = mid + 1;
    
    return findleft(l, r);
}

int findright(int l, int r) {
    
    if(l >= r) return l;
    
    int mid = (l + r + 1) >> 1;
    
    if(a[mid] > k) r = mid - 1;
    else l = mid ;
    
    return findright(l, r);
}


int main()
{
    int l, r;
    
    scanf("%d%d", &n, &q);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    while(q--) {
        
        scanf("%d", &k);
        
        l = findleft(1, n);
        r = findright(1, n);
        
        if(a[l] == k) {
            printf("%d %d\n", l - 1, r - 1);
        }else puts("-1 -1");
    }
    
    exit(0);
}
