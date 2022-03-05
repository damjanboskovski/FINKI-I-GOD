#include<stdio.h>

int main(){
    int br, bank1 = 0, bank2= 0 , bank5 = 0, bank10 = 0, bank50 = 0, bank100 = 0, bank500 = 0, bank1000 = 0, bank5000 = 0;
    scanf("%d", &br);

    if(br >= 5000){
        bank5000 = br/5000;
        br = br - bank5000 * 5000;}
    if(br >= 1000){
        bank1000 = br/1000;
        br = br - bank1000 * 1000;}
    if(br >= 500){
        bank500 = br/500;
        br = br - bank500 * 500;}
    if(br >= 100){
        bank100 = br/100;
        br = br - bank100 * 100;}
    if(br >= 50){
        bank50 = br/50;
        br = br - bank50 * 50;}
    if(br >= 10){
        bank10 = br/10;
        br = br - bank10 * 10;}
    if(br >= 5){
        bank5 = br/5;
        br = br - bank5 * 5;}
    if(br >= 2){
        bank2 = br/2;
        br = br - bank2 * 2;}
    if(br >= 1){
        bank1 = br/1;
        br = br - bank1 * 1;}       

    printf("%d*5000\n",bank5000);
    printf("%d*1000\n",bank1000);
    printf("%d*500\n",bank500);
    printf("%d*100\n",bank100);
    printf("%d*50\n",bank50);
    printf("%d*10\n",bank10);
    printf("%d*5\n",bank5);
    printf("%d*2\n",bank2);
    printf("%d*1\n",bank1);

    return 0;
}