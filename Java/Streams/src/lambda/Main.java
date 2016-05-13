package lambda;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		List<String> list = Arrays.asList("peter", "jason", "wayne", "philos");
		
		//traditional(list);
		use_lambda(list);
		
		for(String item : list){
			System.out.println(item);
		}
	}
	
	public static void traditional(List<String> list){
		
		Collections.sort(list, new Comparator<String>(){
			
			public int compare(String a, String b) {
				// TODO Auto-generated method stub
				return b.compareTo(a);
			}
			
		});
	}
	
	public static void use_lambda(List<String> list){
	
		// Collections.sort(list, (String a, String b) -> {
		//	return b.compareTo(a);
		//	});
		
		//Collections.sort(list, (String a, String b) -> b.compareTo(a));
		
		Collections.sort(list, (a, b) -> b.compareTo(a));
		
	}
}
