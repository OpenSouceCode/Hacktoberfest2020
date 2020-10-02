int partition(List list, int low, int high) {
  if (list == null || list.length == 0) return 0;
  int pivot = list[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (list[j] <= pivot) {
      i++;
      swap(list, i, j);
    }
  swap(list, i+1, high);
  return i+1;
}

void swap(List list, int i, int j) {
  int temp = list[i];
  list[i] = list[j];
  list[j] = temp;
}

void quickSort(List list, int low, int high) {
  if (low < high) {
    int pi = partition(list, low, high);
    quickSort(list, low, pi-1);
    quickSort(list, pi+1, high);
  }
}
