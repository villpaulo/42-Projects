#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

uint8_t		Fu8__search_median(int32_t *ptr_s32_pssd_tab, uint8_t u8_pssd_tab_size, int32_t *s32_pssd_median)//
{																									    //
    /**
    *   I protect the function : Return 1 for false if the variable passed in argument is NULL or the size is equal to ZERO
    */
	if (u8_pssd_tab_size == 0)																			//
		{																							    //
				return (1);																				//
		}																							    //
	else																							    //
		{																							    //
		/**
		*i keep the else here, for debugging and print something if the size of tab equal 0
		*/
		;																							    //
		}																								//
	if (ptr_s32_pssd_tab == NULL)																		//
		{																								//
				return (1);																				//
		}																								//
	else																								//
		{																								//
		/**
		* i keep the else, for debugging and print something if the array equal NULL
		*/
		;																								//
		}																								//
	uint8_t		u8_lcl_tab_index;																		//
																										//
	u8_lcl_tab_index = 0;																		//
	while (u8_lcl_tab_index < u8_pssd_tab_size)															//
		{																							    //
			*s32_pssd_median = *s32_pssd_median + (ptr_s32_pssd_tab[u8_lcl_tab_index] / (u8_pssd_tab_size));
			u8_lcl_tab_index++;																				//
		}																							    //
																										//
	/**
	*	i printf the Minimum value of the array and the index of this one, and i do same thing for the Maximum value of the array
	*/
	printf(" med value = %d\n", *s32_pssd_median);
	return (0);																					    //
}																										//

int			main()
{
	int32_t tab[4] = {32, -42, 3, 21};
	int ret;

	Fu8__search_median(tab, 4, &ret);
	printf("%d\n", ret);
	return (0);
}
