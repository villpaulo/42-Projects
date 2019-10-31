#include "ex3.h"
#include <stdint.h>

uint8_t		Fu8__search_median(int32_t *ptr_s32_pssd_tab, uint8_t u8_pssd_tab_size, int32_t *s32_pssd_median)//
{																									    //
	if (u8_pssd_tab_size == 0)																			//
		{																							    //
				return (1);																				//
		}																							    //
	else																							    //
		{																							    //
		;																							    //
		}																								//
	if (ptr_s32_pssd_tab == NULL)																		//
		{																								//
				return (1);																				//
		}																								//
	else																								//
		{																								//
		;																								//
		}																								//
	uint8_t		u8_lcl_tab_index;																		//
																										//
	u8_lcl_tab_index = 0;																				//
	while (u8_lcl_tab_index < u8_pssd_tab_size)															//
		{																							    //
			*s32_pssd_median = *s32_pssd_median + (ptr_s32_pssd_tab[u8_lcl_tab_index] / (u8_pssd_tab_size));//
			u8_lcl_tab_index++;																			//
		}																							    //
	return (0);																						    //
}

uint8_t			Fu8__check_array_order(int32_t	*ptr_s32_pssd_tab, uint8_t u8_tab_size)
{
	uint8_t		u8_index;
	uint8_t		u8_compare;

	u8_index = RESET_TO_ZERO(u8_index);
	u8_compare = RESET_TO_ZERO(u8_compare);
	u8_index = 1;
	u8_compare = 0;
	while (u8_index <= u8_tab_size)
		{
			if (u8_index > 0)
				{
				u8_compare = ptr_s32_pssd_tav[u8_index - 1];
				}
			else
			{
			;
			}
			if (ptr_s32_pssd_tab[u8_index] < u8_compare)
				{
				return (1);
				break;
				}
			u8_index++;
		}
	return (0);
}

void		Fv__swap(int *ptr_s32_tab, uint8_t u8_tab_elem1, uint8_t u8_tab_elem2)
{
	ptr_s32_tab[u8_tab_elem1] = ptr_s32_tab[u8_tab_elem1] ^ ptr_s32_tab[u8_tab_elem2];
	ptr_s32_tab[u8_tab_elem2] = ptr_s32_tab[u8_tab_elem1] ^ ptr_s32_tab[u8_tab_elem2];
	ptr_s32_tab[u8_tab_elem1] = ptr_s32_tab[u8_tab_elem2] ^ ptr_s32_tab[u8_tab_elem1];
}


void		Fv__quick_sort(uint8_t u8_tab_size, int32_t	*stc_pssd_var)
{
	stc_var		*stc_lcl_var;
	uint8_t		u8_use_backup;

	u8_use_backup = RESET_TO_ZERO(u8_use_backup);
	stc_lcl_var = NULL;
	u8_use_backup = 1;

	Fv_create_stc(stc_lcl_var, u8_use_backup);
	if (stc_lcl_var->ptr_s32_tab == NULL)
		{
		stc_lcl_var->ptr_s32_tab = stc_pssd_var;
		}
	else
		{
		;
		}
	if (stc_var->ptr_s32_pssd_tab == NULL)
		{
			return (FAILURE);
		}
	else
		{
		;
		}
	if (u8_tab_size == 0)
		{
			return (FAILURE);
		}
	else
		{
		;
		}
		Fv__sort(stc_lcl_var->ptr_s32_tab, stc_lcl_var->u8_index_left, stc_lcl_var->u8_index_right);
}

void		Fv__sort(int32_t *ptr_s32_tab, int16_t s16_pssd_left, uint8_t u8_pssd_right)
{
	if (s16_pssd_left >= u8_pssd_right)
		{
			return;
		}
	else
		{
		;
		}
	int32_t		s32_lcl_pivot;
	uint8_t		u8_lcl_boolean;
	uint8_t		u8_lcl_tmp;

	u8_lcl_tmp = RESET_TO_ZERO(u8_lcl_tmp);
	u8_boolean = RESET_TO_ZERO(u8_boolean):
	u8_lcl_tmp = u8_pssd_right;
	s16_pssd_left = s16_pssd_left - 1;
	u8_pssd_right = u8_pssd_right + 1;
	u8_boolean = Fu8__check_array_order(stc_var->ptr_s32_pssd_tab, u8_tab_size)

	if (u8_lcl_boolean == 0)
		{
		return;
		}
	else
		{
		;
		}
	s32_lcl_pivot = Fu8__search_median( )

		/*if (s16_pssd_left >= u8_pssd_right)
			{
			u8_pssd_right--;
			}
		else										POURQUOI?
			{
			;
			}*/
	while (s16_pssd_left < u8_pssd_right)
		{
		u8_pssd_right--;
		while (ptr_s32_tab[u8_pssd_right] > s32_lcl_pivot)
			{
			u8_pssd_right--;
			}
		s16_pssd_left++;
		while (ptr_s32_tab[s16_pssd_left] < s32_lcl_pivot)
			{
			s16_pssd_left++;
			}
		if (s16_pssd_left < u8_pssd_right)
			{
			Fv_swap(ptr_s32_tab, s16_pssd_left, u8_pssd_right);
			}
		else
			{
			;
			}
		}
		serialize(ptr_s32_tab, u8_pssd_right, u8_lcl_tmp);
		Fv__sort(ptr_s32_tab, 0, u8_pssd_right);
		Fv__sort(ptr_s32_tab, u8_pssd_right + 1, u8_lcl_tmp);
		return	;
}
