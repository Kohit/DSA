import javax.swing.JFrame;

import java.awt.Color;
import java.util.Scanner;
public class ChatServerTest {
	public static void main( String[] args ){
		Scanner input = new Scanner( System.in );
		String name = input.nextLine();
		ChatServer easyChat = new ChatServer( name );
		easyChat.setBackground(Color.PINK);
		easyChat.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		easyChat.runServer();
		input.close();
	}
}
