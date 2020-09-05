package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class PlayerMethon extends Application {
	Stage stage = new Stage();

	@Override
	public void start(Stage primaryStage)  {
		try {
			Text t1 = new Text(130.0,50.0,"关于游戏");
			t1.setFont(Font.font("Verdana",FontWeight.BOLD,30));
			t1.setFill(Color.BLACK);
			
			Text t2 = new Text(10.0,100.0,"游戏玩法\r\n" + 
					"用鼠标点击想要移动的块，点击上半部分则向上移，点击下半部分则向下移，向左向右移动以此类推。通过移动各个块，帮助曹操从初始位置移到棋盘最下方中部，从出口逃走，移动过程中不允许跨越块。\r\n" + 
					"\n\n");
			t2.setWrappingWidth(380.0);
			t2.setFont(Font.font("Verdana",20));
			t2.setFill(Color.BLACK);
			
			Text t3 = new Text(10.0,260.0,"游戏历史\r\n" + 
					"华容道游戏取自著名的三国故事，曹操在赤壁大战中被刘备和孙权的“苦肉计”、“铁索连舟”打败，被迫退逃到华容道，又遇上诸葛亮的伏兵，关羽为了报答曹操对他的恩情，明逼实让，终于帮助曹操逃出了华容道。游戏就是依照“曹瞒兵败走华容，正与关公狭路逢。只为当初恩义重，放开金锁走蛟龙”这一故事情节。\r\n" );
			t3.setFont(Font.font("Verdana",20));
			t3.setWrappingWidth(380.0);
			t3.setFill(Color.BLACK);
			
			Pane pane = new Pane();
			pane.setPrefSize(400, 500);
			pane.getChildren().addAll(t1,t2,t3);
			
			primaryStage.setTitle("About");
			primaryStage.setResizable(false);
	        primaryStage.setScene(new Scene(pane, 400, 500));
	        primaryStage.show();
			
		}catch(Exception e) {
			e.printStackTrace();
		}
		// TODO Auto-generated method stub
	}
	
	public void  showWindow() throws Exception {
		start(stage);
	}

}
