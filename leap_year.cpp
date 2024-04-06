#include<iostream>

using namespace std;

/*
* 对于一个日期，我们可以计算出年份的各个数位上的数字之和，也可以分别计算月和日的各位数字之和。
* 请问从1900年1月1日至9999年12月31日，总共有多少天，年份的数位数字之和等于月的数位数字之和加
* 日的数位数字之和。 例如：2022年11月31日满足2+0+2+2 = (1+1) + (1+3)
*/

bool cal(int &year, int &month, int &day) {
    int l = year / 1000 + (year / 100) % 10 + (year / 10) % 10 + year % 10;
    int r = month / 10 + month % 10 + day / 10 + day % 10;
    return l == r ? true : false;
}

bool is_leap(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return true;
    }else return false;
}

int main() 
{
    int year = 1900, month = 1, day = 1;
    
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int cnt = 0;
    
    while(true) {
        
        if(cal(year, month, day)) cnt ++;

        if(year == 9999 && month == 12 && day == 31) break;

        if(is_leap(year)) months[2] = 29;
        else months[2] = 28;

        if(day == months[month]) { // 这个月已经遍历完毕
            if(month == 12) {  // 这个年已经遍历完毕
                year ++;
                month = 1;
                day = 1;
            } else{
                month ++;
                day = 1;
            }
        }else {
            day++;
        }   
    }
    cout << cnt;
    exit(0);
}
