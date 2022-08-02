#!/bin/bash

#source scripts/main.sh
HEADER="
 _______  _______          ___      _______  __    _  _______
|       ||       |        |   |    |       ||  |  | ||       |
|  _____||   _   |        |   |    |   _   ||   |_| ||    ___|
| |_____ |  | |  |        |   |    |  | |  ||       ||   | __
|_____  ||  |_|  |        |   |___ |  |_|  ||  _    ||   ||  |
 _____| ||       | _____  |       ||       || | |   ||   |_| |
|_______||_______||_____| |_______||_______||_|  |__||_______|
"

map_selector()
{
check=0
while [ $check = 0 ]
do
	clear
	printf "\r%s\n\n" "${HEADER}"
	printf "%s%s\n\n""[2] Scape from VIM" "[1] Dungeons and TIGs"
	printf "\n\n\t"
	printf "Map: "
	read answear
	case "$answear" in
		1)
		clear
		start_so_long mandatory
		check=1
		;;
		2)
		start_so_long bonus
		check=1
		;;
		q)
		exit
		;;
		*)
	esac
done
}

start_so_long()
{
	if [[ $1 == mandatory ]]
	then
		afplay audio/main_theme.wav &
		make run
		pkill afplay
	elif [[ $1 == bonus ]]
	then
		echo "test Bonus"
	fi
}

