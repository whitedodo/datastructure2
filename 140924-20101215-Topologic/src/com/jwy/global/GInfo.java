/*
	과제:프로그래밍(3번 - 위상정렬 구현 - 자바버전)
	금오공과대학교(Kumoh National Institute of Technology)
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정원영
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
