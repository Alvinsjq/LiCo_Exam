public class pro1 {
    public static  int[] twoSum(int[] nums, int target) {
        int[] a = new int[2];
        int len =  nums.length;
        for (int i =0;i<len;i++)
            for (int j = i+1;j<len;j++){
                if((nums[i]+nums[j])==target){
                    a[0] = i;
                    a[1] = j;
                }
            }
        return a;
    }


    public static void main(String[] args){
        int a[] = {3,2,4};
        int target = 6;
        int b[] = twoSum(a,6);

        System.out.println(b[0]+","+b[1]);
    }
}
