/*
	����:���α׷���(3�� - �������� ���� - �ڹٹ���)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
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
						V = Character.getNumericValue(Data.charAt(0)); // ���� ù ��° �ܶ��� Vertex��� ���� �̿�
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
