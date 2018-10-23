#include <stdio.h>

int binary_search(int* a, int n, int x) {
  int left = 0, right = n; 
  while(left <= right) {
	  int mid = left + (right - left) / 2;
	  // printf("Mid %d\n", mid);
	  if(x == a[mid])
		  return mid;
	  if(x < a[mid])
		  right = mid - 1;
	  else
		  left = mid + 1;
  }

  return -1;
}

int linear_search(int* a, int n, int x) {
  for (int i = 0; i < n; ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  scanf("%d ", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int m;
  scanf("%d ", &m);
  int b[m];
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    // printf("%d ", linear_search(a, n, b[i]));
    printf("%d ", binary_search(a, n, b[i]));
  }
  printf("\n");
}

