// main : https://github.com/sgtlaugh/algovault/blob/master/code_library/radix_sort.cpp
// time complexity: O(4 * n)
const int  MAX = 1e8 + 7;
unsigned int temp[MAX], cnt[4][256];

void radix_sort(unsigned int *arr, int n) {
  for (int i = 0; i < n; i++) {
    ++cnt[0] [arr[i] & 255];
    ++cnt[1] [(arr[i] >> 8) & 255];
    ++cnt[2] [(arr[i] >> 16) & 255];
    ++cnt[3] [(arr[i] >> 24) & 255];
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < 256; j++) {
      cnt[i] [j] += cnt[i] [j - 1];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    temp[--cnt[0] [arr[i] & 255]] = arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    arr[--cnt[1] [(temp[i] >> 8) & 255]] = temp[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    temp[--cnt[2] [(arr[i] >> 16) & 255]] = arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    arr[--cnt[3] [(temp[i] >> 24) & 255]] = temp[i];
  }
}
