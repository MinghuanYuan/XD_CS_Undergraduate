package application;
	
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.text.*;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;


public class Main extends Application {
	Stage stage = new Stage();
	@Override
	public void start(Stage primaryStage) {
		try {
			Button btn[] = new Button[4];
			btn[0] = new Button("New Game");
			btn[1] = new Button("Continue");
			btn[2] = new Button("About");
			btn[3] = new Button("Exit");
			btn[0].setOnAction(e -> {changeWindowtosecond();primaryStage.close();});
			btn[1].setOnAction(e -> {changeWindowtothird();primaryStage.close();});
			btn[2].setOnAction(e -> {changeWindowtoabout();});
			btn[3].setOnAction(e -> primaryStage.close());
			for(int i=0;i<4;i++)btn[i].setPrefWidth(100.0);
			
			Text t1 = new Text("华容道");
			t1.setFont(Font.font("Verdana",20));
			t1.setFill(Color.BLACK);
			
			Text t2 = new Text("版权所有，翻版必究");
			t1.setFont(Font.font("Verdana",20));
			t1.setFill(Color.BLACK);
			
			VBox hbox = new VBox();
			hbox.getChildren().add(t1);
	        hbox.getChildren().addAll(btn);
	        hbox.getChildren().add(t2);
	        hbox.setAlignment(Pos.CENTER);
	        primaryStage.setTitle("华容道");
	        primaryStage.setResizable(false);
	        primaryStage.setScene(new Scene(hbox, 300, 250));
	        primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
	
	private void changeWindowtosecond() {
		try {
			Choose choose = new Choose();
			choose.showWindow();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}

	private void changeWindowtothird() {
		try {
			Third third=new Third();
			third.showWindow();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private void changeWindowtoabout() {
		try {
			PlayerMethon about=new PlayerMethon();
			about.showWindow();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void  showWindow() throws Exception {
		start(stage);
	}
}
