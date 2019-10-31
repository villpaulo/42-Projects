
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
