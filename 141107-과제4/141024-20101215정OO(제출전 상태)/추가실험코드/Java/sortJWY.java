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
			System.out.println("OOOOOOOOOOO��");
			System.out.println("Dept Business and Computer Software Engineering");
			System.out.println("Jeong OO(20101215)");
			System.out.println("�߰����� : Java Collections Sort");
			
			System.out.println("1�� : ��������");
			System.out.println("2�� : �ڵ�����");
			System.out.println("0�� : Ż��");
			System.out.print("�޴��� �Է��ϼ���: ");
			
			SELECT = scan.nextInt();
			
			// Ż�� ����
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