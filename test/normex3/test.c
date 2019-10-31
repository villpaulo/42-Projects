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
}

int		main()
{
	toto *var
	int *fdtest;

	var->ptr_s32_tab = (int *)malloc(sizeof(int) * 6);

	var->ptr_s32_tab[0] = 1;
	var->ptr_s32_tab[1] = 1;
	var->ptr_s32_tab[2] = 1;
	var->ptr_s32_tab[3] = 1;
	var->ptr_s32_tab[4] = 1;
	var->ptr_s32_tab[5] = 1;

	var.u8_index_memory = 32;
	var.index_right = 42;

	*fdtest = open("toto.JSON", O_CREAT | O_WRONLY | O_TRUNC, 0644);

}

