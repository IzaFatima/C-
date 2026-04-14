#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// p1: LinearSearch using Array...............Time_Complexity: O(n)
int linearSEarch(int arr[], int size, int tar)
{
    for (int i = 0; i < size; i++)
    {
        if (tar == arr[i])
        {
            return i;
        }
    }
    return -1;
}
// p2: Reverse array using two pointer approach..............Time_Complexity: O(n)
void reverseArray(int arr[], int size)
{
    int st = 0;
    int end = size - 1;
    while (st < end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

//Find Single Value(Unique) Using Nested Loop
int uniqueValue(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
        if (count == 0)
        {
            return (i, arr[i]);
        }
    }
    return -1;
}
//Find Single Value(Unique) Using Bitwise XOR operator
int SingleNumber(vector<int> &vec)
{

    int ans = 0;
    for (int val : vec)
    {
        ans = ans ^ val;
    }
    return ans;
}

int main()
{
  vector<int> vec1 = {1, 2, 3, 2, 3, 4, 4};
    vector<int> vec2 = {4, 1, 2, 1, 2};
    cout << uniqueValue(vec1) << endl;
    cout << SingleNumber(vec2) << endl;

    
    // p1:
    int arr[] = {4, 2, 7, 8, 1, 2};
    int size = 6;
    reverseArray(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    // p2:
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    int size = 7;
    int target = 4;
    cout << linearSEarch(arr, size, target);

    // Find Largest Number
    int smallest = INT16_MAX;
    int largest = INT16_MIN;
    int marks[6] = {5, 15, 22, 1, -15, 24};
    int size = 6;
    for (int i = 0; i < size; i++)
    {
        // if (marks[i] > largest)
        // {
        //     largest = marks[i];
        // }
        largest = max(largest, marks[i]);
    }
    cout << "Largest: " << largest << endl;

    // Find Smallest Number
    for (int i = 0; i < size; i++)
    {
        // if (marks[i] < smallest)
        // {
        //     smallest = marks[i];
        // }
        smallest = min(smallest, marks[i]);
    }
    cout << "Smallest: " << smallest << endl;

    // For input:
    for (int i = 0; i < size; i++)
    {
        cin >> marks[i];
    }

    // For output
    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << " ";
    }

    // convert string into HEX_Decimal number
    string hexSTR = "2F"; // 2*16^1 + 15*16^0 ---> 47
    int result;
    stringstream ss;
    ss << hex << hexSTR;
    ss >> result;
    cout << result << endl;

    // pointers
    int num = 3;
    int *ptr = &num;
    cout << "&num: " << &num << endl;
    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    // Add 1 to pointer
    cout << "ptr+1: " << ptr + 1 << endl;
    // Addresses
    int arr[3] = {1, 2, 3};
    cout << sizeof(int) << endl;
    cout << "&arr[0]= " << &arr[0] << endl;
    cout << "&arr[1]= " << &arr[1] << endl;
    cout << "&arr[2]= " << &arr[2] << endl;
    return 0;
}
