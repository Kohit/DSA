import javax.swing.JFrame;

public class MouseTrackerTest {
	public static void main( String[] args ){
		MouseTrackerFrame mouse = new MouseTrackerFrame();
		mouse.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		mouse.setSize(480, 272);
		mouse.setVisible(true);
	}
}
