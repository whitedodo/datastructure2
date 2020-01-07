/*
	과제:프로그래밍(3번 - 위상정렬 구현 - 자바버전)
	금오공과대학교(Kumoh National Institute of Technology)
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정원영
*/

package com.jwy.global;
import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import com.jwy.global.common;
import com.jwy.global.GInfo;

public class io {
		
	public static String GetFileRead(String Filename, GInfo G_Info) throws Exception{
		
		int V = common.NULL;
		int E = common.NULL;
		
		String Data = "";
		String Put = "1";
		File f = new File(Filename);
		
		if(f.exists())
		{
			try{
				BufferedReader in = new BufferedReader(new FileReader(Filename));
				
				while((Put = in.readLine()) != null)
				{
					Data = Data + Put + "\n";
					
					if(Data.length() <= 4 && Data.length() >= 0){
						V = Character.getNumericValue(Data.charAt(0)); // 파일 첫 번째 단락이 Vertex라는 점을 이용
					}
					else
					{
						if(!Put.equals("-1"))
							E++;
					}
					
					// end of if
					
				} // end of while

				in.close();
			}
			catch(IOException e){
				System.out.println(Data);
			} // end in try
			
			G_Info.SetInfo(V, E);
			
			return Data;
		}
		else
			return "";
	};
	
}
