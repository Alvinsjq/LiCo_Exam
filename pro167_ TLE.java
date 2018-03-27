public class pro167 {
    public static  int[] twoSum(int[] nums, int target) {

        for(int i=0;i<nums.length;i++){
            int x=nums[i];
            int j = bisearch(nums,target-x,i+1);
            if(j!=-1)
                return new int[]{i+1,j+1};
        }

        return new int[]{0,0};
    }

    private static int bisearch(int[] A, int key, int start){
        int left = start, right = A.length-1;
        while(left<right){
            int mid = (left+right)/2;
            if(key<A[mid])
                right = mid+1;
            else if(key>A[mid])
                left = mid;
            else
                return mid;
        }
        return -1;
    }

    public static void main(String[] args){
        int a[] = {2,3,4};
        int target = 5;
        int b[] = twoSum(a,target);
        System.out.println(b[0]+","+b[1]);

    }
}
