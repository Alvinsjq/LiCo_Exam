public class pro167 {
    public static  int[] twoSum(int[] nums, int target) {

      int i = 0;
      int j = nums.length-1;
      while(i<j){
          if(nums[i]+nums[j]>target){
                j--;
          }else
              if(nums[i]+nums[j]<target){
                i++;
              }else
                  return new int[]{i+1,j+1};

      }

      return new int[]{0,0};
    }



    public static void main(String[] args){
        int a[] = {2,3,4};
        int target = 5;
        int b[] = twoSum(a,target);
        System.out.println(b[0]+","+b[1]);

    }
}
