import java.util.Scanner;
public class QuickUnion {
	private int[] id;
	private int[] size;
	private int count;  // number of connected component
	QuickUnion( int N ){
		id = new int[N + 1];
		size = new int[N + 1];
		count = N;
		for ( int i = 0; i < N; i++ ){
			id[i] = i;
			size[i] = 1;
		}
	}
	public int count() { return count; }
	public int find( int p ){
		while( p != id[p] ){
			id[p] = id[id[p]];
			p = id[p];
		}
		return p;
	}
	public boolean connect( int p, int q ){
		return find(p) == find(q);
	}
	public void union( int p, int q ){
		int i = find(p);
		int j = find(q);
		if ( i == j ) return;
		if ( size[i] < size[j] ){ id[i] = j; size[j] += size[i];}
		else{ id[j] = i; size[i] += size[j]; }
		count--;
	}
	public static void main( String[] args ){
		Scanner scan = new Scanner( System.in );
		int N = scan.nextInt();
		QuickUnion QU = new QuickUnion( N );
		int rela = scan.nextInt();
		int p, q;
		for ( int i = 0; i < rela; i++ ){
			p = scan.nextInt();
			q = scan.nextInt();
			QU.union(p, q);
		}
		int query = scan.nextInt();
		for ( int i = 0; i < query; i++ ){
			p = scan.nextInt();
			q = scan.nextInt();
			if ( QU.connect(p, q) ) System.out.println( "y" );
			else System.out.println( "n" );
		}
		scan.close();
	}
}
