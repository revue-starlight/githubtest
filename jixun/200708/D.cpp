#include <bits/stdc++.h>
using namespace std;
int a[1000],n;
vector <int> vec;
int find_mex(){
    bool bo[1001];
    memset(bo,0,sizeof(bo));
    int mex;
    for (int i=0;i<n;i++) {bo[a[i]]=1;}
    for (int i=0;i<=n;i++) {if (!bo[i]) {mex=i; break;}}
    return mex;
}

void fill(int x){
    for (int i=0;i<n;i++){
        if (a[i]==x) {a[i]=find_mex(); vec.push_back(i);}
    }
}

bool check(){
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]) return false;
    }
    return true;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=0;i<n;i++) cin>>a[i];
        vec.clear();
        int tmp=0;
       while (1){
           if (check()) break;
           int mex=find_mex();
           if (mex==n){
                int i;
                for (i=0;i<n;i++) 
                    if (a[i]!=i){
                        a[i]=mex; vec.push_back(i); break;}     
            } 
           else
           {
               a[mex]=mex; vec.push_back(mex);
           }
       }
        int len=vec.size();
        cout<<len<<endl;
        for (int i=0;i<len;i++) cout<<vec[i]+1<<" ";
        cout<<endl;
    }
}