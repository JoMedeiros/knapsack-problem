// A Dynamic Programming based solution for 0-1 Knapsack problem 
#include <stdio.h> 
#include <iostream>
#include <fstream>      // std::fstream
#include <algorithm>
#include <string>
#include <chrono> 
#include "knapsack.h"

using namespace std::chrono;
using namespace std;

int main() { 
  string low_dim_files[] = { 
    "f10_l-d_kp_20_879", 
    "f2_l-d_kp_20_878 ",
    "f4_l-d_kp_4_11", "f6_l-d_kp_10_60", "f8_l-d_kp_23_10000",
    "f1_l-d_kp_10_269", "f3_l-d_kp_4_20", "f5_l-d_kp_15_375", 
    "f7_l-d_kp_7_50", "f9_l-d_kp_5_80" };

  string large_scale_files[] = {
    "knapPI_1_100_1000_1", "knapPI_2_100_1000_1", "knapPI_3_100_1000_1",
    "knapPI_1_200_1000_1", "knapPI_2_200_1000_1", "knapPI_3_200_1000_1",
    "knapPI_1_500_1000_1", "knapPI_2_500_1000_1", "knapPI_3_500_1000_1"};
    //"knapPI_1_1000_1000_1", "knapPI_2_1000_1000_1", "knapPI_3_1000_1000_1",
    //"knapPI_1_2000_1000_1", "knapPI_2_2000_1000_1", "knapPI_3_2000_1000_1",
    //"knapPI_1_10000_1000_1", "knapPI_2_10000_1000_1", "knapPI_3_10000_1000_1",
    //"knapPI_1_5000_1000_1", "knapPI_2_5000_1000_1", "knapPI_3_5000_1000_1"};

  cout << "low-dimension\nArquivo, Items, Limite, Resposta, Tempo (microsegundos)\n";
  for (int i = 0; i < 10; ++i) {
    vector<Item> arr;

    fstream myfile("../instances_01_KP/low-dimensional/" + low_dim_files[i], ios_base::in);

    int a, b, n, W;
    myfile >> n;
    myfile >> W;
    while (myfile >> a) {
      myfile >> b;
      arr.push_back({b, a});
    }
    n = arr.size();

    auto start = high_resolution_clock::now(); 
    cout << low_dim_files[i] << " , " << n << " , " << W << " , " << knapsack(W, arr, n);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << " , " << duration.count() << endl;

  }
  cout << "large-scale\nArquivo, Items, Limite, Resposta, Tempo (microsegundos)\n";
  for (int i = 0; i < 9; ++i) {
    vector<Item> arr;

    fstream myfile("../instances_01_KP/large_scale/" + large_scale_files[i], ios_base::in);

    int a, b, n, W;
    myfile >> n;
    myfile >> W;
    while (myfile >> a) {
      myfile >> b;
      arr.push_back({b, a});
    }
    n = arr.size();

    auto start = high_resolution_clock::now(); 
    cout << low_dim_files[i] << " , " << n << " , " << W << " , " << knapsack(W, arr, n);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << " , " << duration.count() << endl;

  }
  return 0; 
} 
