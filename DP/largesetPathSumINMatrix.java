import java.io.*; // for handling input/output
import java.util.*; // contains Collections framework

// don't change the name of this class
// you can add inner classes if needed
class Main {
	public static int cal(int n,int matrix[][]){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0){matrix[i][j]=matrix[i][j];
			}
			else if(j==0&& i!=0){
				matrix[i][j]=matrix[i][j]+Math.max(matrix[i-1][j],matrix[i-1][j+1]);
			}
			else if(j==(n-1)&& i!=0){
				matrix[i][j]=matrix[i][j]+Math.max(matrix[i-1][j],matrix[i-1][j-1]);
			}
			else{
				int x=Math.max(matrix[i-1][j],matrix[i-1][j-1]);
				matrix[i][j]=matrix[i][j]+Math.max(x,matrix[i-1][j+1]);
			}

			
		}
	}

	int res=matrix[n-1][0];
	for(int i=1;i<n;i++){
res=Math.max(res,matrix[n-1][i]);
	}
	return res;
	}

	public static void main (String[] args) {
                      // Your code here
		Scanner inputtaker =new Scanner(System.in);
		int n=inputtaker.nextInt();
		int matrix[][]=new int[n][n];

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)matrix[i][j]=inputtaker.nextInt();
		}


		System.out.print(cal(n,matrix));

				
	}

}