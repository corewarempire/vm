#include "corewar.h"

void	ld(t_board *bd, t_process *proc)
{
	unsigned int	pc;
	unsigned int	octal;
	unsigned int	offset;
	int				reg;
	int				val1;

	pc = proc->pc;
	octal = ocp_first(bd->ram[MEM_MOD(pc + 1)]);
	val1 = (octal == DIR_CODE) ? get_dir4(bd, pc + 2) : get_indir(bd, proc, pc + 2);
	offset = (octal == DIR_CODE) ? 6 : 4;
	reg = bd->ram[MEM_MOD(pc + offset)];
	proc->carry = (!(proc->r[reg - 1] = val1)) ? 1 : 0;
	proc->pc += offset + 1;
	if (!bd->verbose[1])
		return ;
	ft_putstrnbrstr("Player ", proc->id_player, " // Process ");
	ft_putnbrstrnbr(proc->id_process, "\nLd ", val1);
	ft_putstrnbrstr(" in r", bd->ram[MEM_MOD(proc->pc) - 1], ". Carry : ");
	ft_putnbr(proc->carry);
	ft_putstr("\n\n");
}