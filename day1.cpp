#include <iostream>
using namespace std;
//p5: BruteForce approach O(n^3) to get maxsum of sub array
void bruteforce(int arr[])
{
    int n = 5;
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
                sum += arr[k];
            }
            cout << " , ";
            maxSum = max(maxSum, sum);
        }
        cout << endl;
    }
    cout << "Sum= " << maxSum << endl;
}
//p6: BruteForce approach O(n^2)
int bBruteforce(int arr[])
{
    int n = 5, maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}
//p1: Standard Kadane's Algorithm
int kadane(int arr[])
{
    int n = 3;
    int currSum = 0, maxSum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
//p2:
struct Sum
{
    int maxSum, minSum, totalSum, currMax;
};
//  Maximum Sum Circular Subarray
Sum kadaneCircular(int arr[])
{
    int n = 3, totalSum = 0, circularMax;
    // For MAXIMUM subarray sum
    int currMax = 0, maxSum = INT16_MIN;
    // For MINIMUM subarray sum
    int currMin = 0, minSum = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i]; // for total sum
                            // Maximum subarray (standard Kadane)
        currMax += arr[i];
        maxSum = max(currMax, maxSum);
        if (currMax < 0)
        {
            currMax = 0;
        }
        // Minimum subarray (inverted logic)
        currMin += arr[i];
        minSum = min(currMin, minSum);

        if (currMin > 0)
        {
            currMin = 0;
        }
    }
    // For circular case
    if (maxSum < 0)
    {
        // All numbers are negative
        return {maxSum, minSum, totalSum};
    }
  
    return {circularMax, minSum, totalSum, currMax};
}

//p3: Simpler version without reset logic
int findMinSubArray(int arr[])
{
    int n = 3;
    int currMin = arr[0];
    int minSum = arr[0];
    for (int i = 1; i < n; i++)
    {
        currMin = min(arr[i], arr[i] + currMin);
        minSum = min(minSum, currMin);
    }
    return minSum;
}
//p4: Kadane-style for product
int maxProduct(vector<int> &nums)
{
    int currMax = nums[0], maxPro = nums[0], n = nums.size();
    int currMin = nums[0]; // Need min because negative × negative = positive
    for (int i = 1; i < n; i++)
    {
        // Store previous values before overwriting
        int tempMax = currMax;
        // Current max could be:
        // 1. Start fresh with nums[i]
        // 2. Extend previous max (positive × positive)
        // 3. Extend previous min (negative × negative = positive)
        currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
        currMin = min({nums[i], tempMax * nums[i], currMin * nums[i]}); // help tracking negative and do (negative × negative = positive)
        maxPro = max(maxPro, currMax);
    }
    return maxPro;
}

int main(){
  //p1:
int arr1={1,2,3,4};
  cout<<kadane(arr1)<<endl
    //p2:
 int arr2={5, -3, 5};
  Sum result = kadaneCircular(arr2)<<endl;
    cout << "maxsum= " << result.maxSum << endl;
    cout << "minsum= " << result.minSum << endl;
    cout << "currMax= " << result.currMax << endl;
    cout << "totalsum= " << result.totalSum << endl;
  // p3:
  int arr3={-2,-3,-1};
  cout<<findMinSubArray(arr3);
  //p4:
    vector<int> vec = {-3, -1, -1};
    cout << maxProduct(vec) << endl;
     //p5:
    bruteforce(arr1);
    //p6:
    cout<<bBruteforce(arr1);
  return 0;
}
