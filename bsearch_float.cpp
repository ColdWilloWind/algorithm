#include<iostream>

using namespace std;

int main()
{
    
    double n;
    
    scanf("%lf", &n);
    
    double l = -100.0, r = 100.0;
    /*
     * 题目要求保留6位小数就1e-8，如果保留4位就1e-6
     */    
    while(r - l > 1e-8) {
        
        double mid = (l + r) / 2;
        if(mid * mid * mid > n) r = mid;
        else l = mid;
    }
    
    printf("%.6lf", l);
    
    exit(0);
}
