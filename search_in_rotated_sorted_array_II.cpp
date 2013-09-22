/* Search in Rotated Sorted Array II
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return true, otherwise return false.
 *
 * Duplicages are allowed. Would this affect the run-time complexity? How and why?
 *
 * Algorithm:
 * 1. Find the pivot index.
 * 2. Run binary search twice.
 */
#include<iostream>
using namespace std;

int binarySearch(int A[], int begin, int end, int target) {
	if(begin <= end) {
		if(A[(begin + end) / 2] < target) {
			return binarySearch(A, (begin + end) / 2 + 1, end, target);
		} else if(A[(begin + end) / 2] > target) {
			return binarySearch(A, begin, (begin + end) / 2 - 1, target);
		} else {
			return (begin + end) / 2;
		}
	}
	return -1;
}

int findPivot(int A[], int begin, int end) {
	if(begin <= end) {
		if(A[(begin + end) / 2] > A[begin] || (begin + end) / 2 == begin) {
			if(A[(begin + end) / 2] > A[(begin + end) / 2 + 1]) {
				return (begin + end) / 2;
			} else {
				return findPivot(A, (begin + end) / 2 + 1, end);
			}
		} else if(A[(begin + end) / 2] < A[begin]) {
			return findPivot(A, begin, (begin + end) / 2 - 1);
		} else {
			if(A[(begin + end) / 2] < A[end]) {
				return -1;
			} else if(A[(begin + end) / 2] > A[end]) {
				if(A[(begin + end) / 2] > A[(begin + end) / 2 + 1]) {
					return (begin + end) / 2;
				} else
					return findPivot(A, (begin + end) / 2 + 1, end);
			} else {
				if(A[(begin + end) / 2] > A[(begin + end) / 2 + 1]) {
					return (begin + end) / 2;
				}
				int rv1 = findPivot(A, begin, (begin + end) / 2 - 1);
				int rv2 = findPivot(A, (begin + end) / 2 + 1, end);
				return (rv1 >= rv2 ? rv1 : rv2);
			}
		}
	}
	return -1;
}

bool search(int A[], int n, int target) {
	if(n == 0) {
		return -1;
	}
	int index = 0;
	int pivot;
	if(A[0] < A[n - 1]) {
		index = binarySearch(A, 0, n - 1, target);
	} else {
		pivot = findPivot(A, 0, n - 1);
		if(pivot == -1) {
			if(A[0] == A[n - 1] && A[0] == target) {
				index = 0;
			} else {
				index = binarySearch(A, 0, n - 1, target);
			}
		} else {
			index = binarySearch(A, 0, pivot, target);
			if(index == -1) {
				index = binarySearch(A, pivot + 1, n - 1, target);
			}
		}
	}
	return (index >= 0);
}

int main() {
	int A[] = {2,2,2,0,0,1};
	//{2,2,2,0,2,2}; 0
	//{1, 1, 3, 1}; 3
	//{1, 3, 1, 1, 1}; 3
	//{1, 1, 1, 1, 1, 1, 1, 1};
	//{3, 1}, 0;
	//{4, 5, 6, 7, 0, 1, 2};
	cout << search(A, 6, 0);
	return 0;
}
