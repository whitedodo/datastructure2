/*
	����:���α׷���(3�� - �������� ���� - �ڹٹ���)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
*/

package com.jwy.global;

public class GInfo {
	
	private int V;
	private int E;
	
	public int GetVertex(){
		return this.V;
	}
	
	public int GetEdge(){
		return this.E;
	}

	public void SetInfo(int V, int E){
		this.V = V;
		this.E = E;
	}
	
	public void Vertex(int V){
		this.V = V;
	}
	
	public void Edge(int E){
		this.E = E;
	}
	
	public boolean Peak(){
		
		boolean check = true;
		
		if(V == 0 || E == 0)
			check = false;
		
		return check;
	}
	
}
