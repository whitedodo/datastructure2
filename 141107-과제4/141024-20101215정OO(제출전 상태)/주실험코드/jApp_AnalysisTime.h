
template <typename T>
void JApp<T>::CreateAnalysis(JTime* startTime, JTime* endTime, JUserVar* jvar){
	
	JTime* estTime = new JTime();
	std::string print_analysis_start;
	std::string print_analysis_end;
	std::string print_analysis_estimate;

	// ��� �ð�
	estTime->year = endTime->year - startTime->year;
	estTime->month = endTime->month - startTime->month;
	estTime->day = endTime->day - startTime->day;
	
	estTime->hour = abs(endTime->hour - startTime->hour);
	estTime->miniute = abs(endTime->miniute - startTime->miniute);
	estTime->sec = abs(endTime->sec - startTime->sec);
	estTime->usec = abs(endTime->usec - startTime->usec);

	// �� ���� �� ���� ��� ����

	print_analysis_start.append("������۽ð�:");
	print_analysis_start.append(JPatch::to_string(startTime->year));
	print_analysis_start.append(JPatch::to_string(startTime->month));
	print_analysis_start.append(JPatch::to_string(startTime->day));
	print_analysis_start.append(" ");
	print_analysis_start.append(JPatch::to_string(startTime->hour));
	print_analysis_start.append(":");
	print_analysis_start.append(JPatch::to_string(startTime->miniute));
	print_analysis_start.append(":");
	print_analysis_start.append(JPatch::to_string(startTime->sec));
	print_analysis_start.append(".");
	print_analysis_start.append(JPatch::to_string(startTime->usec));

	jvar->SetPrintAnalysisStart(print_analysis_start);

	// ���� ����ð�
	print_analysis_end.append("��������ð�:");
	print_analysis_end.append(JPatch::to_string(endTime->year));
	print_analysis_end.append(JPatch::to_string(endTime->month));
	print_analysis_end.append(JPatch::to_string(endTime->day));
	print_analysis_end.append(" ");
	print_analysis_end.append(JPatch::to_string(endTime->hour));
	print_analysis_end.append(":");
	print_analysis_end.append(JPatch::to_string(endTime->miniute));
	print_analysis_end.append(":");
	print_analysis_end.append(JPatch::to_string(endTime->sec));
	print_analysis_end.append(".");
	print_analysis_end.append(JPatch::to_string(endTime->usec));

	jvar->SetPrintAnalysisEnd(print_analysis_end);

	// �Ѵ� �̳��� ������.
	print_analysis_estimate.append("����ð�:*");
	int sum = estTime->hour + estTime->day * 24 + estTime->sec;

	print_analysis_estimate.append(JPatch::to_string(sum));
	print_analysis_estimate.append(".");
	print_analysis_estimate.append(JPatch::to_string(estTime->usec));
	print_analysis_estimate.append("*");

	jvar->SetPrintAnalysisEstimate(print_analysis_estimate);

}