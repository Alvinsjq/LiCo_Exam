public class pro28 {

    public int strStr(String haystack, String needle) {

        //solution 1:

//        int flag = -1;
//        int i,j;
//        for(i=0,j=0;i<haystack.length()&&j<needle.length();){
//            if(haystack.charAt(i)!=needle.charAt(j)) {
//                i = i-j+1;
//                flag = -1;
//                j=0;
//            }else{
//                i++;
//                j++;
//                flag = i-j;
//            }
//        }
//
//        if(needle.length()>haystack.length()||j<needle.length())
//            return -1;
//        if(!haystack.equals("")&&needle.equals("")||needle.equals("")&&haystack.equals(""))
//            return 0;
//        return flag;



        //solution 2:

        for(int i=0;;i++){
            for(int j=0;;j++){
                if(j==needle.length()) return i;//竟然都匹配到了
                if(i+j == haystack.length()) return -1;
                if(haystack.charAt(i+j)!=needle.charAt(j)) break; //如果说比对到第j个发现不对了，那立马从下一个i开始吧！
            }
        }





    }


    public static void main(String[] args){

        System.out.print(new pro28().strStr("hello","el"  ));

    }
}
