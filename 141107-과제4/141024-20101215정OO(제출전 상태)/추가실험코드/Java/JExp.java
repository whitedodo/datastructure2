import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class JExp {
	
	public void create(List<Integer> jList, int n){
	
		int num;
		
		for (int i = 0; i < n; i++)
		{
			num = (int)(Math.random() * n) + 1;
			jList.add(Integer.valueOf(num));
		}
		
	}
	
	public void Sorting(List<Integer> jList)
	{
		Collections.sort(jList);
	}
	
	public void Print(List<Integer> jList){
		
		Iterator<Integer> iter = jList.iterator();
		
		while(iter.hasNext())
		{
			System.out.print(iter.next() + " ");
		} // end of while
		
		System.out.println();
		
	}
	
}
