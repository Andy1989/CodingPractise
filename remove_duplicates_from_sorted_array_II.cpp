/* Remove Duplicates from Sorted Array II
 * Given a sorted array, remove the duplicates in place such that 
 * each element appear at most twice and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this 
 * in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

#include<iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
	int i = 0, j = 0, k = 0;
	if(n < 3) {
		return n;
	}
	while(j < n) {
		if(k == 0) {
			A[i++] = A[j++];
			k++;
		} else if(k == 1) {
			if(A[j] == A[j - 1]) {
				A[i++] = A[j++];
				k++;
			} else {
				A[i++] = A[j++];
			}
		} else if(k == 2) {
			if(A[j] == A[j - 1]) {
				j++;
			} else {
				A[i++] = A[j++];
				k = 1;
			}
		}
	}
	return i;
}

int main() {
	int A[] = {1,2,2};
	//{1, 2, 3, 4, 5};
	//{1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
	int length;
	length = removeDuplicates(A, 3);
	cout << length << endl;
	for(int i = 0; i < length; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
