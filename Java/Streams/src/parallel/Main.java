package parallel;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

//Parallel: streams in concurrency

public class Main {

	public static void main(String[] args) {

		List<String> list = new ArrayList<String>(); 
		list.add("dfasd");
		list.add("rwiuo");
		list.add("rewjf");
		list.add("hello");
		list.add("apple");
		list.add("waterloo");
		list.add("syde");
		
		doReduce(list);
		
	}
	
	public static void doReduce(List<String> list){
		
		Optional<String> result = list
			.parallelStream() //use parallelStream() instead of standard stream()
			.sorted()
			.reduce((a, b) -> a + b);
		
		result.ifPresent(System.out::println);
			
	}

}
