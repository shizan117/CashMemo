# include "iGraphics.h"
# include<stdlib.h>
#include <cstring> 
 #include <stdio.h>
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

bool musicOn=true;
int mposx,  mposy;
int page ;
int s; // history read
int q1,q2,q3,q4,q5,q6,q7,q8;
int len,mode,input,ii,i,iii;
int add=0,price_1=0,price_2=0,price_3=0,price_4=0,price_5=0,price_6=0,price_7=0,price_8=0;
char str[100]; // iText use this
char str2[100],/*products name*/ str3[50],/*price*/ 
     str5[50]/*price1*/,str6[50]/*price2*/,str7[50]/*price3*/,str8[50]/*price4*/,str9[50]/*price5*/,str10[50]/*price6*/,str11[50]/*price7*/,str12[50]/*price8*/,
     str13[50]/*quantity1*/,str14[50]/*quantity2*/,str15[50]/*quantity3*/,str16[50]/*quantity4*/,str17[50]/*quantity5*/,str18[50]/*quantity6*/,str19[50]/*quantity7*/,str20[50]/*quantity8*/,
     str23[50]/*name1*/,str24[50]/*name2*/,str25[50]/*name3*/,str26[50]/*name4*/,str27[50]/*name5*/,str28[50]/*name6*/,str29[50]/*name7*/,str30[50]/*name8*/;
char total[50]; // total price
char str22[100]/*date*/,str222[100]/*time*/, str33[100]/*search*/;
int  p;
int  r=252;
int  g=0;
int  b=0;
int  k ;
char ch[100];
int m; //ProductsQuantity
int pr; //ProductsPrice
void change()
{

    g=rand()%255;
    b=rand()%245;
}


char file[1000][10000];
char filepr[1000][10000];
char fileSearch[1000][10000];
void fileRead()        //::::: this will print products name in delete page
{
    FILE *fp = fopen("ProductsName.txt", "r");
    while (fscanf(fp, "%s", &file[i]) != EOF)
    {
        printf("%s\n", file[i]);
        i++;
    }
    fclose(fp);

}
char fil[10][100];

void ProductsQuantityfileRead()// ::::: this will print products quantity in delete page
{
    FILE *f = fopen("ProductsQuantity.txt", "r");
    while (fscanf(f, "%s", &fil[m]) != EOF)
    {

        printf("%s\n", fil[m]);
        m++;
    }
    fclose(f);

}

						//:::::::::::::::::function of dlt:::::::::::::::::::

							void print_file(FILE *fp)
						{
							char ch;
							while((ch=fgetc(fp)) != EOF)
							{
								printf("%c",ch);
							}


						}




void iDraw()
{

    iClear();


    add=price_1+price_2+price_3+price_4+price_5+price_6+price_7+price_8;
    itoa(add,total,10);

    if(page==0)
    {
        /*=================================================================*/
        /*...................... WELCOME PAGE .........................*/
        /*==================================================================*/

        iShowBMP(0,0,"image\\welcome.bmp");
        iSetColor(r,g,b);
        iText(410,323,"WELCOME",GLUT_BITMAP_TIMES_ROMAN_24);

//............ this rectangle will create rectangle outside of start button...................
        iRectangle(369,1,204,55);
        iRectangle(368,2,204,53);
        iRectangle(367,3,204,52);
        iRectangle(369,1,204,53);

    }
    /*=================================================================*/
    /*...................... PATTERN PAGE .........................*/
    /*==================================================================*/
    if(page==1)
    {
        iClear();
        if(p==0)
        {
            iShowBMP(0,0,"pattern\\0.bmp");
        }
        if(p==1)
        {
            iShowBMP(0,0,"pattern\\1.bmp");
        }
        if(p==2)
        {
            iShowBMP(0,0,"pattern\\2nd.bmp");
        }
        if(p==3)
        {
            iShowBMP(0,0,"pattern\\3rd.bmp");
        }
        if(p==4)
        {
            iShowBMP(0,0,"pattern\\4.bmp");
        }

        if(p==21)
        {
            iShowBMP(0,0,"pattern\\incorrect.bmp");
        }


    }
    /*=================================================================*/
    /*...................... MEMu PAGE .........................*/
    /*==================================================================*/

    if (page==2)
    {
        iClear();
        iShowBMP(0,0,"image\\menu.bmp");

    }

    /*=================================================================*/
    /*...................... ADD PRODUCTS PAGE .........................*/
    /*==================================================================*/
    if (page==3)
    {
        iClear();

        iShowBMP(0,0,"image\\add1.bmp");
        iSetColor(r,g,b);
        iRectangle(390,33,137,25);
        iText(395,40,"Click to MENU",GLUT_BITMAP_HELVETICA_18);



        //.................. Showing word .............
        iSetColor(210,210,210); //black color
        iText(346,480,str2,GLUT_BITMAP_HELVETICA_18); // products name
        iText(346,356,str3,GLUT_BITMAP_HELVETICA_18);//  price
       // iText(333,210,str3,GLUT_BITMAP_HELVETICA_18);//price
        if(mode==1)   // products name
        {
            iSetColor(0,0,0);
            iText(346,480,str,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(347,481,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(mode==2)  //  quantity
        {
            iSetColor(0,0,0);
              iText(346,356,str,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(347,356,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

       
    }


    /*=================================================================*/
    /*...................... DELETE PAGE .........................*/
    /*==================================================================*/

    if(page ==4)
    {
        iClear();
        iShowBMP(0,0,"image\\delete.bmp");
        iSetColor(r,g,b);
        iRectangle(390,33,137,25);
        iText(395,40,"Click to MENU",GLUT_BITMAP_HELVETICA_18);
        iSetColor(0, 0, 0);
        for (int j = 0, y = 460; j<i; j++, y -= 20)
        {
            iText(83, y, file[j]);
        }
        for (int k = 0, l = 460; k<m; k++, l -= 20)
        {
            iText(150, l, fil[k]);
        }

        if(mode==50)   // input to delete
        {
            iSetColor(0,0,0);
            iText(622,380,str,GLUT_BITMAP_HELVETICA_18);
        }
    }




    /*=================================================================*/
    /*...................... MEMO PAGE .........................*/
    /*==================================================================*/

    else if (page==5)
    {
        iClear();

        iShowBMP(0,0,"image\\memo1.bmp");
        iSetColor(r,g,b);
        iRectangle(390,2,137,25);
        iText(395,10,"Click to MENU",GLUT_BITMAP_HELVETICA_18);


        iSetColor(0,0,0); // white color
        iText(780,455,str5,GLUT_BITMAP_HELVETICA_18);//price1
        iText(780,420,str6,GLUT_BITMAP_HELVETICA_18);//price2
        iText(780,376,str7,GLUT_BITMAP_HELVETICA_18);//price3
        iText(780,335,str8,GLUT_BITMAP_HELVETICA_18);//price4
        iText(780,300,str9,GLUT_BITMAP_HELVETICA_18);//price5
        iText(780,260,str10,GLUT_BITMAP_HELVETICA_18);//price6
        iText(780,215,str11,GLUT_BITMAP_HELVETICA_18);//price7
        iText(780,180,str12,GLUT_BITMAP_HELVETICA_18);//price8

        iText(610,455,str13,GLUT_BITMAP_HELVETICA_18);//quantity1
        iText(610,420,str14,GLUT_BITMAP_HELVETICA_18);//quantity2
        iText(610,375,str15,GLUT_BITMAP_HELVETICA_18);//quantity3
        iText(610,337,str16,GLUT_BITMAP_HELVETICA_18);//quantity4
        iText(610,295,str17,GLUT_BITMAP_HELVETICA_18);//quantity5
        iText(610,257,str18,GLUT_BITMAP_HELVETICA_18);//quantity6
        iText(610,224,str19,GLUT_BITMAP_HELVETICA_18);//quantity7
        iText(610,180,str20,GLUT_BITMAP_HELVETICA_18);//quantity8

        iText(340,460,str23,GLUT_BITMAP_TIMES_ROMAN_24);//product_name1
        iText(340,415,str24,GLUT_BITMAP_TIMES_ROMAN_24);//product_name2
        iText(340,376,str25,GLUT_BITMAP_TIMES_ROMAN_24);//product_name3
        iText(340,340,str26,GLUT_BITMAP_TIMES_ROMAN_24);//product_name4
        iText(340,295,str27,GLUT_BITMAP_TIMES_ROMAN_24);//product_name5
        iText(340,258,str28,GLUT_BITMAP_TIMES_ROMAN_24);//product_name6
        iText(340,218,str29,GLUT_BITMAP_TIMES_ROMAN_24);//product_name7
        iText(340,178,str30,GLUT_BITMAP_TIMES_ROMAN_24);//product_name8

      iText(785,594,str22,GLUT_BITMAP_TIMES_ROMAN_24); // date
      iText(785,594,str22,GLUT_BITMAP_TIMES_ROMAN_24); // date

	   iText(785,560,str222,GLUT_BITMAP_TIMES_ROMAN_24);//time
	   iText(784,559,str222,GLUT_BITMAP_TIMES_ROMAN_24);//time

	   

        iSetColor(0, 0, 0);
        for (int j = 0, y = 422; j<ii; j++, y -= 20)  // products name in store box 
        {
			iText(85, y, file[j],GLUT_BITMAP_HELVETICA_18);

        }
        for (int j = 0, e = 422; j<pr; j++, e -= 20)
        {
            iText(230, e, filepr[j],GLUT_BITMAP_HELVETICA_18);
        }


        if(mode==4) //date
        {
            iSetColor(0,0,0);
            iText(785,594,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }
		 if(mode==44) //time
        {
			 iSetColor(127,127,127);
            iFilledRectangle(775,551,152,32);
            iSetColor(0,0,0);
            iText(785,560,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }


        if(mode==5) //price1
        {
            iSetColor(127,127,127);
            iFilledRectangle(775,447,153,36);
            iSetColor(0,0,0);
            iText(783,455,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(mode==6) //price2
        {
            iSetColor(127,127,127);
            iFilledRectangle(775,409,153,34);
            iSetColor(0,0,0);
            iText(780,420,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(mode==7) //price3
        {
            iSetColor(127,127,127);
            iFilledRectangle(775,368,153,36);
            iSetColor(0,0,0);
            iText(780,376,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(mode==8) //price4
        {
            iSetColor(127,127,127);
            iFilledRectangle(775,328,153,36);
            iSetColor(0,0,0);
            iText(780,335,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(mode==9) //price5
        {
            iSetColor(127,127,127);
            iFilledRectangle(775,287,153,36);
            iSetColor(0,0,0);
            iText(780,300,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(mode==10) //price6
        {
            iSetColor(127,127,127);
            iFilledRectangle(775,249,153,36);
            iSetColor(0,0,0);
            iText(779,260,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(mode==11) //price7
        {
            iSetColor(127,127,127);
            iFilledRectangle(775,208,153,36);
            iSetColor(0,0,0);
            iText(779,215,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }


        if(mode==12) //price8
        {
            iSetColor(127,127,127);
            iFilledRectangle(776,168,153,36);
            iSetColor(0,0,0);
            iText(779,180,str,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(mode==13)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,447,226,36);
            //taking quantity 1 as a string
            iSetColor(0,0,0);
            iText(610,455,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==14)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,409,226,35);
            //taking quantity 2 as a string
            iSetColor(0,0,0);
            iText(610,420,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        if(mode==15)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,368,226,36);
            //taking quantity 3 as a string
            iSetColor(0,0,0);
            iText(610,375,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==16)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,328,226,35);
            //taking quantity 4 as a string
            iSetColor(0,0,0);
            iText(610,337,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==17)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,287,226,36);
            //taking quantity 5 as a string
            iSetColor(0,0,0);
            iText(610,295,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==18)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,249,226,34);
            //taking quantity 6 as a string
            iSetColor(0,0,0);
            iText(610,257,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        if(mode==19)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,208,226,36);
            //taking quantity 7 as a string
            iSetColor(0,0,0);
            iText(610,224,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==20)
        {
            iSetColor(127,127,127);
            iFilledRectangle(544,168,225,35);
            //taking quantity 8 as a string
            iSetColor(0,0,0);
            iText(610,180,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==21)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,447,205,36);
            //taking product name 1 as a string
            iSetColor(0,0,0);
            iText(340,460,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==22)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,409,205,34);
            //taking product name 2 as a string
            iSetColor(0,0,0);
            iText(340,415,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }

        if(mode==23)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,368,205,36);
            //taking product name 3 as a string
            iSetColor(0,0,0);
            iText(340,376,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        if(mode==24)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,328,205,36);
            //taking product name 4 as a string
            iSetColor(0,0,0);
            iText(340,340,str,GLUT_BITMAP_TIMES_ROMAN_24);


        }

        if(mode==25)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,286,205,36);
            //taking product name 5 as a string
            iSetColor(0,0,0);
            iText(340,295,str,GLUT_BITMAP_TIMES_ROMAN_24);


        }

        if(mode==26)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,249,205,35);
            //taking product name 6 as a string
            iSetColor(0,0,0);
            iText(340,258,str,GLUT_BITMAP_TIMES_ROMAN_24);



        }
        if(mode==27)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,209,205,36);
            //taking product name 7 as a string
            iSetColor(0,0,0);
            iText(340,218,str,GLUT_BITMAP_TIMES_ROMAN_24);



        }
        if(mode==28)
        {
            iSetColor(127,127,127);
            iFilledRectangle(334,169,205,35);
            //taking product name 8 as a string
            iSetColor(0,0,0);
            iText(340,178,str,GLUT_BITMAP_TIMES_ROMAN_24);

        }





        /// Total wil be show all time
        iSetColor(0,0,0);

        iText(832,128,total,GLUT_BITMAP_TIMES_ROMAN_24);



    }






/*=================================================================*/
    /*...................... HISTORY PAGE .........................*/
    /*==================================================================*/
	if(page==7){	
						iClear();
						iShowBMP(0,0,"image\\history.bmp");
						iSetColor(r,g,b);
						iRectangle(390,33,137,25);
					    iText(395,40,"Click to MENU",GLUT_BITMAP_HELVETICA_18);
						iSetColor(0,0,0);
						 iText(478,500,str33,GLUT_BITMAP_HELVETICA_18);
 if(mode==77) 
        {
            iSetColor(0,0,0);
            iText(478,500,str,GLUT_BITMAP_HELVETICA_18);
        }
  iSetColor(0, 0, 0);
        for (int j = 0, y = 560; j<iii; j++, y -= 20)
        {
            iText(65, y, file[j],GLUT_BITMAP_HELVETICA_18);
        }

					
	}




    //::::::::::::::::::::  END OF HISTORY PAGE  ::::::::::::::::::::::


    /*=================================================================*/
    /*...................... ABOUT PAGE .........................*/
    /*==================================================================*/
    if (page==6)
    {
        iClear();
        iShowBMP(0,0,"image\\about.bmp");
    }


}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {


        if(page==0 && mx>=360 && mx<=679 && my>=1 && my<=58)   // start button
        {
            page=1;  // pattern page;

            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        printf("x= %d  y= %d\n",mx,my);


        if(page==1 && p==0 && mx>=436 && mx<=527 && my>=486 && my<=579)  // click on button 2
        {
            p=1;
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==1 && p==1 && mx>=235 && mx<=326 && my>=287 && my<=379) // click on button 4
        {
            p=2;
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==1 && p==2 && mx>=440 && mx<=527 && my>=287 && my<=381) // click on button 5
        {
            p=3;
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==1 && p==3 && mx>=440 && mx<=527 && my>=96 && my<=187) // click on button 8
        {
            p=4;
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==1 && p==4 && mx>=854 && mx<=947 && my>=11 && my<=109) // click on button OK
        {
            page=2;  // menu page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }

        //::::::::::::::::::::::::::::::::::::::::::   pattern click position  :::::::::::::::::::::::::::::::::::::::::::::::::

        if(page==1 && p==0 && mx>=235 && mx<=326 && my>=486 && my<=579/*1*/||page==1 && p==0 && mx>=650 && mx<=723 && my>=486 && my<=573/*3*/ ||page==1 && p==0 && mx>=235 && mx<=326 && my>=287 && my<=379/*4*/||page==1 && p==0 && mx>=440 && mx<=527 && my>=287 && my<=381/*5*/||page==1 && p==0 && mx>=650 && mx<=723 && my>=293 && my<=378/*6*/||page==1 && p==0 && mx>=235 && mx<=326 && my>=96 && my<=187/*7*/ ||page==1 &&p==0 && mx>=440 && mx<=527 && my>=96 && my<=187/*8*/ ||page==1 && p==0 && mx>=650 && mx<=723 && my>=95 && my<=183/*9*/
                || page==1 && p==1 && mx>=235 && mx<=326 && my>=486 && my<=579/*1*/||page==1 && p==1 && mx>=650 && mx<=723 && my>=486 && my<=573/*3*/ ||page==1 && p==1 && mx>=440 && mx<=527 && my>=287 && my<=381/*5*/||page==1 && p==1 && mx>=650 && mx<=723 && my>=293 && my<=378/*6*/||page==1 && p==1 && mx>=235 && mx<=326 && my>=96 && my<=187/*7*/ ||page==1 && p==1 && mx>=440 && mx<=527 && my>=96 && my<=187/*8*/ ||page==1 &&p==1 && mx>=650 && mx<=723 && my>=95 && my<=183/*9*/
                || page==1 && p==2 && mx>=235 && mx<=326 && my>=486 && my<=579/*1*/||page==1 && p==2 && mx>=650 && mx<=723 && my>=486 && my<=573/*3*/ ||page==1 && p==2 && mx>=650 && mx<=723 && my>=293 && my<=378/*6*/||page==1 && p==2 && mx>=235 && mx<=326 && my>=96 && my<=187/*7*/ ||page==1 && p==2 && mx>=440 && mx<=527 && my>=96 && my<=187/*8*/ ||page==1 && p==2 && mx>=650 && mx<=723 && my>=95 && my<=183/*9*/
                || page==1 && p==3 && mx>=235 && mx<=326 && my>=486 && my<=579/*1*/||page==1 && p==3 && mx>=650 && mx<=723 && my>=486 && my<=573/*3*/ ||page==1 && p==3 && mx>=650 && mx<=723 && my>=293 && my<=378/*6*/||page==1 && p==3 && mx>=235 && mx<=326 && my>=96 && my<=187/*7*/ ||page==1 && p==3 && mx>=650 && mx<=723 && my>=95 && my<=183/*9*/
                || page==1 && p==4 && mx>=235 && mx<=326 && my>=486 && my<=579/*1*/||page==1 && p==4 && mx>=650 && mx<=723 && my>=486 && my<=573/*3*/ ||page==1 && p==4 && mx>=650 && mx<=723 && my>=293 && my<=378/*6*/||page==1 && p==4 && mx>=235 && mx<=326 && my>=96 && my<=187/*7*/ ||page==1 && p==0 && mx>=650 && mx<=723 && my>=95 && my<=183/*9*/)
        {
            p=21;  // incorrect pattern page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }

        if(p==21 && mx>=929 && mx<=996 && my>=633 && my<=699) // in pattern page this button is for return
        {
            p=0; //  going to input pattern
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }

        //"""""""""""""""""""""""""""""""""""""""""""""     END of pattern """"""""""""""""""""""""""""""""""""""""""""""//

        //::::::::::::::::::::::::::::::::::::::::::     ADD page ::::::::::::::::::::::::::::::::::::::::::::::::
        if(page==2 && mx>=141 && mx<=353 && my>=465 && my<=550) // add button
        {
            page=3; // add page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }

        if(page==3 && mx>=325 && mx<=870 && my>=448 && my<=515 && mode==0)  // page 3= add product page
        {
            mode=1;  //  taking input  of products name
        }
        if(page==3 && mx>=325 && mx<=870 && my>=325 && my<=385 && mode==0)  // page 3= add product page
        {
            mode=2;  //  taking input of quantity
        }

        
        if(page==3 && mx>=390 && mx<=527 && my>=33 && my<=58) // inside of add page going back to menu page.  :::::: click to menu:::::::::
        {

            page=2;  // menu page

            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }





        // """"""""""""""""""""""""""""""""   END add page """"""""""""""""""""""""""""""""""""""""""""""""""




        ///::::::::::::::::::::: DELETE PAGE  :::::::::::::::::::::::::::::::::::::::::::::::::::::




        if(page==2 && mx>=527 && mx<=741 && my>=465 && my<=547)  // page 2= menu page
        {
            page=4;   // page 4=delete page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==4 && mx>=390 && mx<=527 && my>=33 && my<=58) // inside of delete page going back to menu page.  :::::: click to menu:::::::::
        {
            page=2;  // menu page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }

        if(page==4 && mx>=619 && mx<=855 && my>=352 && my<=420 && input==0)
        {
            mode=50;
        }
		




        //:::::::::::::::::::::::::::::: MEMO page :::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

        if(page==2 && mx>=140 && mx<=358 && my>=322 && my<=404)  // memo button
        {
            k=1;
            page=5;  // memo page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==5 && mx>=776 && mx<=927 && my>=587 && my<=634 && mode==0)  // page 5= memo page
        {
            mode=4;  //  taking input of date in memo page
        }
		if(page==5 && mx>=776 && mx<=927 && my>=552 && my<=581 && mode==0)  // page 5= memo page
        {
            mode=44;  //  taking input of time in memo page
        }


        if(page==5 && mx>=773 && mx<=927 && my>=448 && my<=490 && mode==0)  //  page 5= memo page
        {
            mode=5;  //  taking input of price 1
        }

        if(page==5 && mx>=772 && mx<=928 && my>=410 && my<=448 && mode==0)  //  page 5= memo page
        {
            mode=6;  //  taking input of price 2
        }

        if(page==5 && mx>=773 && mx<=929 && my>=368 && my<=411 && mode==0)  //  page 5= memo page
        {
            mode=7;  //  taking input of price 3
        }

        if(page==5 && mx>=773 && mx<=929 && my>=328 && my<=369 && mode==0)  //  page 5= memo page
        {
            mode=8;  //  taking input of price 4
        }

        if(page==5 && mx>=773 && mx<=931 && my>=291 && my<=328 && mode==0)  //  page 5= memo page
        {
            mode=9;  //  taking input of price 5
        }

        if(page==5 && mx>=773 && mx<=928 && my>=250 && my<=290 && mode==0)  //  page 5= memo page
        {
            mode=10;  //  taking input of price 6
        }

        if(page==5 && mx>=773 && mx<=929 && my>=207 && my<=251 && mode==0)  //  page 5= memo page
        {
            mode=11;  //  taking input of price 7
        }

        if(page==5 && mx>=773 && mx<=927 && my>=171 && my<=207 && mode==0)  //  page 5= memo page
        {
            mode=12;  //  taking input of price 8
        }
        ///input of quantity

        if(page==5 && mx>=545 && mx<=770 && my>=450 && my<=488 && mode==0)  //  page 5= memo page
        {
            mode=13;  //  taking input of quantity 1
        }

        if(page==5 && mx>=545 && mx<=770 && my>=410 && my<=448 && mode==0)  //  page 5= memo page
        {
            mode=14;  //  taking input of quantity 2
        }
        if(page==5 && mx>=545 && mx<=773 && my>=368 && my<=411 && mode==0)  //  page 5= memo page
        {
            mode=15;  //  taking input of quantity 3
        }
        if(page==5 && mx>=545 && mx<=773 && my>=330 && my<=368 && mode==0)  //  page 5= memo page
        {
            mode=16;  //  taking input of quantity 4
        }
        if(page==5 && mx>=545 && mx<=773 && my>=288 && my<=330 && mode==0)  //  page 5= memo page
        {
            mode=17;  //  taking input of quantity 5
        }

        if(page==5 && mx>=545 && mx<=773 && my>=249 && my<=288 && mode==0)  //  page 5= memo page
        {
            mode=18;  //  taking input of quantity 6
        }
        if(page==5 && mx>=545 && mx<=773 && my>=214 && my<=249 && mode==0)  //  page 5= memo page
        {
            mode=19;  //  taking input of quantity 7
        }
        if(page==5 && mx>=545 && mx<=773 && my>=172 && my<=214 && mode==0)  //  page 5= memo page
        {
            mode=20;  //  taking input of quantity 8
        }





        if(page==5 && mx>=330 && mx<=540 && my>=450 && my<=487 && mode==0)  //  page 5= memo page
        {
            mode=21;  //  taking input of product name 1
        }

        if(page==5 && mx>=333 && mx<=541 && my>=410 && my<=452 && mode==0)  //  page 5= memo page
        {
            mode=22;  //  taking input of product name 2
        }

        if(page==5 && mx>=333 && mx<=541 && my>=370 && my<=410 && mode==0)  //  page 5= memo page
        {
            mode=23;  //  taking input of product name 3
        }

        if(page==5 && mx>=333 && mx<=541 && my>=330 && my<=370 && mode==0)  //  page 5= memo page
        {
            mode=24;  //  taking input of product name 4
        }
        if(page==5 && mx>=333 && mx<=541 && my>=289 && my<=330 && mode==0)  //  page 5= memo page
        {
            mode=25;  //  taking input of product name 5
        }

        if(page==5 && mx>=333 && mx<=540 && my>=248 && my<=289 && mode==0)  //  page 5= memo page
        {
            mode=26;  //  taking input of product name 6
        }
        if(page==5 && mx>=333 && mx<=540 && my>=210 && my<=248 && mode==0)  //  page 5= memo page
        {
            mode=27;  //  taking input of product name 7
        }
        if(page==5 && mx>=333 && mx<=540 && my>=171 && my<=209 && mode==0)  //  page 5= memo page
        {
            mode=28;  //  taking input of product name 8
        }





        if(page==5 && mx>=390 && mx<=527 && my>=2 && my<=27) //  page 5= memo page.  :::::: click to menu:::::::::
        {
            page=2;  // menu page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==5 && mx>=70 && mx<=327 && my>=489 && my<=545  ) // store
        {


            FILE *fp = fopen("ProductsName.txt", "r");
            while (fscanf(fp, "%s", &file[ii]) != EOF)
            {
                printf("%s\n", file[ii]);
                ii++;
            }
            fclose(fp);

            FILE * fPtr;
            fPtr = fopen("ProductsPrice.txt", "r");
            while (fscanf(fp, "%s", &filepr[pr]) != EOF)
            {
                printf("%s\n", filepr[pr]);
                pr++;
            }
            fclose(fPtr);
        }





       //:::::::::::::::::::::::::::::: HISTORY PAGE :::::::::::::::::::::::::
		if(page==2 && mx>=528 && mx<=740 && my>=322 && my<=405)
		{
		page=7;
		PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
		}
		if(page==7 && mx>=390 && mx<=527 && my>=33 && my<=58) // inside of history :::::: click to menu:::::::::
        {
            page=2;  // menu page
           PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
		if(page==7 && mx>=243 && mx<=675 && my>=444 && my<=520 && mode==0)
		{
		mode=77;
		PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
		}



        // ::::::::::::::::::::::   ABOUT PAGE  :::::::::::::::::::::::::::::::

        if(page==2 && mx>=145 && mx<=353 && my>=179 && my<=263) // about button
        {
            page=6; // about page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        if(page==6 && mx>=929 && mx<=989 && my>=632 && my<=962)  // about page er back button
        {
            page=2; // menu page
            PlaySound("sound\\Keyboard-Button.wav",NULL,SND_ASYNC);
        }
        //:::::::::::::::::::::::::::::::::  END OF ABOUT PAGE::::::::::::::::::::::::::::



        if(page==2 && mx>=530 && mx<=711 && my>=179 && my<=263)  // exit button
        {
            exit(0);
        }


        /* if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
         {

         }*/
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {

        }
    }
}

void iPassiveMouseMove(int mx,int my)
{
    mposx = mx;
    mposy = my;
    if(mx== 2) {}
    else if(my== 2) {}
}

void iKeyboard(unsigned char key)
{
    int i;
    if(mode==1)
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            printf("%s\n",str2);
            FILE * fPtr;
            fPtr = fopen("ProductsName.txt", "a");
            fprintf(fPtr,"\n",str2);
            fputs(str2, fPtr);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;

            fclose(fPtr);
        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }



    if(mode==2)
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str3,str);
            printf("%s\n",str3);
            FILE * fPtr;
            fPtr = fopen("ProductsPrice.txt", "a");
            fprintf(fPtr,"\n",str3);
            fputs(str3, fPtr);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;

            fclose(fPtr);
        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


  

    if(mode==50)    // page =4 delete , input option


    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            printf("%s\n",str2);

            for(i=0; i<len; i++)
                str[i]=0;
            len=0;

						//:::::::::::::::::::::::::delete from a line::::::::::::::::::::

						//char filename[100];
						char stri[100];

						FILE *fp1, *fp2;
						int del_line_no;
						int line_no=0;

						//printf("enter the file name : \n");
						//scanf("%s" ,filename);

						fp1= fopen("ProductsName.txt","r");
						//printf("\ncontent of the file before modification : \n");
						//print_file(fp1);
						//rewind(fp1);


						del_line_no=atoi(str2);
						//printf("\nEnter the number of the line to be deleted : \n");
						//scanf("%d",&del_line_no);
						fp2=fopen("replica.txt","w");

						while(fgets(stri, 99, fp1) != NULL)
						{
							line_no++;

							if(line_no != del_line_no)
							{
								fputs(stri,fp2);
							}
						}

						fclose(fp1);
						fclose(fp2);

						remove("ProductsName.txt");
						rename("replica.txt", "ProductsName.txt");

						

						fp1= fopen("ProductsName.txt","r");
						//printf("\ncontent of the file after modification : \n");
						print_file(fp1);
						fclose(fp1);





        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }



    }



    if(mode==4)  // date
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str22,str);
            printf("%s\n",str22);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;
            char txt[70]= {"                                    .txt"}; // for this blank space .txt will not show on memo page


            strcat(str22,txt);
            FILE *fp1;
            fp1 = fopen(str22,"w");
            fclose(fp1);

        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }
	 if(mode==44) // time
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str222,str);
            printf("%s\n",str222);

           
            FILE *fp1;
            fp1 = fopen(str22,"a");
            
            fputs(str222, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {
            --len;
            str[len]=key;
        }
        else
        {
            str[len]=key;
            len++;
        }

    }




    if(mode==5) // price 1 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str5,str);
            printf("%s\n",str5);

            price_1=atoi(str5);
            FILE *fp1;
            fp1 = fopen(str22,"a");

            fprintf(fp1,"______________",price_1);
            fputs(str5, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==6) ///price 2 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str6,str);
            printf("%s\n",str6);

            price_2=atoi(str6);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",price_2);
            fputs(str6, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==7) ///price 3 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str7,str);
            printf("%s\n",str7);

            price_3=atoi(str7);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",price_3);
            fputs(str7, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==8) ///price 4 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str8,str);
            printf("%s\n",str8);

            price_4=atoi(str8);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",price_4);
            fputs(str8, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==9) ///price 5 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str9,str);
            printf("%s\n",str9);

            price_5=atoi(str9);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",price_5);
            fputs(str9, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==10) ///price 6 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str10,str);
            printf("%s\n",str10);

            price_6=atoi(str10);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",price_6);
            fputs(str10, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==11) ///price 7 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str11,str);
            printf("%s\n",str11);

            price_7=atoi(str11);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",price_7);
            fputs(str11, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==12) ///price 8 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str12,str);
            printf("%s\n",str12);

            price_8=atoi(str12);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",price_8);
            fputs(str12, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==13) ///quantity 1 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str13,str);
            printf("%s\n",str13);
            q1=atoi(str13);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q1);
            fputs(str13, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==14) ///quantity 2 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str14,str);
            printf("%s\n",str14);

            q2=atoi(str14);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q2);
            fputs(str14, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==15) ///quantity 3 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str15,str);
            printf("%s\n",str15);

            q3=atoi(str15);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q3);
            fputs(str15, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==16) ///quantity 4 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str16,str);
            printf("%s\n",str16);

            q4=atoi(str16);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q4);
            fputs(str16, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }
    if(mode==17) ///quantity 5 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str17,str);
            printf("%s\n",str17);

            q5=atoi(str17);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q5);
            fputs(str17, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==18) ///quantity 6 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str18,str);
            printf("%s\n",str18);

            q6=atoi(str18);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q6);
            fputs(str18, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==19) ///quantity 7 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str19,str);
            printf("%s\n",str19);

            q7=atoi(str19);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q7);
            fputs(str19, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==20) ///quantity 8 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str20,str);
            printf("%s\n",str20);

            q8=atoi(str20);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"______________",q8);
            fputs(str20, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==21) ///product name 1 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str23,str);
            printf("%s\n",str23);


            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n",str23);
            fputs(str23, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==22) ///product name 2 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str24,str);
            printf("%s\n",str24);


            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n",str24);
            fputs(str24, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==23) ///product name 3 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str25,str);
            printf("%s\n",str25);


            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n",str25);
            fputs(str25, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==24) ///product name 4 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str26,str);
            printf("%s\n",str26);


            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n",str26);
            fputs(str26, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==25) ///product name 5 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str27,str);
            printf("%s\n",str27);


            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n",str27);
            fputs(str27, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }


    if(mode==26) ///product name 6 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str28,str);
            printf("%s\n",str28);


            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n",str28);
            fputs(str28, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==27) ///product name 7 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str29,str);
            printf("%s\n",str29);

            q8=atoi(str29);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n",q8);
            fputs(str29, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }

    if(mode==28) ///product name 8 input in memo page
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str30,str);
            printf("%s\n",str30);

            q8=atoi(str30);
            FILE *fp1;
            fp1 = fopen(str22,"a");
            fprintf(fp1,"\n______________",q8);
            fputs(str30, fp1);

            fclose(fp1);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;


        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }






















    //::::::::::::::::::::::  HISTORY PAGE :::::::::::::::::::::::::::::

     if(mode==77)  // input date to search  
    {
        if (key=='\r')
        {
            mode=0;
            strcpy(str33,str);
            printf("%s\n",str33);
            for(i=0; i<len; i++)
                str[i]=0;
            len=0;
             char txt[70]= {"                                    .txt"};
            strcat(str33,txt);
            FILE *fp2;
            fp2 = fopen(str33,"r");
			  while (fscanf(fp2, "%s", &file[iii]) != EOF)
            {
                printf("%s\n", file[iii]);
                iii++;
            }
            fclose(fp2);

        }
        if(key=='\b')
        {

            --len;
            str[len]=key;

        }
        else
        {
            str[len]=key;
            len++;

        }

    }





    

}

void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }

}
int main()
{
    len =0;
    mode=0;
    input=0;
    str[0]=0;
    p=0;
    page=0;
    if(musicOn)
    {
        PlaySound("sound\\Windows_95_Startup-Microsoft.wav",NULL,SND_ASYNC);
    }

    iSetTimer(20,change);
    fileRead();

    ProductsQuantityfileRead();

    iInitialize(1000,700, "Cash Memo");
    return 0;
}


