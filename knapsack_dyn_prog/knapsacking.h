#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, vector<int> wt, vector<int> val, int n) {
  int i, w; 
  int K[n+1][W+1]; 

  // Build table K[][] in bottom up manner 
  for (i = 0; i <= n; i++) {
    for (w = 0; w <= W; w++) { 
      if (i==0 || w==0) 
        K[i][w] = 0; 
      else if (wt[i-1] <= w) 
        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
      else
        K[i][w] = K[i-1][w]; 
    } 
  } 

  return K[n][W]; 
} 

