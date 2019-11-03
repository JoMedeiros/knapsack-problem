#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "utils.h"

/**
 * @brief Returns maximum profit we can get with capacity W 
 * @param W The maximum weight.
 * @param arr Array of itens in the knapsack.
 * @param n Size of array.
 */
int knapsack(int W, vector<Item> arr, int n) {
    sort(arr.begin(), arr.end(), cmp); 
  
    queue<Node> Q; 
    Node u, v; 
  
    u.level = -1; 
    u.profit = u.weight = 0; 
    Q.push(u); 
  
    int maxProfit = 0; 
    while (!Q.empty()) { 
        u = Q.front(); Q.pop(); 
  
        if (u.level == -1) 
            v.level = 0; 
  
        if (u.level == n-1) 
            continue; 
  
        v.level = u.level + 1; 
  
        v.weight = u.weight + arr[v.level].weight; 
        v.profit = u.profit + arr[v.level].value; 
  
        if (v.weight <= W && v.profit > maxProfit) 
            maxProfit = v.profit; 
  
        v.bound = bound(v, n, W, arr); 
  
        if (v.bound > maxProfit) 
            Q.push(v); 
  
        v.weight = u.weight; 
        v.profit = u.profit; 
        v.bound = bound(v, n, W, arr); 
        if (v.bound > maxProfit) 
            Q.push(v); 
    } 
  
    return maxProfit; 
} 
#endif // KNAPSACK_H
