
template <>
void JApp<std::string>::PrintInWriter(std::string* data, const int printtype, JUserVar* jvar){

	std::string print_title;
	std::string print_memo;

	switch (printtype)
	{
		case TYPE_PRINT_ON:

			print_title = "정렬 후 결과\n";

			for (int i = 0; i < jvar->GetUserSize(); i++)
			{
				print_memo.append(data[i]);
				print_memo.append(" ");
			}

			print_memo.append("\n");

			jvar->SetPrintOnTitle(print_title);
			jvar->SetPrintOnMemo(print_memo);

			break;

		case TYPE_PRINT_OFF:

			print_title = "정렬 전 결과\n";

			for (int i = 0; i < jvar->GetUserSize(); i++)
			{
				print_memo.append(JPatch::to_string(data[i]));
				print_memo.append(" ");
			}

			print_memo.append("\n");

			jvar->SetPrintOffTitle(print_title);
			jvar->SetPrintOffMemo(print_memo);

			break;

	} // end of switch

}

template <typename T>
void JApp<T>::PrintInWriter(T* data, const int printtype, JUserVar* jvar){

	std::string print_title;
	std::string print_memo;

	switch (printtype)
	{
		case TYPE_PRINT_ON:

			print_title = "정렬 후 결과\n";

			for (int i = 0; i < jvar->GetUserSize(); i++)
			{
				print_memo.append(JPatch::to_string(data[i]));
				print_memo.append(" ");
			}

			print_memo.append("\n");

			jvar->SetPrintOnTitle(print_title);
			jvar->SetPrintOnMemo(print_memo);

			break;

		case TYPE_PRINT_OFF:

			print_title = "정렬 전 결과\n";

			for (int i = 0; i < jvar->GetUserSize( ); i++)
			{
				print_memo.append(JPatch::to_string(data[i]));
				print_memo.append(" ");
			}

			print_memo.append("\n");

			jvar->SetPrintOffTitle(print_title);
			jvar->SetPrintOffMemo(print_memo);

			break;

	} // end of switch
}

template <>
void JApp<std::string>::PrintInWriter(Node<std::string>* data, const int printtype, JUserVar* jvar)
{
	Node<std::string>* ptr = data;

	std::string print_title;
	std::string print_memo;

	switch (printtype)
	{

		case TYPE_PRINT_ON:

			print_title = "정렬 후 결과\n";

			while (ptr != NULL)
			{
				print_memo.append(ptr->data);
				print_memo.append(" ");
				ptr = ptr->next;
			} // end of while

			print_memo.append("\n");

			jvar->SetPrintOnTitle(print_title);
			jvar->SetPrintOnMemo(print_memo);

			break;

		case TYPE_PRINT_OFF:

			print_title = "정렬 전 결과\n";

			while (ptr != NULL)
			{
				print_memo.append(ptr->data);
				print_memo.append(" ");
				ptr = ptr->next;
			} // end of while


			print_memo.append("\n");

			jvar->SetPrintOffTitle(print_title);
			jvar->SetPrintOffMemo(print_memo);

			break;

	} // end of switch

}

template <typename T>
void JApp<T>::PrintInWriter(Node<T>* data, const int printtype, JUserVar* jvar)
{
	Node<T>* ptr = data;

	std::string print_title;
	std::string print_memo;

	switch (printtype)
	{
		case TYPE_PRINT_ON:
			print_title = "정렬 후 결과\n";

			while (ptr != NULL)
			{
				print_memo.append(JPatch::to_string(ptr->data));
				print_memo.append(" ");
				ptr = ptr->next;
			} // end of while

			print_memo.append("\n");

			jvar->SetPrintOnTitle(print_title);
			jvar->SetPrintOnMemo(print_memo);

			break;

		case TYPE_PRINT_OFF:

			print_title = "정렬 전 결과\n";

			while (ptr != NULL)
			{
				print_memo.append(JPatch::to_string(ptr->data));
				print_memo.append(" ");
				ptr = ptr->next;
			} // end of while


			print_memo.append("\n");

			jvar->SetPrintOffTitle(print_title);
			jvar->SetPrintOffMemo(print_memo);

			break;

	} // end of switch

}