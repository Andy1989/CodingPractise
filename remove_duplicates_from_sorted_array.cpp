/* Remove Duplicates from Sorted Array 
 * Given a sorted array, remove the duplicates in place such that 
 * each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this 
 * in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 */

#include<iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
	int i = 0, j = 1;
	if(n < 2) {
		return n;
	}
	while(j < n) {
		if(A[i] == A[j])	j++;
		else if(j - i == 1) {
			i++;
			j++;
		} else {
			A[++i] = A[j++];
		}
	}
	return (i + 1);
}

int main() {
	int A[] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
	int length;
	length = removeDuplicates(A, 11);
	cout << length << endl;
	for(int i = 0; i < length; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
