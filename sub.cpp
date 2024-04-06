#include<iostream>
#include<vector>

using namespace std;

bool compare(string &a, string &b){
    if(a.size() == b.size()) {
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) return a[i] > b[i];
        }
        return true;
    } else return a.size() > b.size();
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    int t = 0;
    vector<int> C;
    for(int i = 0; i < A.size(); i++) {
        if(i < B.size()) t += A[i] - B[i] + 10;
        else t += A[i] + 10;
        C.push_back(t % 10);
        t = t > 9 ? 0 : -1;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    vector<int> A, B, C;
    string a, b;
    cin >> a >> b;
    
    for(int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for(int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }
    
    if(compare(a, b)) {
        C = sub(A, B);
    }else {
        printf("%c", '-');
        C = sub(B, A);
    }
    
    
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    
    exit(0);
}
