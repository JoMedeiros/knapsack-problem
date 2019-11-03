// A Dynamic Programming based solution for 0-1 Knapsack problem 
#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <chrono> 
#include "knapsacking.h"

using namespace std::chrono; 
using namespace std;

int main() { 
  string low_dim_files[] = { 
    "f10_l-d_kp_20_879", 
    "f2_l-d_kp_20_878 ",
    "f4_l-d_kp_4_11", "f6_l-d_kp_10_60", "f8_l-d_kp_23_10000",
    "f1_l-d_kp_10_269", "f3_l-d_kp_4_20", "f5_l-d_kp_15_375", 
    "f7_l-d_kp_7_50", "f9_l-d_kp_5_80" };
  //int low_dim_maxWs[] = { 879, 878, 11, 60, 10000, 269, 20, 375, 50, 80 };

  for (int i = 0; i < 10; ++i) {
    vector<int> val;
    //vector<int> wt = {10, 20, 30}; 
    vector<int> wt; 
    //vector<int> val = {60, 100, 120};
    //int W = 50; 
    //int W = low_dim_maxWs[i]; 

    fstream myfile("../instances_01_KP/low-dimensional/" + low_dim_files[i], ios_base::in);

    int a, b, n, W;
    myfile >> n;
    myfile >> W;
    while (myfile >> a) {
      myfile >> b;
      val.push_back(a);
      wt.push_back(b);
    }
    n = val.size(); 

    auto start = high_resolution_clock::now(); 
    cout << "Resposta para " << low_dim_files[i] << " : " << knapSack(W, wt, val, n) << "\n";
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Tempo: " << duration.count() << endl;
  }
  return 0; 
} 

