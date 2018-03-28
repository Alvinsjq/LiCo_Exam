import java.util.ArrayList;

public class pro151 {

    public String reverseWords(String s) {
        StringBuffer result = new StringBuffer();
        ArrayList<String> sl = new ArrayList<>();
        int i = 0;
        String mid="";
        int len = s.length();
        while(i<len){
            while(s.charAt(i)!=' ') {
                mid+=String.valueOf(s.charAt(i));
                if(i<len-1)
                    i++;
                else
                    break;
            }
            if(!mid.equals(""))
                 sl.add(mid);
            mid = "";
            if(i<len-1)
                i++;
            else
                break;
        }


        for(int _i=sl.size()-1;_i>=0;_i--){
            if(_i!=0){
                result.append(sl.get(_i)+" ");
            }else
                result.append(sl.get(_i));
        }


        // solution 2 : unfinished
//        boolean setright = true;
//        int left = s.length()-1, right = s.length()-1;
//        String subs;
//
//        for(int i=s.length()-1;i>=0;i--){
//            if(s.charAt(i)!= ' ') {
//                if (setright) {
//                    right = i;
//
//                    if(i==0 && s.charAt(i)!=' '){
//                        left = 0;
//                        subs = s.substring(left,right+1);
//                        if(!subs.equals(" ")&&!subs.equals("")) {
//                            result.append(subs);
//                            right = i;
//                        }
//                    }
//
//                    setright = false;
//                }
//                    continue;
//            }
//            else{
//                    left = i + 1;
//                    subs = s.substring(left,right+1);
//                    if(!subs.equals(" ")&&!subs.equals("")){
//                        result.append(subs+" ");
//                        right = i;
//                    }
//
//                setright = true;
//            }
//        }

        return result.toString();
    }

    public static void main(String[] args){
        ArrayList<String> sl = new ArrayList<>();
        String s =" 0 234 7";
        System.out.println(new pro151().reverseWords(s));



    }
}
