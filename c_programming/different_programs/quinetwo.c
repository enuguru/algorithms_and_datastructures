#include <stdio.h>
char str[] = "#include <stdio.h>%cchar str[] = %c%s%c;%cint main() {%c    printf(str, 10, 34, str, 34, 10, 10, 10);%c}";
int main() {
	printf(str, 10, 34, str, 34, 10, 10, 10);
}