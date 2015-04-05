import javax.swing.JFrame;

public class ChatClientTest {
	public static void main( String[] args ){
		ChatClient easyChat = new ChatClient( args[0], args[1] );
		easyChat.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		easyChat.runClient();
	}
}
