#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums{1, 3, 4, 2, 2};
    // nums lemgth is n + 1 = 5 so n = 4

    while (nums[0] != nums[nums[0]])

        // for index 0 : while( 1 != nums[1] )
        // swap( nums[0] which value is 1 and nums[nums[0]] position`s value )
        // Basically we are placing the integers in there respective index position menas integer '1' will be at index No 1 , integer '2' will be at index No 2 and So on.....
        // all the intergers will be in the range of n & here n = 4 so integers will be 1,2,3,4
        // here " while( 1 != nums[1] ) " <- this condition is true swap the value....

        while (nums[0] != nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }

    cout << "Duplicate : " << nums[0];

    return 0;
}