/*
 * Ass3 - GuessNumber.java
 *
 *  Created on: 2015��3��19��
 *      Author: FongYoung Vane
 */

package ass3;
import java.util.Scanner;

public class GuessNumber {
	public static void main( String args[] ){
		Scanner in = new Scanner( System.in );
		System.out.println( "����һ��0 ~ 100֮�����������²������" );
		int realNumber = ( int )Math.round( Math.random() * 100 );
		System.out.print( "��������Ĳ²�:" );
		int yourGuess = in.nextInt();
		boolean isRight = false;
		while( !isRight ){
			if ( yourGuess > realNumber ){
				System.out.print( "�´��ˣ���������Ĳ²�:" );
				yourGuess = in.nextInt();
			}
			else if ( yourGuess < realNumber ){
				System.out.print( "��С�ˣ���������Ĳ²�:" );
				yourGuess = in.nextInt();
			}
			else{
				isRight = true;
				System.out.print( "��ϲ�㣬�¶���" );
			}
		}
		in.close();
	}
}
