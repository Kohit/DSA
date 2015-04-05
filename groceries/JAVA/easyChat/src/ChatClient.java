import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class ChatClient extends JFrame {
	private JTextField enterField;
	private JTextArea displayArea;
	private ObjectOutputStream output;
	private ObjectInputStream input;
	private Socket client;
	private String message = "";
	private String chatServer;
	private String nickname;
	private String user;
	
	public ChatClient( String host, String name ){
		super( "easyChat Client" );
		chatServer = host;
		nickname = name;
		enterField = new JTextField( "enter message here" );
		enterField.setEditable( false );
		enterField.addActionListener( 
			new ActionListener(){
				public void actionPerformed( ActionEvent event ){
					sendData( event.getActionCommand() );
					enterField.setText( "" );
				}
			}
		);
		add( enterField, BorderLayout.SOUTH );
		displayArea = new JTextArea();
		displayArea.setBackground( Color.PINK );
		add( new JScrollPane( displayArea ) );
		setSize( 800, 480 );
		setVisible( true );
	}
	
	public void runClient(){
		try{
			connectToServer();
			getStreams();
			processConnection();
		}catch ( EOFException e ){
			displayMessage( "\nClient terminated connection\n" );
		}catch ( IOException e ){
			e.printStackTrace();
		}finally{
			closeConnection();
		}
	}
	private void connectToServer() throws IOException{
		displayMessage( "Attempting connection\n" );
		client = new Socket( InetAddress.getByName( chatServer ), 12345 );
		displayMessage( "Connected to: " + client.getInetAddress().getHostName() );
	}
	private void getStreams() throws IOException{
		output = new ObjectOutputStream( client.getOutputStream() );
		output.flush();
		input = new ObjectInputStream( client.getInputStream() );
		displayMessage( "\nGot I/O streams\n\n\n" );
		output.writeObject( nickname );
		output.flush();
		try{
			user = ( String ) input.readObject();
		}catch ( ClassNotFoundException e ){
			displayMessage( "get user name failed\n" );
		}
	}
	private void processConnection() throws IOException{
		setTextFieldEditable( true );
		do{
			try{
				message = ( String ) input.readObject();
				displayMessage( user + " : \n" + message + "\n\n" );
			}catch ( ClassNotFoundException e ){
				displayMessage( "Unknown object type received\n" );
			}
		} while ( !message.equals( "logout" ) );
	}
	private void closeConnection(){
		displayMessage( "\n closing connection\n" );
		setTextFieldEditable( false );
		try{
			output.close();
			input.close();
			client.close();
		}catch ( IOException e ){
			e.printStackTrace();
		}
	}
	private void sendData( String messages ){
		try{
			output.writeObject( messages );
			output.flush();
			displayMessage( nickname + " : \n" + messages + "\n\n" );
		}catch ( IOException e ){
			displayArea.append( "\n Error writing object\n" );
		}
	}
	private void displayMessage( final String messages ){
		SwingUtilities.invokeLater( 
			new Runnable(){
				public void run(){
					displayArea.append( messages );
				}
			}
		);
	}
	private void setTextFieldEditable( final boolean editable ){
		SwingUtilities.invokeLater(  
			new Runnable(){
				public void run(){
					enterField.setEditable( editable );
				}
			}
		);
	}
}
