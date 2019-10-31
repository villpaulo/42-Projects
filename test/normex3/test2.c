#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>


struct		toto
{
	int32_t *ptr_s32_tab;
	uint8_t u8_index_memory;
	uint8_t index_right;
};

int		main()
{
	//toto var;
	int  fd;
	FILE *fichier;
	char *str;

	str = "jaime lveau\n";
	fichier = NULL;
	printf("ici nono\n");
	fichier = fopen("toto2.JSON", "wrx");
	printf("ici \n");
	int i = 42;
	int a = 42;

	/*var.ptr_s32_tab = (int *)malloc(sizeof(int) * 6);

	var.ptr_s32_tab[0] = 1;
	var.ptr_s32_tab[1] = 1;
	var.ptr_s32_tab[2] = 1;
	var.ptr_s32_tab[3] = 1;
	var.ptr_s32_tab[4] = 1;
	var.ptr_s32_tab[5] = 1;
	var.u8_index_memory = 32;
	var.index_right = 42;*/

	printf("ici1 \n");
	fd = open("toto.JSON", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	printf("ici2 \n");
	//fwrite(&i, sizeof(i), 1, fichier);
	fwrite(&i, sizeof(i), 1, fichier);
	write(fd,"a", 1);
	write(fd, &a, 2);
	//fprintf(fichier, "%d\n", i);
	printf("ici3 \n");
	return (0);
}
