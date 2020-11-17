public static void Sort<T>(List<T> list) where T : IComparable
{
    if (list.Count > 1)
    {
        StoogeSort(list, 0, list.Count - 1);
    }
}

private static void StoogeSort<T>(List<T> L, int i, int j) where T : IComparable
{
    if (L[j].CompareTo(L[i]) < 0)
    {
        T tmp = L[i];
        L[i] = L[j];
        L[j] = tmp;
    }
    if (j - i > 1)
    {
        int t = (j - i + 1) / 3;
        StoogeSort(L, i, j - t);
        StoogeSort(L, i + t, j);
        StoogeSort(L, i, j - t);
    }
}