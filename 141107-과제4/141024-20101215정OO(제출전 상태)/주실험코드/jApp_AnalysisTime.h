
template <typename T>
void JApp<T>::CreateAnalysis(JTime* startTime, JTime* endTime, JUserVar* jvar){
	
	JTime* estTime = new JTime();
	std::string print_analysis_start;
	std::string print_analysis_end;
	std::string print_analysis_estimate;

	// 경과 시간
	estTime->year = endTime->year - startTime->year;
	estTime->month = endTime->month - startTime->month;
	estTime->day = endTime->day - startTime->day;
	
	estTime->hour = abs(endTime->hour - startTime->hour);
	estTime->miniute = abs(endTime->miniute - startTime->miniute);
	estTime->sec = abs(endTime->sec - startTime->sec);
	estTime->usec = abs(endTime->usec - startTime->usec);

	// 각 유형 별 수집 결과 정리

	print_analysis_start.append("실험시작시간:");
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

	// 실험 종료시간
	print_analysis_end.append("실험종료시간:");
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

	// 한달 이내만 측정됨.
	print_analysis_estimate.append("경과시간:*");
	int sum = estTime->hour + estTime->day * 24 + estTime->sec;

	print_analysis_estimate.append(JPatch::to_string(sum));
	print_analysis_estimate.append(".");
	print_analysis_estimate.append(JPatch::to_string(estTime->usec));
	print_analysis_estimate.append("*");

	jvar->SetPrintAnalysisEstimate(print_analysis_estimate);

}