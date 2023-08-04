#include<reg52.h>
#include<string.h>

unsigned char bcd_dec(unsigned char bcd); 	 // Chuyen doi so BCD-thap phan

unsigned char dec_bcd(unsigned char dec); 	 // Chuyen doi so thap phan-BCD
char h11=10,h12=10,m11=10, m12=10, h21, h22, m21, m22, s21, s22, dd1,dd2, mm1,mm2, yy1, yy2, thu1, chuong1 = 'a', chuong2='a';
int i;
void Uart_Init();
void Uart_Write(char c);
char Uart_Read();
void note(int a);
unsigned int mode=0;
unsigned char gop2byte(char m, char n);
unsigned char bcd_dec(unsigned char bcd)
              {
			    return((bcd/16)*10+(bcd%16));
		}		

unsigned char dec_bcd(unsigned char dec) 
               {
			     return((dec/10)*16+(dec%10));
		}  
unsigned char gop2byte(char m, char n) {
	m=m-48;
	m=m<<4;
	n=n-48;
	return (m | n);
}				
void Uart_Init()
{
	// Khoi tao UART o mode 1, 9600 baud
	SM0 = 0; SM1 = 1;		// Chon UART mode 1
	TMOD = 0x20;            // 0010 xxxx - Timer1 hoat dong o che do 8bit tu dong nap lai
	TH1 = 0xFD;				// Toc do baud 9600
	TR1 = 1;				// Timer1 bat dau chay
	TI = 1;					// San sang gui du lieu
	REN = 1;				// Cho phep nhan du lieu
}

void Uart_Write(char c)
{
 	while(TI == 0);
	TI = 0;
	SBUF = c;
}


char Uart_Read()
{
	while(RI == 0);
	RI = 0;
	return SBUF;
}							 
void batchuong();


//bit tang0=1,tang1=1,giam0=1,giam1=1,mode0=1,mode1=1;
char giay,phut,gio,h1,h2,m1,m2,s1,s2,ngay,thang,nam,ng1,ng2,th1,th2,n1,n2,thu,day; // cac gia tri
// giay,phut,gio,thu,ngay,thang,nam duoc tach thanh 2 so de hien thi

// Dat lai ten cho cac chan dac biet duoc dung
sbit SCL=P1^0;	  
sbit SDA=P1^1;
sbit Rs=P2^0;
sbit Rw=P2^1;
sbit En=P2^2;
sbit tang=P3^5;
sbit giam=P3^4;
sbit menu=P3^2;
sbit Bf=  P0^7;
sbit buzz=P3^6;
sbit nut1=P2^5;
sbit nut2=P2^6;
sbit nut3=P2^7;



// Ham tre t(ms)
void delay(int t)
{
  int a,b;
  for(a=0;a<t;a++)
  {
    for(b=0;b<125;b++)
	{}
  }
}
void note(int nh) {
if (nut3==0) {h11=10; h12=10; m11=10; m12=10;}
if (nh==1)
{
i=65;
	while (i>0) {
TMOD=0X01;
TH0=0Xf8;
TL0=0X80;
TR0=1;
while(TF0==0);
buzz=~buzz;
TR0=0;
TF0=0;
i--;
		}
	buzz=0;
}

if (nh==2)
{
i=73;
while (i>0) {
TMOD=0X01;
TH0=0Xf9;
TL0=0X55;
TR0=1;
while(TF0==0);
buzz=~buzz;
TR0=0;
TF0=0;
	i--;
	}
buzz=0;
}

if (nh==3)
{
i=83;
while (i>0) {
TMOD=0X01;
TH0=0Xfa;
TL0=0X00;
TR0=1;
while(TF0==0);
	buzz=~buzz;
TR0=0;
TF0=0;
i--;
	}
buzz=0;
}

if (nh==4)
{
i=88;
while (i>0) {
TMOD=0X01;
TH0=0Xfa;
TL0=0X66;
TR0=1;
while(TF0==0);
	buzz=~buzz;
TR0=0;
TF0=0;
i--;
	}
buzz=0;
}

if (nh==5)
{
i=98;
while (i>0) {
TMOD=0X01;
TH0=0XFB;
TL0=0X00;
TR0=1;
while(TF0==0);
	buzz=~buzz;
TR0=0;
TF0=0;
i--;
	}
buzz=0;
}

if (nh==6)
{
i=110;
while (i>0) {
TMOD=0X01;
TH0=0XFB;
TL0=0X80;
TR0=1;
while(TF0==0);
buzz=~buzz;
TR0=0;
TF0=0;
i--;
	}
buzz=0;
}
if (nh==7)
{
i=124;
while (i>0) {
TMOD=0X01;
TH0=0XFC;
TL0=0X00;
TR0=1;
while(TF0==0);
	buzz=~buzz;
TR0=0;
TF0=0;
i--;
	}
buzz=0;
}
if (nh==8)
{
i=134;
while (i>0) {
TMOD=0X01;
TH0=0XFC;
TL0=0X40;
TR0=1;
while(TF0==0);
	buzz=~buzz;
TR0=0;
TF0=0;
i--;
	}
buzz=0;
}
}
//Ham bat chuong
void batchuong() {
	if (chuong1=='a') {
	note(1); note(7); note(8); note(6);note(2); note(1);note(5); note(6);note(6); note(1); note(7); note(5);note(2); 
		}
	if (chuong1=='b') {
	note(8); note(1); note(8);note(1); note(8);note(1); note(8);note(1); note(8); note(1); note(8);note(1); note(8);note(1); note(8);
		}
	if (chuong1=='c') {
	note(1); note(8);note(2);note(8); note(3); note(8);note(4);note(8);note(5); note(6);note(8);note(7); note(8); note(7); note(8);note(6); note(8);note(5);note(8);note(4); note(8);note(3);note(8);note(2); note(8);note(1);note(8);
		}
}
// Ham tre t(us)
void delay_us(int t)
{
  int a;
  for(a=0;a<t;a++)
  {}
}

// CAC CHUONG TRINH GIANH CHO LCD
// Ham kiem tra ban
void ban()
{
  P0 =0xFF;
  Rs=0;
  Rw=1;
  while(Bf)
  {
    En=0;
	delay_us(50);
	En=1;
  }
}
// Ham ghi lenh
void lenh(unsigned char x)
{
  ban();
  P0=x;
  Rs=0;
  Rw=0;
  delay_us(50);
  En=1;
  delay_us(50);
  En=0;
}
// Ham ghi du lieu
void kitu(unsigned char x)
{
  ban();
  P0=x;
  Rs=1;
  Rw=0;
  delay_us(50);
  En=1;
  delay_us(50);
  En=0;
}
// Ham ghi chuoi
void chuoi(unsigned char *s)
{
  char i;
  for(i=0;i<strlen(s);i++)
  {
    kitu(s[i]);
  }
}
// Ham ghi cham 1 chuoi
void chuoi_cham(unsigned char *s)
{
  char i;
  for(i=0;i<strlen(s);i++)
  {
    kitu(s[i]);
	delay(75);
  }
}
// Ham khoi tao LCD
void khoitao()
{
  lenh(0x38);
  lenh(0x01);
  lenh(0x0c);
  lenh(0x80);
}

// CAC CHUONG TRINH GIANH CHO DS1307
// Ham start I2C
void start()
{
  SCL=1;
  SDA=1;
  delay(1);
  SDA=0;
  delay(1);
  SCL=0;
  SDA=1;
}
// Ham stop I2C
void stop()
{
  
  SDA=0;SCL=1;
  delay(1);
  SDA=1;
  delay(1);
}
// Ham ghi 1 byte vao DS1307
void truyen(unsigned char g)
{
  unsigned char tem,i;
  for(i=0;i<8;i++)
  {
    tem=g&0x80;
	if(tem==0x80)
	SDA=1;
	else SDA=0;
	SCL=1;
	delay(1);
	SCL=0;
	g=g*2;
	
  }
  SCL=1;
  delay(1);
  SCL=0;
}
// Ham nhan 1 byte
unsigned char nhan()
{
 unsigned char gt=0,i;
 for(i=0;i<8;i++)
 {
   SCL=1;
   gt=gt*2;
   delay(1);
   gt=gt|SDA;
   SCL=0;
   delay(1);
 }
 SCL=1;
 SDA=1;
 delay(1);
 SCL=0;
 return gt;
}
//Ham ghi gia tri vao 1 dia chi 
void ghi(unsigned char add,unsigned char gt)
{
  start();
  truyen(0xd0);
  truyen(add);
  truyen(gt);
  stop();
}
// Ham doc gia tri tu 1 dia chi
unsigned char doc(unsigned char add)
{
  unsigned char value;
  start();
  truyen(0xd0);
  truyen(add);
  start();
  truyen(0xd1);
  value=nhan();
  stop();
  return value;
}
void docgio()
{
  giay =bcd_dec(doc(0x00));
  phut =bcd_dec(doc(0x01));
  gio  =bcd_dec(doc(0x02));
  thu=bcd_dec(doc(0x03));
  ngay =bcd_dec(doc(0x04));
  thang=bcd_dec(doc(0x05));
  nam  =bcd_dec(doc(0x06)); 
}
//Tach gia tri de hien thi
void tach()
{  
  s1=giay/10+48;s2=giay%10+48;
  m1=phut/10+48;m2=phut%10+48;
  h1=gio/10+48;h2=gio%10+48;
  day=thu+47;
  ng1=ngay/10+48;ng2=ngay%10+48;
  th1=thang/10+48;th2=thang%10+48;
  n1=nam/10+48;n2=nam%10+48;
}   


//Ham hien thi thoi gian
void hienthi()
{ 
  docgio();
  tach();
  lenh(0x80);
  if(thu!=7)
  {
    chuoi("Thu ");
	kitu(day+1);
	kitu(' ');
  }
  else chuoi("CNHAT ");
  kitu(ng1);kitu(ng2);
  kitu('/');
  kitu(th1);kitu(th2);
  kitu('/');
  chuoi("20");
  kitu(n1);kitu(n2);
  lenh(0xc0);
  chuoi("Time: ");
  kitu(h1);kitu(h2);
  kitu(':');
  kitu(m1);kitu(m2);
  kitu(':');
  kitu(s1);kitu(s2);
  chuoi("  ");
}


// HAM CHINH
void main()
{
	buzz=0;
  khoitao();
  lenh(0x80);
  chuoi_cham(" REAL TIME CLOCK ");
  
  lenh(0xc0);
  chuoi_cham("    GROUP 10  ");
  delay(2000);
  lenh(0x01);
  while(1)
  {
		if (nut2==0) mode=2;
		if (nut1==0) mode=1;
	if (mode==0) //che do hien gio
	{hienthi();
	if ((h1==h11)&&(h2==h12)&&(m1==m11)&&(m2==m12))
	 {
	 batchuong();
	 }
	}
	if (mode==1) // Che do dieu chinh gio
		{
		khoitao();
		chuoi("    SET GIO");
		delay(1000);
		lenh(0x01);
		chuoi("    HH:MM:SS");
		lenh(0xc0);
		chuoi("    ");
		Uart_Init();
		h21 = Uart_Read();
		Uart_Write(h21);
		kitu(h21);
		h22 = Uart_Read();
		Uart_Write(h22);
		kitu(h22);
		gio =	gop2byte(h21, h22);
		chuoi(":");
		m21 = Uart_Read();
		Uart_Write(m21);
		kitu(m21);
		m22 = Uart_Read();
		Uart_Write(m22);
		kitu(m22);
		phut = gop2byte(m21, m22);
		chuoi(":");
		s21 = Uart_Read();
		Uart_Write(s21);
		kitu(s21);
		s22 = Uart_Read();
		Uart_Write(s22);
		kitu(s22);
		giay = gop2byte(s21, s22);
		delay(10);
		lenh(0x01);
		chuoi("    SET NGAY");
		delay(2000);
		lenh(0x01);
		chuoi("  DATE:DD/MM/YY");
		lenh(0xc0);
		chuoi("     ");
		Uart_Init();
		thu1 = Uart_Read();
		Uart_Write(thu1);
		kitu(thu1);
		thu = thu1-48;
		chuoi(":");
		dd1 = Uart_Read();
		Uart_Write(dd1);
		kitu(dd1);
		dd2 = Uart_Read();
		Uart_Write(dd2);
		kitu(dd2);
		ngay = gop2byte(dd1, dd2);
		chuoi("/");
		mm1 = Uart_Read();
		Uart_Write(mm1);
		kitu(mm1);
		mm2 = Uart_Read();
		Uart_Write(mm2);
		kitu(mm2);
		thang = gop2byte(mm1, mm2);
		chuoi("/");
		yy1 = Uart_Read();
		Uart_Write(yy1);
		kitu(yy1);
		yy2 = Uart_Read();
		Uart_Write(yy2);
		kitu(yy2);
		nam = gop2byte(yy1, yy2);
		ghi(0x00, giay);
		ghi(0x01, phut);
		ghi(0x02, gio);
		ghi(0x03, thu);
		ghi(0x04, ngay);
		ghi(0x05, thang);
		ghi(0x06, nam);
		mode=0;
		}
	if (mode==2) // che do hen gio
		{
		khoitao();
		chuoi("    HEN GIO");
		delay(1000);
		lenh(0x01);
		chuoi("     HH:MM");
		lenh(0xc0);
		chuoi("     ");
		Uart_Init();
		h11 = Uart_Read();
		Uart_Write(h11);
		kitu(h11);
		h12 = Uart_Read();
		Uart_Write(h12);
		kitu(h12);
		chuoi(":");
		m11 = Uart_Read();
		Uart_Write(m11);
		kitu(m11);
		m12 = Uart_Read();
		Uart_Write(m12);
		kitu(m12);
		lenh(0x01);
		chuoi("  NHAC CHUONG");
		lenh(0xc0);
		chuong1 = Uart_Read();
		Uart_Write(chuong1);
		while (1) {

		if ((chuong1!='a')&&(chuong1!='b')&&(chuong1!='c')) chuong1='a';
		if (chuong1 == 'a') {
		chuoi("    CHUONG 1");
		batchuong();
		Uart_Init();
		chuong2 = Uart_Read();
		Uart_Write(chuong2);
		if (chuong2 == 'a') { mode=0; break;  } else { chuong1=chuong2;}
		}
		lenh(0x01);
		chuoi("  NHAC CHUONG");
		lenh(0xc0);
		if (chuong1 == 'b') {
		chuoi("    CHUONG 2");
		batchuong();
		Uart_Init();
		chuong2 = Uart_Read();
		Uart_Write(chuong2);
		if (chuong2 == 'b') { mode=0;  break;  } else { chuong1=chuong2;}
		}
		lenh(0x01);
		chuoi("  NHAC CHUONG");
		lenh(0xc0);
		if (chuong1 == 'c') {
		chuoi("    CHUONG 3");
		batchuong();
		Uart_Init();
		chuong2 = Uart_Read();
		Uart_Write(chuong2);
		if (chuong2 == 'c') { mode=0; break;  } else { chuong1=chuong2;}
		}
		lenh(0x01);
		chuoi("  NHAC CHUONG");
		lenh(0xc0);
		}
		}
  }
}