int yellow = 13 ;
int green = 12 ;
int red = 11 ;

void setup (){

  pinMode(yellow , OUTPUT ) ;
  pinMode (green , OUTPUT );
  pinMode ( red , OUTPUT ) ;
}

void loop ()
{ 
  digitalWrite (yellow , HIGH ) ;
  digitalWrite (green , LOW ) ;
  digitalWrite ( red , LOW ) ;
   delay (2000) ;
   
   digitalWrite (yellow , LOW ) ;
   digitalWrite (green , HIGH ) ;
   digitalWrite (red , LOW ) ;
   delay (2000) ;

   digitalWrite (yellow , LOW ) ;
   digitalWrite (green , LOW ) ;
   digitalWrite (red , HIGH ) ;
   delay(2000) ;
   }


