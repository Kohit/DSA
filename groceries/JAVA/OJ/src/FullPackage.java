// Full package
import java.util.Scanner;

public class FullPackage {
	public static void main( String[] args ){
		Scanner input = new Scanner( System.in );
		int N, V;
		V = input.nextInt(); N = input.nextInt();
		int[] value, weight;
		value = new int[1002];
		weight = new int[1002];
		for ( int i = 1; i <= N; i++ ){
			value[i] = input.nextInt();
			weight[i] = input.nextInt();
		}
		int[] total = new int[102];
		for( int i = 1; i <= N; i++ )
			for ( int j = 0; j <= V; j++ )
				if ( j - weight[i] >= 0 )
				total[j] = max( total[j], total[j - weight[i]] + value[i] );
		System.out.print( total[V] );
	}
	public static int max( int a, int b ){
		return a > b ? a : b;
	}
}
