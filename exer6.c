#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

int includes(int *arr, int sz, int target);

int main(void) {
  int sz, target, target_index, *arr;

  printf("Enter size of array: ");
  scanf("%d", &sz);

  // allocate `sz` ints
  arr = (int *)malloc(sz * sizeof *arr);

  printf("Enter elements in array: ");
  for (int i = 0; i < sz; i++) {
    scanf("%d", arr + i);
  }

  printf("Enter element to search: ");
  scanf("%d", &target);

  target_index = includes(arr, sz, target);
  if (target_index == NOT_FOUND)
    printf("%d does not exist in the array.\n", target);
  else
    printf("%d is found at index %d\n", target, target_index);

  return 0;
}

int includes(int *arr, int sz, int target) {
  /**
   * Takes an input `arr`, and a `target` to be searhed. When found, this
   * returns the index of `target` in `arr`, otherwise `NOT_FOUND`.
   */
  for (int i = 0; i < sz; i++) {
    if (*(arr + i) == target)
      return i;
  }

  return NOT_FOUND;
}
