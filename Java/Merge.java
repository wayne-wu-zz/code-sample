//Author: Wayne Wu

public class Merge {
	
	public static void sort(int[] num){
		int[] aux = new int[num.length];
		sort(num, aux, 0, num.length-1);
	}
	
	private static void sort(int[] num, int[] aux, int lo, int hi){
		if(lo < hi){
			int mid = lo + (hi-lo)/2;
			sort(num, aux, lo, mid); //sort left side;
			sort(num, aux, mid+1, hi); //sort right side;
			merge(num, aux, lo, mid, hi); //merge both side;
			
		}
	}
	
	private static void merge(int[] num, int[] aux, int lo, int mid, int hi){
		
		for(int i = lo; i <= hi; i ++){
			aux[i] = num[i];
		}
		
		int i = lo; 
		int j = mid+1;
		for(int k = lo; k<=hi; k++){
			if(i>mid) 	           num[k] = aux[j++]; //left side is done, add the rest of right
			else if(j>hi)          num[k] = aux[i++]; //right side is done, add the rest of left
			else if(aux[j]<aux[i]) num[k] = aux[j++]; //right element < left element; insert right element
			else                   num[k] = aux[i++]; //left element < right element; insert left element
		}
	
	}
	
	public static void main(String[] args){
		int[] num = {6, 1, 13, 15, 8, 4, 10};
		sort(num);
	}
}
