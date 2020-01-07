import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TaskManager {

	public void MenuOfAuto(int Arr[]) throws IOException
	{	
		
		long start, end;
		double estimate;
		StringBuilder sb = new StringBuilder();
		FileWriter fw = new FileWriter("report.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		
		int sampleArr[] = new int[5];
		
		JExp jexp = new JExp();
		List<Integer> jList = new ArrayList<Integer>();

		
		sampleArr[0] = 1000;
		sampleArr[1] = 5000;
		sampleArr[2] = 10000;
		sampleArr[3] = 50000;
		sampleArr[4] = 100000;
		
		sb.append("Java Integer형 Collection");
		
		sb.append("\r\n");
		
		for(int i = 0; i < sampleArr.length; i++)
		{
			jexp.create(jList, sampleArr[i]);
			
			System.out.print(sampleArr[i] + "번 / ");
			
			start = System.currentTimeMillis();
			jexp.Sorting(jList);
			end = System.currentTimeMillis();
			
			estimate = (end - start);
			System.out.println("경과시간:" + (estimate / 100));
			
			if( ( i + 1 ) == sampleArr.length){
				sb.append(sampleArr[i] + ",");
				sb.append( Double.valueOf ( estimate / 100 ) );
			}
			else{
				sb.append(sampleArr[i] + ",");
				sb.append( Double.valueOf ( estimate / 100) + "\r\n" );
			}
		}

		System.out.print("출력할 파일명: report.txt\n\n");
		bw.write(String.valueOf(sb));
		bw.close();
		
		
	}
	
	public void MenuOfManual(int Arr[]){

		int n;
		long start, end;
		double estimate;

		JExp jexp = new JExp();
		List<Integer> jList = new ArrayList<Integer>();
		
		Scanner scan = new Scanner(System.in);

		System.out.print("입력:");
		n = scan.nextInt();
		
		jexp.create(jList, n);
		
		start = System.currentTimeMillis();
		jexp.Sorting(jList);
		end = System.currentTimeMillis();
		
		estimate = (end - start);
		System.out.println("경과시간:" + (estimate / 100));			
		System.out.println();
		
	}
	
}
