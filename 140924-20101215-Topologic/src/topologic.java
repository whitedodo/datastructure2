/*
	과제:프로그래밍(3번 - 위상정렬 구현 - 자바버전)
	금오공과대학교(Kumoh National Institute of Technology)
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정원영
*/

import java.util.LinkedList;
import java.util.Scanner;
import java.util.Queue;
import com.jwy.global.*;

class topologic{
	
	public static void main(String Argc[]) throws Exception{
		
		String choose = common.EMPTY;
		String Filename = common.EMPTY;
		String D = common.EMPTY;
		
		Queue<Integer> queueApp = new LinkedList<Integer>();			// 큐 Util.Queue Library 이용 (구현 생략)
	
		GInfo GraphInfo = new GInfo();		// 그래프에 필요한 원소 정보(Vertex, Edge)
		
		while(choose != common.CMD_QUIT){

			@SuppressWarnings("resource")
			Scanner scanner = new Scanner(System.in);
			Graph graphApp;
			
			System.out.print("프로그램을 선택하세요 ([S]earch / [M]inimum cost spanning tree / ");
			System.out.print("[T]opological Sort / [Q]uit) :");
			
			choose = scanner.next();

			// 프로그램 종료 판단
			if(choose.equals(common.CMD_QUIT))
			{
				System.out.println("프로그램을 종료합니다.\n");
				break;
			} // end of if
			
			// 사용자 입력 메뉴
			switch(choose)
			{
				case common.CMD_SEARCH:
					System.out.println("현재 C++ 버전만 지원합니다.");
					break;
			
				case common.CMD_MINIMUM:
					System.out.println("현재 C++ 버전만 지원합니다.");
					break;
			
				case common.CMD_TOPOLOGICAL:
					
					System.out.print("방향 그래프가 저장된 파일명을 입력하시요(종료는 quit): ");
					Filename = scanner.next();
					D = io.GetFileRead(Filename, GraphInfo);
					
					if(GraphInfo.Peak()){
							
						graphApp = new Graph(GraphInfo);
	
						graphApp.SetOfMatrix(GraphInfo, D); // 행렬 셋팅
						graphApp.PrintOut(GraphInfo);  //  입력된 그래프의 인접행렬 표현
						
						graphApp.Topologic(GraphInfo, queueApp);
						
					}else
						System.out.println("비정상적인 자료입니다.");

					break;
					
				case common.CMD_QUIT:
					// 종료 기능 확보
					break;
					
				default:
					// 비정상 기능
					break;
					
			} // end of switch
			
		} // end of while
		
	} // end of void
	
}
