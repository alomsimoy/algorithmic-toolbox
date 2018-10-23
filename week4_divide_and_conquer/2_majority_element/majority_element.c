#include <stdio.h>

int get_majority_element(int* a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = left + (right - left) / 2;
  int l = get_majority_element(a, left, mid - 1);
  int r = get_majority_element(a, mid, right);
  if (l == r)
	  return l;
  
  return -1;
}

int has_majority(int* a, int n) {
	int elements[100000];
	for(int i = 0; i < 100000; i++)
		elements[i] = 0;
	for(int i = 0; i < n; i++) {
		elements[a[i]]++;
		if(elements[a[i]] > n / 2)
			return 1;
	}
	return 0;
}

int find_candidate(int* a, int n) {
	int index = 0, count = 1;
	for(int i = 1; i < n; ++i) {
		if(a[index] == a[i])
			++count;
		else
			--count;
		if(count == 0) {
			index = i;
			count = 1;
		}
	}
	return a[index];
}

int is_majority(int* a, int n, int candidate) {
	int count = 0;
	int mid = n / 2;
	for(int i = 0; i < n; ++i) {
		if(a[i] == candidate)
			count++;
		if(count > mid)
			return 1;
	}
	return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; ++i) {
	  scanf("%d", &a[i]);
  }
  
  int candidate = find_candidate(a, n);
  printf("%d\n", is_majority(a, n, candidate));
  // printf("%d\n", has_majority(a, n));
  // printf("%d\n", get_majority_element(a, 0, n));
}

