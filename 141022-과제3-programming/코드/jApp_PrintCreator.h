
template <typename T>
void JApp<T>::PrintCreate(Node<T>* data, T* Arr, const int printtype, JUserVar* jvar){

	switch ( jvar->GetDataType( ) )
	{
		case PRINT_LINKED:		// 연결 구조 형식
			PrintInWriter(data, printtype, jvar);
			break;

		case PRINT_NORMAL:		// 보통 구조 형식
			PrintInWriter(Arr, printtype, jvar);

		default:
			break;
	}

}

template <typename T>
void JApp<T>::PrintCreate(JPolygonList<T>* data, int* Arr, const int printtype, JUserVar* jvar){

	double x, y;
	double result;

	std::string print_title;
	std::string print_memo;

	switch (printtype)
	{
	case TYPE_PRINT_ON:

		print_title = "정렬 후 결과\n";

		for (int i = 0; i < jvar->GetUserSize(); i++)
		{
			print_memo.append("Arr[");
			print_memo.append(JPatch::to_string(Arr[i]));
			print_memo.append("],Data,");

			switch (jvar->GetCriticType())
			{
				case POLY_TYPE_X:
					x = data[Arr[i]].position->GetX();
					print_memo.append(JPatch::to_string(x));
					break;

				case POLY_TYPE_Y:
					y = data[Arr[i]].position->GetY();
					print_memo.append(JPatch::to_string(y));
					break;

				case POLY_TYPE_WEIGHT:
					x = data[Arr[i]].position->GetX();
					y = data[Arr[i]].position->GetY();
					result = x * y;

					if (result <= 2500)
						print_memo.append(JPatch::to_string(result));
					else
						print_memo.append(JPatch::to_string((int)result));

					break;

				default:
					break;
			} // end of switch

			print_memo.append("");
			print_memo.append("\n");

		} // end of for 

		print_memo.append("\n");

		jvar->SetPrintOnTitle(print_title);
		jvar->SetPrintOnMemo(print_memo);

		break;

	case TYPE_PRINT_OFF:

		print_title = "정렬 전 결과\n";

		for (int i = 0; i < jvar->GetUserSize(); i++)
		{
			print_memo.append("Arr[");
			print_memo.append(JPatch::to_string(Arr[i]));
			print_memo.append("],Data,");

			switch (jvar->GetCriticType())
			{
				case POLY_TYPE_X:
					x = data[Arr[i]].position->GetX();
					print_memo.append(JPatch::to_string(x));
					break;

				case POLY_TYPE_Y:
					y = data[Arr[i]].position->GetY();
					print_memo.append(JPatch::to_string(y));
					break;

				case POLY_TYPE_WEIGHT:
					x = data[Arr[i]].position->GetX();
					y = data[Arr[i]].position->GetY();
					result = x * y;
					print_memo.append(JPatch::to_string(result));
					break;

				default:
					break;

			} // end of switch

			print_memo.append("\n");
		
		} // end of for

		print_memo.append("\n");

		jvar->SetPrintOffTitle(print_title);
		jvar->SetPrintOffTitle(print_memo);

		break;

	} // end of switch

}
