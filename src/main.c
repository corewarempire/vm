#include "../inc/corewar.h"

int init_board_data(t_board **bd, char **argv)
{ 
	int i;

	i = 0;
	if (!((*bd) = (t_board *)malloc(sizeof(t_board))))
		return (ft_error(1, 0));
	(*bd)->champions_count = 0;
	(*bd)->opt_list = NULL;
	(*bd)->lst_process = NULL;
	(*bd)->ram = NULL;
	(*bd)->verbose = NULL;
	(*bd)->first_champ = NULL;
	(*bd)->cycle = 0;
	(*bd)->id_process = 0;
	(*bd)->dump = -1;
	(*bd)->total_cycle_live = 0;
	(*bd)->check_nbr = 0;
	while (argv[++i])
		if (ft_strlen(argv[i]) >= 5
			&& !ft_strcmp(argv[i] + ft_strlen(argv[i]) - 4, ".cor"))
			(*bd)->champions_count++;
	if ((*bd)->champions_count > 4 || (*bd)->champions_count < 1)
		return(ft_error(6, 0));
	if (!((*bd)->ram = ft_memalloc_c(MEM_SIZE, 0)))
		return (ft_error(1, 0));
	if (!((*bd)->verbose = ft_memalloc(5)))
		return (ft_error(1, 0));
	return (1);
}

int	error_management(t_board *fucked_board, int errno)
{
	memclear(fucked_board);
	printf("ERROR MANAGEMENT MESSAGE LEAKS TO ERASE ERROR\n");
	return (-1);
}

int main(int argc, char **argv)
{
	t_board  *board;

	board = NULL;
	if (argc < 2)
	{
		ft_usage();
		return (0);
	}
	if (!(init_board_data(&board, argv)) ||
			!collect_inputs(argv, argc, board) ||
			!insert_instructions(board))
		return (error_management(board, 0));
	 if (board->verbose[0])
		print_champ_lst(board);
	play(board);
	//printf("Le champion gagnant:%d\n", board->last_live);
	if (board->verbose[4])
		print_memory(board, 0);
	memclear(board);
	return (0);
}
