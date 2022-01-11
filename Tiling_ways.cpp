#include<bits/stdc++.h>
using namespace std;
int tilingway(int n){

    if(n==0 || n==1 )
    {
        return n;
    }
  // Tile board is of 2*n and tile is of Demonsion 2*1;
    return tilingway(n-1)+tilingway(n-2);


}
int main(){
    int n;
    cin>>n;
    cout<<tilingway(n)<<endl;

    return 0;


}