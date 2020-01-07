import java.util.Scanner;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.io.*;

public class sortJWY{
	
	public final static int  MENU_MANUAL = 1;
	public final static int  MENU_AUTO = 2;
	
	public static void main(String args[]) throws Exception{
		
		int SELECT;
		int Arr[] = null;
		Scanner scan = new Scanner(System.in);
		
		TaskManager tm = new TaskManager();
		
		while(true)
		{
			System.out.println("OOOOOOOOOOO교");
			System.out.println("Dept Business and Computer Software Engineering");
			System.out.println("Jeong OO(20101215)");
			System.out.println("추가실험 : Java Collections Sort");
			
			System.out.println("1번 : 수동조작");
			System.out.println("2번 : 자동조작");
			System.out.println("0번 : 탈출");
			System.out.print("메뉴를 입력하세요: ");
			
			SELECT = scan.nextInt();
			
			// 탈출 조건
			if(SELECT == 0)
				break;
			
			switch(SELECT)
			{
					case MENU_MANUAL:
						tm.MenuOfManual(Arr);
						break;
						
					case MENU_AUTO:
						tm.MenuOfAuto(Arr);
						break;
			
			
			} // end of switch
			
			
		} // end of while
	
		
	}
	
}