import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework
// don't change the name of this class
// you can add inner classes if needed
class Main {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int n= input.nextInt();
        int k = input.nextInt();
        String s = input.next();
        int arr[] = new int[n];
        for(int i= 0;i<n;i++){
            if(vowelCheck(s.charAt(i))) arr[i] = 1;
            else arr[i] = 0;
        }
        System.out.println(maxSize(arr, n, k));
    }
    public static int maxSize(int arr[], int n, int k){
        int count = 0;
        int l = 0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) count++;
            while(count > k){
                if(arr[l] == 0) count--;
                l++;
            }
            maxLen = Math.max(maxLen, i-l+1);
        }
        return maxLen;
    }
    public static boolean vowelCheck(char temp){
        switch(temp){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
}