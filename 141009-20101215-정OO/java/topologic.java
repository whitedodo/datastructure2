/*
	����:���α׷���(3�� - �������� ���� - �ڹٹ���)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
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
		
		Queue<Integer> queueApp = new LinkedList<Integer>();			// ť Util.Queue Library �̿� (���� ����)
	
		GInfo GraphInfo = new GInfo();		// �׷����� �ʿ��� ���� ����(Vertex, Edge)
		
		while(choose != common.CMD_QUIT){

			@SuppressWarnings("resource")
			Scanner scanner = new Scanner(System.in);
			Graph graphApp;
			
			System.out.print("���α׷��� �����ϼ��� ([S]earch / [M]inimum cost spanning tree / ");
			System.out.print("[T]opological Sort / [Q]uit) :");
			
			choose = scanner.next();

			// ���α׷� ���� �Ǵ�
			if(choose.equals(common.CMD_QUIT))
			{
				System.out.println("���α׷��� �����մϴ�.\n");
				break;
			} // end of if
			
			// ����� �Է� �޴�
			switch(choose)
			{
				case common.CMD_SEARCH:
					System.out.println("���� C++ ������ �����մϴ�.");
					break;
			
				case common.CMD_MINIMUM:
					System.out.println("���� C++ ������ �����մϴ�.");
					break;
			
				case common.CMD_TOPOLOGICAL:
					
					System.out.print("���� �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit): ");
					Filename = scanner.next();
					D = io.GetFileRead(Filename, GraphInfo);
					
					if(GraphInfo.Peak()){
							
						graphApp = new Graph(GraphInfo);
	
						graphApp.SetOfMatrix(GraphInfo, D); // ��� ����
						graphApp.PrintOut(GraphInfo);  //  �Էµ� �׷����� ������� ǥ��
						
						graphApp.Topologic(GraphInfo, queueApp);
						
					}else
						System.out.println("���������� �ڷ��Դϴ�.");

					break;
					
				case common.CMD_QUIT:
					// ���� ��� Ȯ��
					break;
					
				default:
					// ������ ���
					break;
					
			} // end of switch
			
		} // end of while
		
	} // end of void
	
}
