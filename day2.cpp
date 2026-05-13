#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//p1: Find Majority Element by Brute Force approach O(n^2) LeetCode problem no 169
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
//p3: Find Majority Element by Moores's Algorithm O(n) LeetCode problem no 169
int majorityELementAlgo(vector<int> vec){
int count=0,n=vec.size(),ans=0;
 
 for(int i=0;i<n;i++){  /// O(n)
    if(count==0){
        ans=vec[i];
    }
    ans==vec[i]?count++:count--;
 }
 return ans;
}

//p4: Compute Power LeetCode Problem no 50 
double computePower(double x, int n)
{
    double ans = 1;
    long binform = n;
    if (n == 0)
        return 1.0;
    if (x == 0)
        return 0.0;
    if (x == 1)
        return 1.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;
    if (binform < 0)
    {
        x = 1 / x;
        binform = -binform;
    }
    while (binform > 0)
    {
        if (binform % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binform /= 2;
    }
    return ans;
}
//p5: Buy aand sell stock problem LeetCode Problem no 121
int buyAndSell(vector<int> vec)
{
    int maxPro = 0, bestBuy = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > bestBuy)
        {
            maxPro = max(maxPro, vec[i] - bestBuy);
        }
        bestBuy = min(bestBuy, vec[i]);
    }
    return maxPro;
}
// p6: Unlimited Transactions
//Problem: You may complete as many transactions as you like (buy one, sell one, then buy again, etc.). However, you must sell before buying again. Find the maximum profit.

int unlimitedTransactions(vector<int> vec)
{
    int maxPro = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > vec[i-1])
        {
            maxPro+= vec[i]-vec[i-1];
        }
        
    }
    return maxPro;
}

//p7: Max Water Container Brute force approach O(n^2) LeetCode Problem no 11
int maxWater(vector<int> vec)
{
    int n = vec.size();
    int l, w, maxWater = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            w = j - i;
            l = min(vec[i], vec[j]);
            maxWater = max(maxWater, l * w);
        }
    }
    return maxWater;
}
//p8: Max Water Container Optimal approach O(n) LeetCode Problem no 11
int maxWaterCon(vector<int> vec)
{
    int st = 0, end = vec.size() - 1;
    int maxWater = 0;
    while (st < end)
    {
        int w = end - st;
        int l = min(vec[st], vec[end]);
        maxWater = max(maxWater, l * w);
        vec[st] < vec[end] ? st++ : end--;
    }
    return maxWater;
}


int main(){
    //p1: Brute Force approach
 vector<int> vec1={1,2,2,1,1};
 cout<<"Majority Element: "<<majorityELement(vec1)<<endl;

  //p2: by sorting
 cout<<"Majority Element: "<<majorELement(vec1)<<endl;

 //p3: by Moores's Algorithm
 
 cout<<"Majority Element: "<<majorityELementAlgo(vec1)<<endl;

 //p4: Compute Power 
  double a;
    int b;
    cout << "Enter a number: " << endl;
    cin >> a;
    cout << "Enter power that you want: " << endl;
    cin >> b;
    double result = computePower(a, b);
    cout << "Power of " << a << " ^ " << b << " is " << result << endl;

    //p5: Buy aand sell stock problem
  vector<int> vec2 = {7, 1, 5, 3, 6, 4};
    cout << "vec2: " << buyAndSell(vec2) << endl;

    // p6: Unlimited Transactions
    vector<int> vec3 = {3, 6, -4, 3, 2, 7};
    vector<int> vec4 = {1, 2, 3, 0, 2};
    cout << "vec3: " << unlimitedTransactions(vec3) << endl;
    cout << "vec4: " << unlimitedTransactions(vec4) << endl;

//p7: Max Water Container Brute force approach O(n^2) 
vector<int> vec6 = {1, 8, 6, 2, 5, 4};
    cout << "MaxWater Stored: " << maxWater(vec6) << endl;
//p8: Max Water Container Optimal approach O(n) 
    cout << "MaxWater Stored: " << maxWaterCon(vec6) << endl;

    return 0;
}