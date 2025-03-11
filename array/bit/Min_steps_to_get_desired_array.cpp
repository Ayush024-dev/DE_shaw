//qp link:- https://www.geeksforgeeks.org/problems/minimum-steps-to-get-desired-array5519/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
/*
Consider an array with all values zero. We can perform the following operations on the array :
  1. Incremental operations: Choose 1 element from the array and increment its value by 1.
  2. Doubling operation: Double the values of all the elements of an array.
Given an integer array arr[]. Return the least possible number of operations needed to change the original array containing only zeroes to arr[].
*/

//Aproach: 
/*

Approach
For each element in the array:
You need as many incremental operations as the number of bits set in the binary representation of the element (because each bit corresponds to an addition of a power of 2).
You need as many doubling operations as the highest power of 2 needed to reach the element (i.e., the number of bits minus one).

💡 Key Insight
The two operations correspond closely to the binary representation of the target values:

Incremental operations → Correspond to setting individual bits (1) in the binary representation.
Doubling operations → Correspond to left-shifting the binary value (which is the same as multiplying by 2).

How Binary Representation Guides Operations
Each 1 in the binary form corresponds to an increment operation because:
The bit value 1 means that the value needs to be incremented at that place.
Each left shift in binary corresponds to a doubling operation:
Doubling operation shifts bits left, increasing the value exponentially.
The number of left shifts needed to reach the most significant 1 bit gives the number of doubling operations required.
*/

//code: -
class Solution {
  public:
    // Function to count the minimum operations required
    int countMinOperations(vector<int>& arr) {
        // code here
        int totalIncrements = 0;
    int maxDoublings = 0;

    for (int num : arr) {
        int bitCount = 0;
        int doublings = 0;
        while (num > 0) {
            if (num & 1) bitCount++; 
            num >>= 1;
            doublings++;
        }
        totalIncrements += bitCount;
        maxDoublings = max(maxDoublings, doublings - 1);
    }

    return totalIncrements + maxDoublings;
    }
};

