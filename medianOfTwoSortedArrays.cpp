/*
 * Median of Two sorted arrays
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
  if((m + n) % 2) {
    return findKthNum(A, 0, m - 1, B, 0, n - 1, (m + n + 1) / 2);
  } else {
    int a = findKthNum(A, 0, m - 1, B, 0, n - 1, (m + n) / 2);
	int b = findKthNum(A, 0, m - 1, B, 0, n - 1, (m + n) / 2 + 1);
	return (a + b)/2.0;
    //return (findKthNum(A, 0, m - 1, B, 0, n - 1, (m + n) / 2) + findKthNum(A, 0, m - 1, B, 0, n - 1, (m + n) / 2 - 1)) / 2.0;
  }
}

int findKthNum(int A[], int startA, int endA, int B[], int startB, int endB, int k) {
  if(endA == -1) {
	// Bug: B[k - 1]
    return B[startB + k - 1];
  }
  if(endB == -1) {
    // Bug: A[k - 1]
    return A[startA + k - 1];
  }
  if(endA < startA) {
    return B[startB + k - 1];
  }
  if(endB < startB) {
    return A[startA + k - 1];
  }
  if(k == 1) {
	// Bug: (A[0] <= B[0]) ? A[0] : B[0]
    return (A[startA] <= B[startB]) ? A[startA] : B[startB];
  }
  if(A[(startA + endA) / 2] >= B[(startB + endB) / 2]) {
    if((startA + endA) / 2 - startA + 1 + (startB + endB) / 2 - startB + 1 > k) {
	  return findKthNum(A, startA, (startA + endA) / 2 - 1, B, startB, endB, k);
	} else if((startA + endA) / 2 - startA + 1 + (startB + endB) / 2 - startB + 1 == k) {
	  // Bug: return A[(startA + endA) / 2];
	  return findKthNum(A, startA, endA, B, (startB + endB) / 2 + 1, endB, k - ((startB + endB) / 2 - startB + 1));
	} else {
	  return findKthNum(A, startA, endA, B, (startB + endB) / 2 + 1, endB, k - ((startB + endB) / 2 - startB + 1));
	}
  } else {
    if((startA + endA) / 2 - startA + 1 + (startB + endB) / 2 - startB + 1 > k) {
	  return findKthNum(A, startA, endA, B, startB, (startB + endB) / 2 - 1, k);
	} else if((startA + endA) / 2 - startA + 1 + (startB + endB) / 2 - startB + 1 == k) {
	  // Bug: return B[(startB + endB) / 2];
	  return findKthNum(A, (startA + endA) / 2 + 1, endA, B, startB, endB, k - ((startA + endA) / 2 - startA + 1));
	} else {
	  return findKthNum(A, (startA + endA) / 2 + 1, endA, B, startB, endB, k - ((startA + endA) / 2 - startA + 1));
	}
  }
} 
};
