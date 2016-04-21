import java.lang.Math;

public class Binary {
	
	public static void sort(int[] nums){
		if(!isSorted(nums)) Merge.sort(nums);
	}
		
	public static int search(int[] nums, int num){
		return search(nums, num, 0, nums.length-1);
	}

	
	private static int search(int[] nums, int num, int i, int j){
		if(j<i) return -1;
		int mid = (int)Math.floor((i+j)/2);
		if(num == nums[mid]) return mid;
		else if(num < nums[mid]) return search(nums, num, i, mid-1);
		else return search(nums, num, mid+1, j);
	}
	
	private static boolean isSorted(int[] nums){
		for(int i = 0; i<nums.length-1; i++)
			if(nums[i+1]<nums[i]) return false;
		return true;
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		int[] nums = {1, 3, 14, 24, 25, 30};
		System.out.println(search(nums, 31));
	}
	
}