#include <simplecpp>
main_program{
  cout<< "Choose level of difficulty: easy medium hard .Type your choice(case sensitive)"<<endl;
  string ans;
  cin>>ans;
  int dx,dy0,rg;
  if(ans=="easy"){
  dx=2;dy0=1;rg=4;
}
if(ans=="medium"){
  dx=4;dy0=2;rg=7;
}
if(ans=="hard"){
  dx=8;dy0=4;rg=10;
}
  initCanvas("Pong",800,800);
  Text t3(400,75,"Press 'UpArrow' for Up and 'DownArrow' for Down");
  Text t8(400,25,"Press 'Space' to stop your paddle");
 // Text t4(400,750,"Player 2: Press 'UpArrow' for Up and 'DownArrow' for Down");
  Text t5(280,150,"Score:");
  Text t6(450,150,"Score:");
  Rectangle r(400,400,600,600);
  Line l1(400,700,400,100);
  Rectangle r1(110,400,20,50);
  r1.setColor(COLOR("black"));
  r1.setFill();
  Rectangle r2(690,130,20,50);
  r2.setColor(COLOR("black"));
  r2.setFill();
  Circle c1(400,400,10);
  c1.setColor(COLOR("black"));
  c1.setFill();
  string score_A="0",score_B="0";
  int x=400,y=400;
  int r1x=110;
  int scoreA=0,scoreB=0;
//  int dx=6,dy0=3,rg=10;
  int dy=dy0;
  XEvent event;
  Text t1(350,150,score_A);
  Text t2(520,150,score_B);
  
  while (scoreA<7 && scoreB<7){
     // string score_A = to_string(scoreA);
     // Text t1(350,150,score_A);
     // string score_B = to_string(scoreB);
      //  Text t2(450,150,score_B);
        c1.moveTo(x,y);
  	r1.moveTo(r1x,y);
      x=x+dx;y=y+dy;
      if((x>=690&&y>=690)||(x>=690&&y<=110)||(x<=110&&y>=690)||(x<=110&&y<=110)){
       dx=-dx;
       dy=-dy;
       c1.move(dx,dy);
	r1.move(0,dy);
       x=x+2*dx;y=y+2*dy;
}
      if (x>=680 || x<=120) {
	if(x>=680 && ((r2.getY()-y)<30 && (r2.getY()-y)>-30)){
	         dx=-dx;
                 c1.move(dx,dy);
		r1.move(0,dy);
                 x=x+2*dx;
		 

	}
	else if(x>=690){
	  dx=-dx;
          c1.move(dx,dy);
	  r1.move(0,dy);
          x=x+2*dx;
	  scoreA += 1;
          string score_A = to_string(scoreA);
	  t1.reset(350,150,score_A);
	}
	if(x<=120 && ((r1.getY()-y)<30 && (r1.getY()-y)>-30)){
      
         
	 dx=-dx;
       c1.move(dx,dy);
	r1.move(0,dy);
       x=x+2*dx;
       
	 
       }
	else if(x<=110){
	  scoreB += 1;
	 dx=-dx;
       c1.move(dx,dy);
	r1.move(0,dy);
       x=x+2*dx;
       string score_B = to_string(scoreB);
	t2.reset(520,150,score_B);
	}

       
}
      
      else if (y>=695){
        dy=-dy0;
        c1.move(dx,dy);
	r1.move(0,dy);
       y=y+2*dy;
}    
      else if (y<=105){
       dy=dy0;
       c1.move(dx,dy);
	r1.move(0,dy);
       y=y+2*dy;
      }
      checkEvent(event);
      if (keyPressEvent(event)) {
	
            if (charFromEvent(event) == 'R') {
	      if(r2.getY()>125){
	      r2.move(0,-rg);
	      }
	      else if(r2.getY()<=125){
		r2.move(0,0);
}           
 }
            
            if (charFromEvent(event) == 'T') {
	     if(r2.getY()<675){
	      r2.move(0,rg);
	      }
	      else if(r2.getY()>=675){
		r2.move(0,0);
}
            }
	   // if (charFromEvent(event) == 'w') {
	     // if(r1.getY()>125){
	     // r1.move(0,-rg);
	     // }
	//      else if(r1.getY()<=125){
	//	r1.move(0,0);
//}
  //          }
//	    if (charFromEvent(event) == 's') {
//	      if(r1.getY()<675){
//	      r1.move(0,rg);
//	      }
//	      else if(r1.getY()>=675){
//		r1.move(0,0);
//}
  //          }
           
        }
//      if(r1.getY()>=685){
//	r1.move(0,-15);
//	}
  //    if(r1.getY()<=115){
//	r1.move(0,15);
	
//	}
  //    if(r2.getY()<=115){
//	r2.move(0,15);
//	}
  //    if(r2.getY()>=685){
//	r2.move(0,-15);
//	}
      
     
	  
  }
  
  if(scoreA==7){
    Text t3(250,250,"Player 1 won");
    t3.imprint();
  }
  else {
    Text t3(550,550,"Player 2 won");
    t3.imprint();
  }
  wait(2);
}
