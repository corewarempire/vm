if [[ $# -eq 1 ]]; then
	./asm $1 && make && ./corewar $1 
fi
if [[ $# -eq 2 ]]; then
	./asm $1 && ./asm $2 && make && ./corewar $1 $2
fi
