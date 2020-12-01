#include<stdio.h>
FILE*fp,*ft,*fs; 
COORDcoord={0,0}; 
//listofglobalvariable 
ints; 
charfindbook; 
charpassword[10]={"codewithc"}; 
voidgotoxy(intx,inty) 
{ 
coord.X=x;coord.Y=y;//XandYcoordinates SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
} 
structmeroDate 
{ 
intmm,dd,yy; 
}; 
structbooks 
{ 
intid; 
charstname[20]; 
charname[20]; 
charAuthor[20]; 
intquantity; 
floatPrice; 
intcount; 
intrackno;

char*cat; 
structmeroDateissued; 
structmeroDateduedate; 
}; 
structbooksa; 
intmain() 
{ 
Password(); 
getch(); 
return0; 
} 
voidmainmenu() 
{ 
//loaderanim(); 
system("cls"); 
// textbackground(13); 
inti; 
gotoxy(20,3); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2MAINMENU\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); // show_mouse(); 
gotoxy(20,5); 
printf("\xDB\xDB\xDB\xDB\xB21.AddBooks "); gotoxy(20,7); 
printf("\xDB\xDB\xDB\xDB\xB22.Deletebooks"); gotoxy(20,9); 
printf("\xDB\xDB\xDB\xDB\xB23.SearchBooks"); gotoxy(20,11); 
printf("\xDB\xDB\xDB\xDB\xB24.IssueBooks"); gotoxy(20,13); 
printf("\xDB\xDB\xDB\xDB\xB25.ViewBooklist"); gotoxy(20,15); 
printf("\xDB\xDB\xDB\xDB\xB26.EditBook'sRecord"); gotoxy(20,17); 
printf("\xDB\xDB\xDB\xDB\xB27.CloseApplication"); gotoxy(20,19); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); 
gotoxy(20,20); 
t(); 
gotoxy(20,21); 
printf("Enteryourchoice:"); 
switch(getch()) 
{ 
case'1': 
addbooks(); 
break; 
case'2': 
deletebooks(); 
break; 
case'3': 
searchbooks(); 
break; 
case'4': 
issuebooks(); 
break; 
case'5': 
viewbooks();

break; 
case'6': 
editbooks(); 
break; 
case'7': 
{ 
system("cls"); 
gotoxy(16,3); 
printf("\tLibraryManagementSystem"); gotoxy(16,4); 
printf("\tMiniProjectinC"); 
gotoxy(16,5); 
printf("\tisbroughttoyouby"); 
gotoxy(16,7); 
printf("\tCodewithCTeam"); 
gotoxy(16,8); 
printf("******************************************"); gotoxy(16,10); 
printf("*******************************************"); gotoxy(16,11); 
printf("*******************************************"); gotoxy(16,13); 
printf("********************************************"); gotoxy(10,17); 
printf("Exitingin3second...........>"); 
//flushall(); 
Sleep(3000); 
exit(0); 
} 
default: 
{ 
gotoxy(10,23); 
printf("\aWrongEntry!!Pleasere-enteredcorrectoption"); if(getch()) 
mainmenu(); 
} 
} 
} 
