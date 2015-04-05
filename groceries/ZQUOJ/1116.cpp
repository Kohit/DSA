#include<stdio.h>
#include<string.h>
int main()
{
   char zw[24][3]={"°¡","°Å","²Á","´î","¶ê","·¢","¸Á","¹þ","»÷","¿¦","À¬","Âè","ÄÃ","Å¶","Å¾","ÆÚ","È»","Èö","Ëú","ÍÚ","Îô","Ñ¹","ÔÑ"};
   char zimu[24]={'a','b','c','d','e','f','g','h','j','k','l','m','n','o','p','q','r','s','t','w','x','y','z'};
   char s[100][102];
   char py[100][102];
   char ch[3];
   int n;
   scanf("%d",&n);
   for(int i = 0; i < n; i++)
   {
	   scanf("%s",s[i]);
   }
   for(int i = 0; i < n; i++)
   {
	   int j = 0;
	   for(j = 0; s[i][j] != '\0'; j = j + 2)
	   {
           ch[0] = s[i][j];
		   ch[1] = s[i][j + 1];
		   ch[2] = '\0';
		   int k = 0;
		   for(k = 0; k < 22; k++)
		   {
			   if(strcmp(ch,zw[k]) >=0 &&strcmp(ch,zw[k+1]) < 0)
				   break;
		   }
           py[i][j/2] = zimu[k];
	   }
	   py[i][j/2] = '\0';
   }
   for(int i = 0; i < n; i++)
   {
	   for(int j = 0; py[i][j] != '\0'; j++)
	   {
		   printf("%c",py[i][j] - 32);
	   }
	   printf("\n");
   }
   return 0;
}
