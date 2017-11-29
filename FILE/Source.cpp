#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

int main()
{
	int i, n, c=0, e=0;
	char s[200];
	FILE *fp, *cez;
	setlocale(LC_CTYPE, ".1251");
	cez = fopen("test1.txt", "w");
	fclose(cez);
	while (c != 2)
	{
		i = 0;
		printf("Кодировка Цезаря\nЖелаемый сдвиг для шифрования: ");
		scanf("%d", &n);
		fp = fopen("test.txt", "r");
		cez = fopen("test1.txt", "a");
		while (fgets(s, 200, fp) != NULL)
		{
			i++;
			printf("Текст до кодировки\n%s", s);
		}
		fclose(fp);
		printf("\nЗакодированный текст\n");
		while (s[i] != NULL && i != 200)
		{
			printf("%c", s[i] + n);
			putc(int(s[i] + n), cez);
			i++;
		}
		putc(10, cez);
		fclose(cez);
		printf("\nВведите 1 для повторного кодирования или 2, чтобы завершить программу ");
		do { scanf("%d", &c); } while (c!=1&&c != 2);
		printf("\n");
	}
		return 0;
}
