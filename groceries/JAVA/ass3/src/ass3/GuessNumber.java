/*
 * Ass3 - GuessNumber.java
 *
 *  Created on: 2015年3月19日
 *      Author: FongYoung Vane
 */

package ass3;
import java.util.Scanner;

public class GuessNumber {
	public static void main( String args[] ){
		Scanner in = new Scanner( System.in );
		System.out.println( "给你一个0 ~ 100之间的整数，请猜测这个数" );
		int realNumber = ( int )Math.round( Math.random() * 100 );
		System.out.print( "请输入你的猜测:" );
		int yourGuess = in.nextInt();
		boolean isRight = false;
		while( !isRight ){
			if ( yourGuess > realNumber ){
				System.out.print( "猜大了，再输入你的猜测:" );
				yourGuess = in.nextInt();
			}
			else if ( yourGuess < realNumber ){
				System.out.print( "猜小了，再输入你的猜测:" );
				yourGuess = in.nextInt();
			}
			else{
				isRight = true;
				System.out.print( "恭喜你，猜对了" );
			}
		}
		in.close();
	}
}
