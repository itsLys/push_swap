#!/bin/bash

export YELLOW='\033[1;33m'
export BOLD='\033[1m'
export GREEN='\033[0;32m'
export RED='\033[0;31m'
export RESET='\033[0m' 

	

if norminette > /tmp/norm; then
	echo -e "norminette		${GREEN}${BOLD}[OK]${RESET}"
	NORM=0
else
	echo -e "norminette		${RED}${BOLD}[KO]${RESET}"
	NORM=1
fi

make > /dev/null 2>&1 
if [ $? -eq 0 ]; then
	echo -e "make			${GREEN}${BOLD}[OK]${RESET}"
	MAKE=0
else
	echo -e "make			${RED}${BOLD}[OK]${RESET}"
	MAKE=1
fi


if [ "$MAKE" = 0 ]; then
	./memory.sh
fi


# < /tmp/norm grep "Error"
# rm -f /tmp/norm
