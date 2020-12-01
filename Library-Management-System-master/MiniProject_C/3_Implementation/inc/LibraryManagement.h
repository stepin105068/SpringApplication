#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h> //containsstrcmp(),strcpy(),strlen(),etc
#include<ctype.h> //containstoupper(),tolower(),etc
#include<dos.h> //contains_dos_getdate
#include<time.h>
//#include<bios.h>
#defineRETURNTIME15
charcatagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
voidreturnfunc(void);
voidmainmenu(void);
voidaddbooks(void);
voiddeletebooks(void);
voideditbooks(void);
voidsearchbooks(void);
voidissuebooks(void);
voidviewbooks(void);
voidcloseapplication(void);
int getdata();
int checkid(int);
intt(void);
//voidshow_mouse(void);
voidPassword();
voidissuerecord();
voidloaderanim();
