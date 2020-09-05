package application;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Choose extends Application {
	Stage stage = new Stage();
	@Override
	public void start(Stage primaryStage)  {
		try {
			Button btn[] = new Button[3];
			btn[0] = new Button("one");
			btn[1] = new Button("two");
			btn[2] = new Button("three");
			btn[0].setOnAction(e -> {Secand.getchoose(1);changeWindowtosecond();primaryStage.close();});
			btn[1].setOnAction(e -> {Secand.getchoose(2);changeWindowtosecond();primaryStage.close();});
			btn[2].setOnAction(e -> {Secand.getchoose(3);changeWindowtosecond();primaryStage.close();});
			for(int i=0;i<3;i++)btn[i].setPrefWidth(50.0);
			
			Text t1 = new Text("请选择模式");
			t1.setFont(Font.font("Verdana",20));
			t1.setFill(Color.BLACK);
			
			VBox hbox = new VBox();
			hbox.getChildren().add(t1);
	        hbox.getChildren().addAll(btn);
	        hbox.setAlignment(Pos.CENTER);
	        
	        primaryStage.setTitle("华容道");
	        primaryStage.setResizable(false);
	        primaryStage.setScene(new Scene(hbox, 300, 250));
	        primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}// TODO Auto-generated method stub
	}
	public void  showWindow() throws Exception {
		start(stage);
	}
	public void changeWindowtosecond() {
		try {
			Secand second=new Secand();
			second.showWindow();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}

}
