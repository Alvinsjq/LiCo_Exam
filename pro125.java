public class pro125 {

    public boolean isPalindrome(String s) {
        char a[] = s.toCharArray();
        int i = 0, j = a.length - 1;

        while (i <= j) {
            boolean left = ('a' <= a[i] && a[i] <= 'z' || 'A' <= a[i] && a[i] <= 'Z' || '0'<=a[i]&&a[i]<='9');
            boolean right = ('a' <= a[j] && a[j] <= 'z' || 'A' <= a[j] && a[j] <= 'Z'|| '0'<=a[j]&&a[j]<='9');
            if(!left && right){
                i++;
                continue;
            }
            if(!left && !right){
                i++;
                j--;
                continue;
            }
            if(left && !right){
                j--;
                continue;
            }
            if(left && right){
                a[i] = Character.toLowerCase(a[i]);
                a[j] = Character.toLowerCase(a[j]);
                if(a[i]==a[j]){
                    i++;
                    j--;
                }else
                    return false;
            }
        }
        return true;
    }

    public static void main(String[] args){
        String s = "A man, a plan, a canal: Panama";
        String ss = "race a car";
        String p = "0P";
        System.out.print(new pro125().isPalindrome(p));


    }

}
