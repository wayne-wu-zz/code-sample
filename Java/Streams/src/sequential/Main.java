package sequential;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;

//Sequential: Single Thread operations

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
		
		doFilter(list);
		doSort(list);
		doMap(list);
		doCount(list);
		doReduce(list);
		
	}

	public static void doFilter(List<String> list){ 
		list
			.stream() //creates stream
			.filter((item) -> item.startsWith("r")) //filter the stream based in prefix
			.forEach(System.out::println);
	}
	
	public static void doSort(List<String> list){
		list
			.stream()
			.sorted((a, b) -> a.compareTo(b))  //sort the stream based on own comparator
			.filter((item) -> item.startsWith("r"))
			.forEach(System.out::println);
		
	}
	
	public static void doMap(List<String> list){
		list
			.stream()
			.sorted()
			.filter((item) -> item.endsWith("o"))
			.map(String::toUpperCase)
			.forEach(System.out::println);
		
	}
	
	public static void doCount(List<String> list){
		long count = list
			.stream()
			.filter((item) -> item.endsWith("o"))
			.count();
		
		System.out.println(count);
	}
	
	public static void doReduce(List<String> list){
		Optional<String> result = list
			.stream()
			.filter((item) -> item.endsWith("o"))
			.map(String::toUpperCase)
			.reduce((a, b) -> a + b);
		
		result.ifPresent(System.out::println);
	}
	
}
