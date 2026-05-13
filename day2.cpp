#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//p1: Find Majority Element by Brute Force approach O(n^2)
int majorityELement(vector<int>vec){
int count=0;
int n=vec.size();
for(int i=0;i<n;i++ ){
 for(int j=0;j<n;j++){
    if(vec[i]==vec[j]){
        count++;
    }
 }
 if(count>n/2){
    return vec[i];
 }
}
}
//p2: Find Majority Element by sorting O(nlogn)
int majorELement(vector<int> vec){
int count=1,n=vec.size(),ans=vec[0];
 sort(vec.begin(),vec.end()); // O(logn)
 for(int i=1;i<n;i++){  /// O(n)
    if(vec[i]==vec[i-1]){
        count++;
    }
    else{
        count=1;
        ans=vec[i];
    }
    if(count>n/2){
        return ans;
    }
 }
}
//p3: Find Majority Element by Moores's Algorithm O(n)
int majorityELementAlgo(vector<int> vec){
int count=0,n=vec.size(),ans=0;
 
 for(int i=1;i<n;i++){  /// O(n)
    if(count==0){
        ans=vec[i];
    }
    ans==vec[i]?count++:count--;
 }
 return ans;
}


int main(){
    //p1:
 vector<int> vec1={1,2,2,1,1};
 cout<<"Majority Element: "<<majorityELement<<endl;
  //p2:
 vector<int> vec1={1,2,2,1,1};
 cout<<"Majority Element: "<<majorELement<<endl;
 //p3:
 vector<int> vec1={1,2,2,1,1};
 cout<<"Majority Element: "<<majorityELementAlgo<<endl;

    return 0;
}