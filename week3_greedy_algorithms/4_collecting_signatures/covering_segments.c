#include <stdio.h>
#include <stdlib.h>

struct Segment {
  int start, end;
};

int segment_cmp(const void *a, const void *b)
{
    const struct Segment sa = *(struct Segment *)a;
    const struct Segment sb = *(struct Segment *)b;
    return sa.end - sb.end;
}

int optimal_points(struct Segment* segments, int size, int* points) {
    int length = 0;

    // sort segments
    qsort(segments, size, sizeof(struct Segment), segment_cmp);

    for (int i = 0; i < size;) {
        // printf("(%d,%d)\n", segments[i].start, segments[i].end);
        int point = segments[i].end;
        points[length] = point;
        length++;
        i++;
        while(point >= segments[i].start && point <= segments[i].end) {
            i++;
        }
    }

    return length;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Segment segments[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &segments[i].start, &segments[i].end);
    }

    int points[n];
    int size = optimal_points(segments, n, points);

    printf("%d\n", size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", points[i]);
    }

    printf("\n");
}
