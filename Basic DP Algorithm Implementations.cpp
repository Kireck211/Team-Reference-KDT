*********************WAYS TO COVER A DISTANCE*****************************

//To find number of ways to cover a distance in 1, 2 or 3 steps
int printCountDP(int dist)
{
    int count[dist+1];
    count[0]  = 1,  count[1] = 1,  count[2] = 2;
    for (int i=3; i<=dist; i++)
       count[i] = count[i-1] + count[i-2] + count[i-3];
    return count[dist];
}
          
*********************************FIBONACCI*********************************
int fib(int n)
{
   if (lookup[n] == NIL)
   {
      if (n <= 1)
         lookup[n] = n;
      else
         lookup[n] = fib(n-1) + fib(n-2);
   } 
   return lookup[n];
}

**************************SUBSET SUM PROBLEM*******************************
// Returns true if there is a subset of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
 
   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
 
   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) || 
                        isSubsetSum(set, n-1, sum-set[n-1]);
}

// Taken from https://github.com/Aksh77/ACM-Team-Notebook