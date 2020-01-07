/*
	����:���α׷���(3�� - �������� ���� - �ڹٹ���)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
*/

package com.jwy.global;

import java.util.Stack;
import java.util.Queue;
import com.jwy.global.GInfo;
import com.jwy.global.common;

public class Graph {

	private final int GRAPH_COMPONENT = 2;
	
	private int count;
	private int Visited[];
	private int Matrix[][];
	
	public Graph(GInfo GraphInfo){
	
		int V = common.NULL;
		V = GraphInfo.GetVertex();
		
		Matrix = new int[V][V];
	
		for(int i = 0; i < V; i++)
		{
			
			for(int j = 0; j < V; j++)
			{
				Matrix[i][j] = common.FALSE;
			} // end of for
			
		} // end of for
		
	}
	
	public void Init_Visited(int V){
		
		Visited = new int[V];
		
		for(int i = 0; i < V; i++)
			Visited[i] = common.NULL;
		
	}
	
	public void PrintOut(GInfo GraphInfo){
		
		int V = GraphInfo.GetVertex();
		
		System.out.println("�Էµ� �׷����� ���� ��� ǥ��");
		
		for(int i = 0; i < V; i++)
		{
			for(int j = 0; j < V; j++)
			{
				System.out.print(Matrix[i][j] + " ");
			} // end of for
			
			System.out.println();
			
		} // end of for
		
		System.out.println();
	
	} // end of void

	
	public void SetOfMatrix(GInfo GraphInfo, String D)
	{
		
		int size = D.length();
		int x, y;
		int num;
		int ChkContinue = common.FALSE;
		char chData;
		
		Stack<Integer> stackApp = new Stack<Integer>();
		
		
		// ī��Ʈ �ʱ�ȭ
		SetCount(0);
		
		for(int i = 0; i < size; i++){
		
			chData = D.charAt(i);
			
			if(chData == '\n')
			{
				if(!stackApp.isEmpty() && GetCount() == GRAPH_COMPONENT)
				{
					y = stackApp.pop();
					x = stackApp.pop();
					
					Matrix[x][y] = common.TRUE;
				} // end of if
				
				while(!stackApp.isEmpty())
					stackApp.pop();
				
				SetCount(0);
				ChkContinue = common.FALSE;
				
				continue;
				
			} // end of if
			
			if(chData == ' '){
				
				if(!stackApp.isEmpty() && GetCount() == GRAPH_COMPONENT)
				{
					y = stackApp.pop();
					x = stackApp.pop();
					
					Matrix[x][y] = common.TRUE;
					
					SetCount(0);
				} // end of if
				
				ChkContinue = common.FALSE;
				
			}
			else
			{
				if(ChkContinue == common.FALSE)
				{
					num = Character.getNumericValue(chData);
					stackApp.push(num);
					ChkContinue = common.TRUE;
					
					SetCount(GetCount() + 1);
					
				}else
				{
					num = stackApp.pop();
					num = num * 10;
					num = num + Character.getNumericValue(chData);
					stackApp.push(num);
					
				} // end of if
				
			} // end of if
			
		} // end of for
		
	} // end of void

	public void Topologic(GInfo GraphInfo, Queue<Integer> queueApp)
	{

		// DFS�� �̿��� ���� ����
		DFS(GraphInfo, queueApp);
		
		if(queueApp.peek() != null)
			System.out.print("������ �ϳ��� ���� ���� : ");
		
		while(queueApp.peek() != null)
		{
			System.out.print(queueApp.poll() + " ");
		} // end of while
		
		System.out.println();
	}
	
	public void DFS(GInfo GraphInfo, Queue<Integer> queueApp){
		
		int V = GraphInfo.GetVertex();	// ���� V(Vertex)
		
		// Visited �ʱ�ȭ
		Init_Visited(V);
		
		for(int i = 0; i < V; i++)
			DFS_Recur(V, i, queueApp);
	}
	
	private void DFS_Recur(int V, int i, Queue<Integer> queueApp)
	{
		int w;
		
		if(Visited[i] == common.FALSE)
		{
			
			Visited[i] = common.TRUE;
			queueApp.offer(i);
			
		} // end of
		
		w = 0;
		
		while(w < V)
		{
			
			if(Matrix[i][w] == common.TRUE)
			{
				
				if(Visited[w] == common.FALSE)
				{
					DFS_Recur(V, w, queueApp);
				} // end of if
				
			} // end of if
			
			w++;
			
		} // end of while
		
	} // end of void
	
	private void SetCount(int count){
		this.count = count;
	}
	
	private int GetCount(){
		return this.count;
	}
	
}
