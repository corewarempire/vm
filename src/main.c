#include "../inc/corewar.h"

t_board *init_board_data(t_board *bd, char **argv)
{ 
	int i;

	i = 0;
	if (!(bd = (t_board *)malloc(sizeof(t_board))))
		ft_error(0);
	bd->ram = ft_memalloc_c(MEM_SIZE, 0);
	bd->champions_count = 0;
	while (argv[++i])
		if (ft_strlen(argv[i]) >= 5 &&
				ft_strcmp(argv[i] + ft_strlen(argv[i]) - 4, ".cor") == 0)
			bd->champions_count++;
	if (bd->champions_count > 4 || bd->champions_count < 1)
		ft_error(1);
	bd->opt_list = NULL;
	bd->first_champ = NULL;
	bd->cycle = 0;
	bd->id_process = 0;
	bd->dump = -1;
	bd->total_cycle_live = 0;
	bd->check_nbr = 0;
	return (bd);
}

int main(int argc, char **argv)
{
	t_board  *board;

	if (argc < 2)
		ft_error(1);
	board = init_board_data(board, argv);
	collect_inputs(argv, argc, board);
	insert_instructions(board);
	print_champ_lst(board);
	// print_memory(board);
	//play(board);
	//print_memory(board);
	printf("Le champion gagnant:%d\n", board->last_live);
	return (0);
}
