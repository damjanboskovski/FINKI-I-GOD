#include<stdio.h>
int main(){
  int d,m,g;
  scanf("%3d",&d); scanf("%3d",&m); scanf("%5d",&g);

  if(m>=1 && m<=12){
    if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)){ 
      printf("1\n"); 
    }
    else if ((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11)){
      printf("1\n");
    }
    else if((d>=1 && d<=28) && (m==2)){
      printf("1\n");
    }
    else if (d==29 && m==2 && (g%400==0 ||(g%4==0 && g%100!=0))){
      printf("1\n");
      }
    else{ printf("0\n"); }
  }
  else{ printf("0\n"); }
  return 0;
}