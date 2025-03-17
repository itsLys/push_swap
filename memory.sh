#!/bin/bash

shopt -s expand_aliases

# alias vg_leak="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42"
# alias vg_mem="valgrind --expensive-definedness-checks=yes --error-exitcode=42"
alias vg_all="valgrind --expensive-definedness-checks=yes --show-reachable=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes  --error-exitcode=42"



alias basic_1="vg_all ./push_swap"                          # No input
alias basic_2="vg_all ./push_swap 1 2 3"                   # Sorted input
alias basic_3="vg_all ./push_swap 3 2 1"                   # Reverse-sorted input
alias basic_4="vg_all ./push_swap 1 3 2"                   # Unsorted input
alias basic_5="vg_all ./push_swap 1 3 2 \"\""              # Empty string in input
alias basic_6="vg_all ./push_swap 1 3 2 \"\" 5 6 4"        # Mixed valid and invalid input
alias basic_7="vg_all ./push_swap a b c"                   # Non-numeric input
alias basic_8="vg_all ./push_swap 1 2 2 3"                 # Repeated numbers
alias basic_9="vg_all ./push_swap -1 -2 -3"                # Negative numbers
alias basic_10="vg_all ./push_swap 2147483647 -2147483648" # INT_MAX and INT_MIN
alias basic_11="vg_all ./push_swap 1 2 3 4 5 6 7 8 9 10"  # Large sorted input
alias basic_12="vg_all ./push_swap 10 9 8 7 6 5 4 3 2 1"  # Large reverse-sorted input
alias basic_13="vg_all ./push_swap 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" # Very large input
alias basic_14="vg_all ./push_swap 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30" # Even larger input
alias basic_15="vg_all ./push_swap 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40" # Very large input
alias basic_16="vg_all ./push_swap 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50" # Very large input


for i in {1..16}; do
	alias_name="basic_$i"
	echo -e "${YELLOW}running $alias_name... ${RESET}"
	${!alias_name} > /tmp/memory 2>&1
	echo $exit_status
	if [[ $exit_status -eq 42 ]] || grep -q "still" /tmp/memory; then
		echo -e "${RED}${BOLD}case $alias_name leaked!${RESET}"
		echo -e "${RED}stopping the script!${RESET}"
		break
	else
		echo -e "${GREEN}${BOLD}case $alias_name no leaks!${RESET}"
	fi
	< /tmp/memory
done

