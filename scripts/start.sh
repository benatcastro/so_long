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
		map=map1.ber
		start_so_long $1
		check=1
		;;
		2)
		clear
		map=bonus_map.ber
		start_so_long $1
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
		./execs/so_long maps/$map
		pkill afplay
	elif [[ $1 == bonus ]]
	then
		afplay audio/main_theme.wav &
		./execs/so_long_bonus maps/$map
		pkill afplay
	fi
}

