// A recursive solution for subset sum problem
#include <stdio.h>
 
// Returns true if there is a subset of set[] with sun equal to given sum
int isSubsetSum(int set[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     return 1;
   if (n == 0 && sum != 0)
     return 0;
 
   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
 
   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) || 
                        isSubsetSum(set, n-1, sum-set[n-1]);
}
 
// Driver program to test above function
int main()
{
  //int set[] = {3, 34, 4, 12, 5, 2};
  int set[] = {5,1,6,8,4};
  int sum = -7;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == 1)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
