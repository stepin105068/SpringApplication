voidaddbooks(void) //funtionthataddbooks { 
system("cls"); 
inti; 
gotoxy(20,5); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7); 
printf("\xDB\xDB\xDB\xDB\xB21.Computer"); gotoxy(20,9); 
printf("\xDB\xDB\xDB\xDB\xB22.Electronics"); gotoxy(20,11); 
printf("\xDB\xDB\xDB\xDB\xB23.Electrical"); gotoxy(20,13); 
printf("\xDB\xDB\xDB\xDB\xB24.Civil"); gotoxy(20,15); 
printf("\xDB\xDB\xDB\xDB\xB25.Mechanical"); gotoxy(20,17); 
printf("\xDB\xDB\xDB\xDB\xB26.Architecture"); gotoxy(20,19); 
printf("\xDB\xDB\xDB\xDB\xB27.Backtomainmenu");

gotoxy(20,21); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); 
gotoxy(20,22); 
printf("Enteryourchoice:"); 
scanf("%d",&s); 
if(s==7) 
mainmenu(); 
system("cls"); 
fp=fopen("Bibek.dat","ab+"); 
if(getdata()==1) 
{ 
a.cat=catagories[s-1]; 
fseek(fp,0,SEEK_END); 
fwrite(&a,sizeof(a),1,fp); 
fclose(fp); 
gotoxy(21,14); 
printf("Therecordissucessfullysaved"); gotoxy(21,15); 
printf("Saveanymore?(Y/N):"); 
if(getch()=='n') 
mainmenu(); 
else 
system("cls"); 
addbooks(); 
} 
} 
voiddeletebooks() //functionthatdeleteitemsfromfilefp { 
system("cls"); 
intd; 
charanother='y'; 
while(another=='y') //infiniteloop 
{ 
system("cls"); 
gotoxy(10,5); 
printf("EntertheBookIDto delete:"); scanf("%d",&d); 
fp=fopen("Bibek.dat","rb+"); 
rewind(fp); 
while(fread(&a,sizeof(a),1,fp)==1) 
{ 
if(a.id==d) 
{ 
gotoxy(10,7); 
printf("Thebookrecordisavailable"); gotoxy(10,8); 
printf("Booknameis%s",a.name); 
gotoxy(10,9); 
printf("RackNo.is%d",a.rackno); 
findbook='t'; 
} 
} 
if(findbook!='t') 
{ 
gotoxy(10,10); 
printf("Norecordisfoundmodifythesearch");

if(getch()) 
mainmenu(); 
} 
if(findbook=='t') 
{ 
gotoxy(10,9); 
printf("Doyouwanttodeleteit?(Y/N):"); if(getch()=='y') 
{ 
ft=fopen("test.dat","wb+"); //temporaryfilefordelete rewind(fp); 
while(fread(&a,sizeof(a),1,fp)==1) 
{ 
if(a.id!=d) 
{ 
fseek(ft,0,SEEK_CUR); 
fwrite(&a,sizeof(a),1,ft);//writeallintemporyfileexceptthat } //wewanttodelete } 
fclose(ft); 
fclose(fp); 
remove("Bibek.dat"); 
rename("test.dat","Bibek.dat");//copyallitemfromtemporaryfiletofpexceptthatfp=fopen("Bibek.dat","rb+"); //wewanttodelete if(findbook=='t') 
{ 
gotoxy(10,10); 
printf("Therecordissucessfullydeleted"); gotoxy(10,11); 
printf("Deleteanotherrecord?(Y/N)"); } 
} 
else 
mainmenu(); 
fflush(stdin); 
another=getch(); 
} 
} 
gotoxy(10,15); 
mainmenu(); 
} 
voidsearchbooks() 
{ 
system("cls"); 
intd; 
printf("*****************************SearchBooks*********************************");gotoxy(20,10); 
printf("\xDB\xDB\xDB\xB21.SearchByID"); gotoxy(20,14); 
printf("\xDB\xDB\xDB\xB22.SearchByName"); gotoxy(15,20); 
printf("EnterYourChoice"); 
fp=fopen("Bibek.dat","rb+");//openfileforreadingpropose rewind(fp); //movepointeratthebeginingoffile switch(getch()) 
{ 
case'1': 
{ 
system("cls"); 
gotoxy(25,4);

printf("****SearchBooksById****"); 
gotoxy(20,5); 
printf("Enterthebookid:"); 
scanf("%d",&d); 
gotoxy(20,7); 
printf("Searching........"); 
while(fread(&a,sizeof(a),1,fp)==1) 
{ 
if(a.id==d) 
{ 
Sleep(2); 
gotoxy(20,7); 
printf("TheBookisavailable"); 
gotoxy(20,8); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,9); 
printf("\xB2ID:%d",a.id);gotoxy(47,9);printf("\xB2"); gotoxy(20,10); 
printf("\xB2Name:%s",a.name);gotoxy(47,10);printf("\xB2"); gotoxy(20,11); 
printf("\xB2Author:%s",a.Author);gotoxy(47,11);printf("\xB2"); gotoxy(20,12); 
printf("\xB2Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2");gotoxy(47,11);printf("\xB2");gotoxy(20,13); 
printf("\xB2Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2"); gotoxy(20,14); 
printf("\xB2RackNo:%d",a.rackno);gotoxy(47,14);printf("\xB2"); gotoxy(20,15); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); findbook='t'; 
} 
} 
if(findbook!='t') //checkswhetherconditiionentersinsideloopornot
{ 
gotoxy(20,8); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); 
gotoxy(20,9);printf("\xB2"); gotoxy(38,9);printf("\xB2"); gotoxy(20,10); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); 
gotoxy(22,9);printf("\aNoRecordFound"); } 
gotoxy(20,17); 
printf("Tryanothersearch?(Y/N)"); 
if(getch()=='y') 
searchbooks(); 
else 
mainmenu(); 
break; 
} 
case'2': 
{ 
chars[15]; 
system("cls"); 
gotoxy(25,4); 
printf("****SearchBooksByName****");

gotoxy(20,5); 
printf("EnterBookName:"); 
scanf("%s",s); 
intd=0; 
while(fread(&a,sizeof(a),1,fp)==1) 
{ 
if(strcmp(a.name,(s))==0)//checkswhethera.nameisequaltosornot
{ 
gotoxy(20,7); 
printf("TheBookisavailable"); 
gotoxy(20,8); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,9); 
printf("\xB2ID:%d",a.id);gotoxy(47,9);printf("\xB2"); gotoxy(20,10); 
printf("\xB2Name:%s",a.name);gotoxy(47,10);printf("\xB2"); gotoxy(20,11); 
printf("\xB2Author:%s",a.Author);gotoxy(47,11);printf("\xB2"); gotoxy(20,12); 
printf("\xB2Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(20,13); 
printf("\xB2Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2"); gotoxy(20,14); 
printf("\xB2RackNo:%d",a.rackno);gotoxy(47,14);printf("\xB2"); gotoxy(20,15); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); d++; 
} 
} 
if(d==0) 
{ 
gotoxy(20,8); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); 
gotoxy(20,9);printf("\xB2"); gotoxy(38,9);printf("\xB2"); gotoxy(20,10); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); 
gotoxy(22,9);printf("\aNoRecordFound"); } 
gotoxy(20,17); 
printf("Tryanothersearch?(Y/N)"); 
if(getch()=='y') 
searchbooks(); 
else 
mainmenu(); 
break; 
} 
default: 
getch(); 
searchbooks(); 
} 
fclose(fp); 
} 
voidissuebooks(void) //functionthatissuebooksfromlibrary { 
intt;

system("cls"); 
printf("********************************ISSUESECTION**************************");
gotoxy(10,5); 
printf("\xDB\xDB\xDB\xDb\xB21.IssueaBook"); gotoxy(10,7); 
printf("\xDB\xDB\xDB\xDb\xB22.ViewIssuedBook"); gotoxy(10,9); 
printf("\xDB\xDB\xDB\xDb\xB23.SearchIssuedBook"); gotoxy(10,11); 
printf("\xDB\xDB\xDB\xDb\xB24.RemoveIssuedBook"); gotoxy(10,14); 
printf("EnteraChoice:"); 
switch(getch()) 
{ 
case'1': //issuebook 
{ 
system("cls"); 
intc=0; 
charanother='y'; 
while(another=='y') 
{ 
system("cls"); 
gotoxy(15,4); 
printf("***IssueBooksection***"); 
gotoxy(10,6); 
printf("EntertheBookId:"); 
scanf("%d",&t); 
fp=fopen("Bibek.dat","rb"); 
fs=fopen("Issue.dat","ab+"); 
if(checkid(t)==0)//issuesthosewhicharepresentinlibrary { 
gotoxy(10,8); 
printf("Thebookrecordisavailable"); 
gotoxy(10,9); 
printf("Thereare%dunissuedbooksinlibrary",a.quantity); gotoxy(10,10); 
printf("Thenameofbookis%s",a.name); gotoxy(10,11); 
printf("Enterstudentname:"); 
scanf("%s",a.stname); 
//structdosdate_td;//forcurrentdate 
//_dos_getdate(&d); 
//a.issued.dd=d.day; 
//a.issued.mm=d.month; 
//a.issued.yy=d.year; 
gotoxy(10,12); 
printf("Issueddate=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy); gotoxy(10,13); 
printf("TheBOOKofID%disissued",a.id); a.duedate.dd=a.issued.dd+RETURNTIME; //forreturndate a.duedate.mm=a.issued.mm; 
a.duedate.yy=a.issued.yy; 
if(a.duedate.dd>30) 
{ 
a.duedate.mm+=a.duedate.dd/30; 
a.duedate.dd-=30; 
} 
if(a.duedate.mm>12)

{ 
a.duedate.yy+=a.duedate.mm/12; 
a.duedate.mm-=12; 
} 
gotoxy(10,14); 
printf("Tobereturn:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
fseek(fs,sizeof(a),SEEK_END); 
fwrite(&a,sizeof(a),1,fs); 
fclose(fs); 
c=1; 
} 
if(c==0) 
{ 
gotoxy(10,11); 
printf("Norecordfound"); 
} 
gotoxy(10,15); 
printf("Issueanymore(Y/N):"); 
fflush(stdin); 
another=getche(); 
fclose(fp); 
} 
break; 
} 
case'2': //showissuedbooklist 
{ 
system("cls"); 
intj=4; 
printf("*******************************Issuedbooklist*******************************\n");gotoxy(2,2); 
printf("STUDENTNAME CATEGORY ID BOOKNAMEISSUEDDATERETURNDATE"); 
fs=fopen("Issue.dat","rb"); 
while(fread(&a,sizeof(a),1,fs)==1) 
{ 
gotoxy(2,j); 
printf("%s",a.stname); 
gotoxy(18,j); 
printf("%s",a.cat); 
gotoxy(30,j); 
printf("%d",a.id); 
gotoxy(36,j); 
printf("%s",a.name); 
gotoxy(51,j); 
printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy); gotoxy(65,j); 
printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy); //structdosdate_td; 
//_dos_getdate(&d); 
gotoxy(50,25); 
// printf("Currentdate=%d-%d-%d",d.day,d.month,d.year); j++; 
} 
fclose(fs); 
gotoxy(1,25); 
returnfunc();

} 
break; 
case'3': //searchissuedbooksbyid { 
system("cls"); 
gotoxy(10,6); 
printf("EnterBookID:"); 
intp,c=0; 
charanother='y'; 
while(another=='y') 
{ 
scanf("%d",&p); 
fs=fopen("Issue.dat","rb"); 
while(fread(&a,sizeof(a),1,fs)==1) { 
if(a.id==p) 
{ 
issuerecord(); 
gotoxy(10,12); 
printf("Pressanykey......."); getch(); 
issuerecord(); 
c=1; 
} 
} 
fflush(stdin); 
fclose(fs); 
if(c==0) 
{ 
gotoxy(10,8); 
printf("NoRecordFound"); 
} 
gotoxy(10,13); 
printf("TryAnotherSearch?(Y/N)"); another=getch(); 
} 
} 
break; 
case'4': //removeissuedbooksfromlist { 
system("cls"); 
intb; 
FILE*fg; //declarationoftemporaryfilefordelete charanother='y'; 
while(another=='y') 
{ 
gotoxy(10,5); 
printf("Enterbookidtoremove:"); scanf("%d",&b); 
fs=fopen("Issue.dat","rb+"); while(fread(&a,sizeof(a),1,fs)==1) { 
if(a.id==b) 
{ 
issuerecord(); 
findbook='t'; 
} 
if(findbook=='t')

{ 
gotoxy(10,12); 
printf("DoYouWanttoRemoveit?(Y/N)"); if(getch()=='y') 
{ 
fg=fopen("record.dat","wb+"); 
rewind(fs); 
while(fread(&a,sizeof(a),1,fs)==1) 
{ 
if(a.id!=b) 
{ 
fseek(fs,0,SEEK_CUR); 
fwrite(&a,sizeof(a),1,fg); 
} 
} 
fclose(fs); 
fclose(fg); 
remove("Issue.dat"); 
rename("record.dat","Issue.dat"); 
gotoxy(10,14); 
printf("Theissuedbookisremovedfromlist"); } 
} 
if(findbook!='t') 
{ 
gotoxy(10,15); 
printf("NoRecordFound"); 
} 
} 
gotoxy(10,16); 
printf("Deleteanymore?(Y/N)"); 
another=getch(); 
} 
} 
default: 
gotoxy(10,18); 
printf("\aWrongEntry!!"); 
getch(); 
issuebooks(); 
break; 
} 
gotoxy(1,30); 
returnfunc(); 
} 
voidviewbooks(void) //showthelistofbookpersistsinlibrary { 
inti=0,j; 
system("cls"); 
gotoxy(1,1); 
printf("*********************************BookList*****************************");
gotoxy(2,2); 
printf("CATEGORY ID BOOKNAME AUTHOR QTYPRICERackNo"); 
j=4; 
fp=fopen("Bibek.dat","rb"); 
while(fread(&a,sizeof(a),1,fp)==1) 
{ 
gotoxy(3,j);

printf("%s",a.cat); 
gotoxy(16,j); 
printf("%d",a.id); 
gotoxy(22,j); 
printf("%s",a.name); 
gotoxy(36,j); 
printf("%s",a.Author); 
gotoxy(50,j); 
printf("%d",a.quantity); 
gotoxy(57,j); 
printf("%.2f",a.Price); 
gotoxy(69,j); 
printf("%d",a.rackno); 
printf("\n\n"); 
j++; 
i=i+a.quantity; 
} 
gotoxy(3,25); 
printf("TotalBooks=%d",i); 
fclose(fp); 
gotoxy(35,25); 
returnfunc(); 
} 
voideditbooks(void) //editinformationaboutbook { 
system("cls"); 
intc=0; 
intd,e; 
gotoxy(20,4); 
printf("****EditBooksSection****"); charanother='y'; 
while(another=='y') 
{ 
system("cls"); 
gotoxy(15,6); 
printf("EnterBookIdtobeedited:"); scanf("%d",&d); 
fp=fopen("Bibek.dat","rb+"); 
while(fread(&a,sizeof(a),1,fp)==1) { 
if(checkid(d)==0) 
{ 
gotoxy(15,7); 
printf("Thebookisavailble"); gotoxy(15,8); 
printf("TheBookID:%d",a.id); gotoxy(15,9); 
printf("Enternewname:");scanf("%s",a.name); gotoxy(15,10); 
printf("EnternewAuthor:");scanf("%s",a.Author); gotoxy(15,11); 
printf("Enternewquantity:");scanf("%d",&a.quantity); gotoxy(15,12); 
printf("Enternewprice:");scanf("%f",&a.Price); gotoxy(15,13); 
printf("Enternewrackno:");scanf("%d",&a.rackno); gotoxy(15,14); 
printf("Therecordismodified"); fseek(fp,ftell(fp)-sizeof(a),0); fwrite(&a,sizeof(a),1,fp);

fclose(fp); 
c=1; 
} 
if(c==0) 
{ 
gotoxy(15,9); 
printf("Norecordfound"); 
} 
} 
gotoxy(15,16); 
printf("ModifyanotherRecord?(Y/N)"); fflush(stdin); 
another=getch(); 
} 
returnfunc(); 
} 
voidreturnfunc(void) 
{ 
{ 
printf("PressENTERtoreturntomainmenu"); } 
a: 
if(getch()==13)//allowonlyuseofenter mainmenu(); 
else 
gotoa; 
} 
intgetdata() 
{ 
intt; 
gotoxy(20,3);printf("EntertheInformationBelow"); gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,5); 
printf("\xB2");gotoxy(46,5);printf("\xB2"); gotoxy(20,6); 
printf("\xB2");gotoxy(46,6);printf("\xB2"); gotoxy(20,7); 
printf("\xB2");gotoxy(46,7);printf("\xB2"); gotoxy(20,8); 
printf("\xB2");gotoxy(46,8);printf("\xB2"); gotoxy(20,9); 
printf("\xB2");gotoxy(46,9);printf("\xB2"); gotoxy(20,10); 
printf("\xB2");gotoxy(46,10);printf("\xB2"); gotoxy(20,11); 
printf("\xB2");gotoxy(46,11);printf("\xB2"); gotoxy(20,12); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(21,5); 
printf("Category:"); 
gotoxy(31,5); 
printf("%s",catagories[s-1]); 
gotoxy(21,6); 
printf("BookID:\t"); 
gotoxy(30,6); 
scanf("%d",&t); 
if(checkid(t)==0) 
{

gotoxy(21,13); 
printf("\aThebookidalreadyexists\a"); 
getch(); 
mainmenu(); 
return0; 
} 
a.id=t; 
gotoxy(21,7); 
printf("BookName:");gotoxy(33,7); 
scanf("%s",a.name); 
gotoxy(21,8); 
printf("Author:");gotoxy(30,8); 
scanf("%s",a.Author); 
gotoxy(21,9); 
printf("Quantity:");gotoxy(31,9); 
scanf("%d",&a.quantity); 
gotoxy(21,10); 
printf("Price:");gotoxy(28,10); 
scanf("%f",&a.Price); 
gotoxy(21,11); 
printf("RackNo:");gotoxy(30,11); 
scanf("%d",&a.rackno); 
return1; 
} 
intcheckid(intt) //checkwhetherthebookisexistinlibraryornot { 
rewind(fp); 
while(fread(&a,sizeof(a),1,fp)==1) 
if(a.id==t) 
return0; //returns0ifbookexits 
return1;//return1ifitnot 
} 
intt(void)//fortime 
{ 
time_tt; 
time(&t); 
printf("Dateandtime:%s\n",ctime(&t)); 
return0; 
} 
/*voidshow_mouse(void)//showinactivemousepointerinprogramme
{ 
unionREGSin,out; 
in.x.ax=0x1; 
int86(0x33,&in,&out); 
}*/ 
voidPassword(void)//forpasswordoption { 
system("cls"); 
chard[25]="PasswordProtected"; 
charch,pass[10]; 
inti=0,j; 
//textbackground(WHITE); 
//textcolor(RED); 
gotoxy(10,4); 
for(j=0;j<20;j++) 
{ 
Sleep(50); 
printf("*");

} 
for(j=0;j<20;j++) 
{ 
Sleep(50); 
printf("%c",d[j]); 
} 
for(j=0;j<20;j++) 
{ 
Sleep(50); 
printf("*"); 
} 
gotoxy(10,10); 
gotoxy(15,7); 
printf("EnterPassword:"); 
while(ch!=13) 
{ 
ch=getch(); 
if(ch!=13&&ch!=8){ 
putch('*'); 
pass[i]=ch; 
i++; 
} 
} 
pass[i]='\0'; 
if(strcmp(pass,password)==0) 
{ 
gotoxy(15,9); 
//textcolor(BLINK); 
printf("Passwordmatch"); 
gotoxy(17,10); 
printf("Pressanykeytocountinue....."); 
getch(); 
mainmenu(); 
} 
else 
{ 
gotoxy(15,16); 
printf("\aWarning!!IncorrectPassword"); getch(); 
Password(); 
} 
} 
voidissuerecord() //displayissuedbook'sinformation { 
system("cls"); 
gotoxy(10,8); 
printf("TheBookhastakenbyMr.%s",a.stname); gotoxy(10,9); 
printf("IssuedDate:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy); gotoxy(10,10); 
printf("ReturningDate:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
} 
/*voidloaderanim() 
{ 
intloader; 
system("cls"); 
gotoxy(20,10);

printf("LOADING........"); printf("\n\n"); 
gotoxy(22,11); for(loader=1;loader<20;loader++) { 
Sleep(100);printf("%c",219);} }*/ 
//Endofprogram

