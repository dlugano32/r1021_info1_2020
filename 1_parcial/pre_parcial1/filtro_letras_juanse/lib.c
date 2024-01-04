#include "lib.h"

char voc(char letra)
{
       char(*abc[26])()={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
       if(letra>64&&letra<91)
       {
              return (abc[(letra-65)]());
       }
       else if(letra>96&&letra<123)
       {
              return (abc[(letra-97)]());
       }
       else
       {
              return 0;
       }
       
}

char con(char letra)
{
       char(*abc[26])()={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
       if(letra>64&&letra<91)
       {
              return (1-abc[(letra-65)]());
       }
       else if(letra>96&&letra<123)
       {
              return (1-abc[(letra-97)]());
       }
       else
       {
              return 0;
       }   
}

char a()
{return 1;}         
char b()
{return 0;}           
char c()
{return 0;} 
char d()
{return 0;}         
char e()
{return 1;}           
char f()
{return 0;} 
char g()
{return 0;}         
char h()
{return 0;}           
char i()
{return 1;}
char j()
{return 0;}         
char k()
{return 0;}           
char l()
{return 0;} 
char m()
{return 0;}        
char n()
{return 0;}           
char o()
{return 1;} 
char p()
{return 0;}         
char q()
{return 0;}           
char r()
{return 0;}
char s()
{return 0;}         
char t()
{return 0;}            
char u()
{return 1;}
char v()
{return 0;}         
char w()
{return 0;}           
char x()
{return 0;}
char y()
{return 0;}         
char z()
{return 0;}