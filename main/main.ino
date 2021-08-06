
int re = 8,  ue =10, le = 12;
int rt = 7,  ut = 9, lt = 11;
long t,disr,disl,disu,dis,extra1,extra2;
int frm1 = 30, frm2 = 31, frme = 3, flm1 = 26, flm2 = 27, flme = 2, brm1 = 34, brm2 = 35, brme = 4, blm1 = 38, blm2 = 39,blme = 5;
// f-> front r->right l->left b->back e->enable
//boolean b1 = (disr<10 && disu<7), b2 = (disl<10 && disu<7);
long mod;

void setup() {
Serial.begin(9600);
// put your setup code here, to run once:
Serial.println("hello");
pinMode(re,INPUT);
pinMode(le,INPUT);
pinMode(ue,INPUT);
pinMode(rt,OUTPUT);
pinMode(lt,OUTPUT);
pinMode(ut,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

disr = distance(rt,re);
Serial.print("distance right = ");
Serial.println(disr);
disu = distance(ut,ue);
Serial.print("distance front = ");
Serial.println(disu);
disl = distance(lt,le);
Serial.print("distance left = ");
Serial.println(disl);

mod = abs(disr - disl);
Serial.print("modulus = ");
Serial.println(mod);

//moving();
Serial.println(" ");


delay(5000);

}

long distance(int a,int b)
{
  digitalWrite(a,LOW);
  delayMicroseconds(10);
  digitalWrite(a,HIGH);
  delayMicroseconds(10);
  digitalWrite(a,LOW);
  
  t = pulseIn(b,HIGH);
  dis = (350*t/20000);
  //Serial.print(dis);
  //Serial.print("  ");
  return dis;
}

void moving()
{
  if ((disr<10 && disl<10 && disu<10)|| (disr>1000 && disl>1000 && disu>5000))
  {
    //finish();
    Serial.println("finished");
  } 
  else
  {
    if(mod<5 && (disu>10 && disu<5000))
    {
      //forward();
      Serial.println("goingforward");  
    } 
    else
    {
      if(((disr - disl)>=5 && (disu>10 && disu<5000) && disr<2000) || (disl>2000 && disu<5000))  
      {
        //right();
        Serial.println("goingright");  
      }
      else
      {
        if(((disl - disr)>=5 && (disu>10 && disu<5000) && disl<2000) || (disr>2000 && disu<5000))
        {
          //left();
          Serial.println("goingleft");  
        }
        else
        {
          if((disr<12 && disu<12) || (disr>2000 && disu>5000))
          {
            extra1 =disu;
            do
            { //rotleft();
              disr=distance(rt,re);
              Serial.println("rotating left");
            } while(disr>(extra1 - 3) && disr<(extra1 + 3)); 
          }
          else
          {
            if((disl<12 && disu<12) || (disl>2000 && disu>5000))
            {
              extra2=disu;
            do
            { //rotright(); 
              disl=distance(lt,le);
              Serial.println("rotating right");
            } while(disl>(extra2 - 3) && disl<(extra2 + 3)); 
          
            }  
          }          
        }
      }
    }
  }
}

void finish()
{
    Serial.println("not moving");
    digitalWrite(frm1,LOW);  digitalWrite(frm2,LOW);  
    digitalWrite(flm1,LOW);  digitalWrite(flm2,LOW);
    digitalWrite(brm1,LOW);  digitalWrite(brm2,LOW);
    digitalWrite(blm1,LOW);  digitalWrite(blm2,LOW);
}

void right()
{
    Serial.println("moving right");
    digitalWrite(frm1,LOW);   digitalWrite(frm2,HIGH);  analogWrite(frme,183);
    digitalWrite(flm1,HIGH);  digitalWrite(flm2,LOW);   analogWrite(flme,183);
    digitalWrite(brm1,HIGH);  digitalWrite(brm2,LOW);   analogWrite(brme,183);
    digitalWrite(blm1,LOW);   digitalWrite(blm2,HIGH);  analogWrite(blme,183);
}

void left()
{
    Serial.println("moving left");
    digitalWrite(frm1,HIGH);  digitalWrite(frm2,LOW);  analogWrite(frme,183);
    digitalWrite(flm1,LOW);  digitalWrite(flm2,HIGH);  analogWrite(flme,183);
    digitalWrite(brm1,LOW);  digitalWrite(brm2,HIGH);  analogWrite(brme,183);
    digitalWrite(blm1,HIGH);  digitalWrite(blm2,LOW);  analogWrite(blme,183);
}

void forward()
{
    Serial.println("moving forward");
    digitalWrite(frm1,HIGH);  digitalWrite(frm2,LOW);  analogWrite(frme,183);
    digitalWrite(flm1,HIGH);  digitalWrite(flm2,LOW);  analogWrite(flme,183);
    digitalWrite(brm1,HIGH);  digitalWrite(brm2,LOW);  analogWrite(brme,183);
    digitalWrite(blm1,HIGH);  digitalWrite(blm2,LOW);  analogWrite(blme,183);
}

void rotright()
{
    Serial.println("rotating right");
    digitalWrite(frm1,HIGH);  digitalWrite(frm2,LOW);  analogWrite(frme,183);
    digitalWrite(flm1,LOW);  digitalWrite(flm2,HIGH);  analogWrite(flme,183);
    digitalWrite(brm1,HIGH);  digitalWrite(brm2,LOW);  analogWrite(brme,183);
    digitalWrite(blm1,LOW);  digitalWrite(blm2,HIGH);  analogWrite(blme,183);
}

void rotleft()
{
    Serial.println("rotating left");
    digitalWrite(frm1,LOW);  digitalWrite(frm2,HIGH);  analogWrite(frme,183);
    digitalWrite(flm1,HIGH);  digitalWrite(flm2,LOW);  analogWrite(flme,183);
    digitalWrite(brm1,LOW);  digitalWrite(brm2,HIGH);  analogWrite(brme,183);
    digitalWrite(blm1,HIGH);  digitalWrite(blm2,LOW);  analogWrite(blme,183);
}
