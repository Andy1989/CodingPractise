/* Search in Rotated Sorted Array 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 *You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 *You may assume no duplicate exists in the array.
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
	if(A[(begin + end) / 2] >= A[begin]) {
		if(A[(begin + end) / 2] > A[(begin + end) / 2 + 1]) {
			return (begin + end) / 2;
		} else {
			return findPivot(A, (begin + end) / 2 + 1, end);
		}
	} else {
		return findPivot(A, begin, (begin + end) / 2 - 1);
	}

}

int search(int A[], int n, int target) {
	if(n == 0) {
		return -1;
	}
	int index = 0;
	int pivot;
	if(A[0] < A[n - 1]) { // unrotated
		index = binarySearch(A, 0, n -1, target);
	} else if(A[0] == A[n - 1]) { // n = 1, only one element in the array
		if(A[0] == target) {
			index = 0;
		} else {
			index = -1;
		}
	} else {
		pivot = findPivot(A, 0, n - 1);
		index = binarySearch(A, 0, pivot, target);
		if(index == -1) {
			index = binarySearch(A, pivot + 1, n - 1, target);
		}
	}
	return index;
}

int main() {
	int A[] = {3, 1};
	//{4, 5, 6, 7, 0, 1, 2};
	cout << search(A, 2, 0);
	return 0;
}
