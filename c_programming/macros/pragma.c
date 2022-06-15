#include<stdio.h>
#include<conio.h>
void func() ;
#pragma unpack
#pragma startup func
#pragma exit func
void func(){
printf("\n Simple statement for a pragma directive.");
getch();
}
void main(){
printf("\n This is a sample to test pragma directive.");
getch();
}
