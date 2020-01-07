
/// LinkedInsertSort

template <>
void Sort<std::string>::LinkedInsertSort(Node<std::string>* ptrNode){

	Node<std::string>* first = ptrNode;
	first = first->next;

	Node<std::string>* second = NULL;
	Node<std::string>* prevNode = NULL;

	std::string key;

	while (first != NULL)
	{
		key = first->data;
		second = first->prev;

		while (second != NULL)
		{
			prevNode = second;

			if (second->data.compare(key) == 1)
			{
				second->next->data = second->data;
			}
			else
				break;

			second = second->prev;

		} // end of while

		if (prevNode != NULL && prevNode != second)
			prevNode->data = key;
		else
			second->next->data = key;

		first = first->next;

	} // end of while
}

template <>
void Sort<double>::LinkedInsertSort(Node<double>* ptrNode){

	Node<double>* first = ptrNode;
	first = first->next;

	Node<double>* second = NULL;
	Node<double>* prevNode = NULL;

	double key;

	while (first != NULL)
	{
		key = first->data;
		second = first->prev;

		while (second != NULL)
		{
			prevNode = second;

			if (CompareDoubleAbsoulte(second->data, key) == 1)
			{
				second->next->data = second->data;
			}
			else
				break;

			second = second->prev;

		} // end of while

		if (prevNode != NULL && prevNode != second)
			prevNode->data = key;
		else
			second->next->data = key;

		first = first->next;

	} // end of while
}

template <typename T>
void Sort<T>::LinkedInsertSort(Node<T>* ptrNode){

	Node<T>* first = ptrNode;
		     first = first->next;

	Node<T>* second = NULL;
	Node<T>* prevNode = NULL;
	
	T key;

	while (first != NULL)
	{
		key = first->data;
		second = first->prev;

		while (second != NULL)
		{
			prevNode = second;

			if (second->data > key)
			{
				second->next->data = second->data;
			}
			else
				break;

			second = second->prev;
		
		} // end of while

		if (prevNode != NULL && prevNode != second)
			prevNode->data = key;
		else
			second->next->data = key;

		first = first->next;

	} // end of while
}
// End of Linked Insert Sort