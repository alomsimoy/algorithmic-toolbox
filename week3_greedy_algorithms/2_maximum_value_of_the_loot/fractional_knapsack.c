#include <stdio.h>

double get_optimal_value(int n, int capacity, int* weights, int* values) {
  double value = 0.0;

  while (capacity) {
  // Find the most valuable
      // printf("remaining: %d, ", capacity);
      double highest = 0.0;
      int index;
      for (int i = 0; i < n; i++) {
          double v = (double) values[i] / (double)weights[i];
          if (v > highest) {
              highest = v;
              index = i;
          }
      }
      // printf("index: %d, value: %1.4f, units: %d\n", index, highest, weights[index]);

      // fit the most of index
      if (capacity > weights[index]) {
          value += highest * (double) weights[index];
          capacity -= weights[index];
      } else {
          value += (double) values[index] / (double) weights[index] * (double) capacity;
          capacity = 0;
      }

      // remove that
      values[index] = 0;
  }

  return value;
}

int main()
{
    int n;
    int capacity;
    scanf("%d %d", &n, &capacity);

    int values[n], weights[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }

    double optimal_value = get_optimal_value(n, capacity, weights, values);

    printf("%1.4f\n", optimal_value);

    return 0;
}
