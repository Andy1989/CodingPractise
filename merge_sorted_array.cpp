/* Merge Sorted Array
 * Given two sorted integer arrays A and B, merge B into A as one 
 * sorted array.
 *
 * Note:
 * You may assume that A has enough space to hold additional elements 
 * from B. The number of elements initialized in A and B are m and n
 * respectively.
 */
 
#include<iostream>
#include<stdlib.h>
#include<new>
#include<vector>
using namespace std;

/*
 * Space complexity O(n), time complexity O(n)
 */
void merge3(int A[], int m, int B[], int n) {
	vector<int> temp;
	int i = 0, j = 0;
	while(i < m && j < n) {
		if(A[i] <= B[j]) {
			temp.push_back(A[i++]);
		} else {
			temp.push_back(B[j++]);
		}
	}
	while(i < m) {
		temp.push_back(A[i++]);
	}
	while(j < n) {
		temp.push_back(B[j++]);
	}
	for(vector<int>::size_type it = 0, i = 0; it < temp.size(); it++) {
		A[i++] = temp.at(it);
	}
}

int main() {
	int A[] = {-1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0};
	int B[] = {-1, -1, 0, 0, 1, 2};
	merge3(A, 5, B, 6);
	for(int i = 0; i < 11; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
