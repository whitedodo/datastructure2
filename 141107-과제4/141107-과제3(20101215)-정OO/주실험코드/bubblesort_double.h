
/// Bubble Sort
template <>
void Sort<double>::BubbleSort(double* data, const int n){

	int i, j;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (data[j] > data[j + 1])
				Swap(data, j, j + 1);

			j++;
		} // end of while

		i++;
	} // end of while

}

// End of Bubble Sort
