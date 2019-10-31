#include "ex3.h"

void			Fv__initialize_stc_provisory(stc_var *var)
{
	stc_var->s16_index_left = RESET_TO_ZERO(stc_var->u8_pssd_index_left);
	stc_var->u8_index_right = RESET_TO_ZERO(stc_var->u8_pssd_index_right);
	stc_var->ptr_s32_tab = NULL;
}

uint8_t			Fu8__new_file(char *filename, int8_t *ptr_s8_fd)
{
	*ptr_s8_fd = RESET_TO_ZERO(ptr_s8_fd);
	*ptr_s8_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*ptr_s8_fd == -1)
		{
			return (FAILURE);
		}
	else
		{
			return (SUCCESS);
		}
}

void		Fv__create_stc(stc_var *stc_pssd_var, uint8_t u8_use_backup)
{
	/*if (u8_use_backup == 0)
		{

		}*/
	int8_t s8_fd;

	s8_fd = 0;
	s8_fd = open("fichier.JSON", O_RDONLY);
	if (s8_fd == -1)
		{
		Fv__initialize(stc_pssd_var);
		return ;
		}
	else
		{
		/**
		 * deserialize
		 */
		}
}

void		serialize(int32_t	*ptr_s32_pssd_tab, uint8_t u8_pssd_right, uint8_t u8_pssd_end)
{

}

int			main()
{
	int32_t		ptr_s32_lcl_test[8];

	ptr_s32_lcl_test[8] = {10, -1982, 0, 0, 0, 54, 10, 97};
	Fv__quick_sort(8, ptr_s32_lcl_test);
	return (0);
}

