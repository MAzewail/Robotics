#define DW(x,y) digitalWrite(x,y)
#define s Serial
#define f(x) if(x){
#define end }

typedef char ch;
typedef uint32_t uint32;

uint32 x=0;
void setup()
{
  s.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  f(s.available())
    ch c=s.read();
  
  f(c=='a')
  DW(13,1);
  delay(1000); 
  digitalWrite(13, LOW);
  delay(1000); 
end  
end
end
