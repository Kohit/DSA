import java.util.*;
import java.util.Queue;
import java.util.AbstractQueue;
import java.util.concurrent.ArrayBlockingQueue;
public class Main {
	private int x, y, step;
	public Main( int xx, int yy, int ss ){
		x = xx; y = yy; step = ss;
	}
	public Main(){
		x = 0; y = 0; step = 0;
	};
	public static int BFS( int sx, int sy, int ex, int ey, char[][] maze, int M, int N ){
		int[][] dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
		ArrayBlockingQueue<Main> Q = new ArrayBlockingQueue<Main>(100);
		Q.add( new Main( sx, sy, 0 ) );
		Main head = new Main();
		while( !Q.isEmpty() ){
			head = Q.element();
			if ( maze[head.x][head.y] == '#' )
				Q.poll();
			else{
				maze[head.x][head.y] = '#';
				for ( int i = 0; i < 4; i++ ){
					int x = head.x + dir[i][0];
					int y = head.y + dir[i][1];
					if ( x >= 0 && x <= M - 1 && y >= 0 && y <= N - 1 && maze[x][y] != '#' ){
						Q.add( new Main( x, y, head.step + 1 ));
					}
					if ( x == ex && y == ey )
						return head.step + 1;
				}
			}
		}
		return -1;
	}
	public static void main( String[] args ){
		Scanner input = new Scanner( System.in );
		int M, N, sx, sy, ex, ey;
		char[][] maze = new char[52][52];
			M = input.nextInt(); N = input.nextInt();
			sx = input.nextInt(); sy = input.nextInt();
			ex = input.nextInt(); ey = input.nextInt();
			for ( int i = 0; i < M; i++ )
				maze[i] = input.next().toCharArray();
			if ( sx == ex && sy == ey )
				System.out.println( "0" );
			else{
				int count = BFS( sx, sy, ex, ey, maze, M, N );
				System.out.println( count );
			}
	}
}
