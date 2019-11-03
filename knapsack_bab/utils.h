#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h> 
#include <vector>

using namespace std; 
  
struct Item { 
    int weight; 
    int value; 
}; 
  
/**
 * @brief Node structure to store information of decision tree 
 */
struct Node { 
    int level, //< Level of node in decision tree (or index in arr[]  
        profit, //< Profit of nodes on path from root to this node 
                //(including this node)
        bound; //< Upper bound of maximum profit in subtree of this node/ 
    float weight; 
};
  
/**
 * @brief Comparison function to sort Item according to val/weight ratio
 */
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
}
  
/** 
 * @brief Returns bound of profit in subtree rooted with u. 
 * This function mainly uses Greedy solution to find an upper bound 
 * on maximum profit. 
 */
int bound(Node u, int n, int W, vector<Item> arr) {
    if (u.weight >= W) 
        return 0; 
  
    int profit_bound = u.profit; 
  
    int j = u.level + 1; 
    int totweight = u.weight; 
  
    while ((j < n) && (totweight + arr[j].weight <= W)) { 
        totweight    += arr[j].weight; 
        profit_bound += arr[j].value; 
        j++; 
    } 
  
    if (j < n) 
        profit_bound += (W - totweight) * arr[j].value / 
                                         arr[j].weight; 
  
    return profit_bound; 
}
#endif // UTILS_H

