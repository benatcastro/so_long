#!/bin/bash

source scripts/loading_animations.sh
source scripts/start.sh
trap BLA::stop_loading_animation SIGINT

BLA_so_long=(
					0.1
					'█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'█████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'███████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'█████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'██████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'██████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'███████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'█████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'██████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'███████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒'
					'████████████████████▒▒▒▒▒▒▒▒▒▒▒▒'
					'█████████████████████▒▒▒▒▒▒▒▒▒▒▒'
					'██████████████████████▒▒▒▒▒▒▒▒▒▒'
					'███████████████████████▒▒▒▒▒▒▒▒▒'
					'████████████████████████▒▒▒▒▒▒▒▒'
					'█████████████████████████▒▒▒▒▒▒▒'
					'██████████████████████████▒▒▒▒▒▒'
					'███████████████████████████▒▒▒▒▒'
					'████████████████████████████▒▒▒▒'
					'█████████████████████████████▒▒▒'
					'██████████████████████████████▒▒'
					'███████████████████████████████▒'
					'████████████████████████████████'
						)
HEADER="
 _______  _______          ___      _______  __    _  _______
|       ||       |        |   |    |       ||  |  | ||       |
|  _____||   _   |        |   |    |   _   ||   |_| ||    ___|
| |_____ |  | |  |        |   |    |  | |  ||       ||   | __
|_____  ||  |_|  |        |   |___ |  |_|  ||  _    ||   ||  |
 _____| ||       | _____  |       ||       || | |   ||   |_| |
|_______||_______||_____| |_______||_______||_|  |__||_______|
"




print_header()
{
	printf "%s\n\n" "${HEADER}"
	printf "\t\t        LOADING\n"
}

print_header
BLA::start_loading_animation "${BLA_so_long[@]}"
make>logs
afplay audio/sega.wav &
BLA::stop_loading_animation
clear
check=0
while [ $check = 0 ]
do
	clear
	printf "\r%s\n\n" "${HEADER}"
	printf "Press '1' for mandatory | Press '2' for bonus | Press 'q' to exit\n\n\t\t        Your input:"
	read answear
	case "$answear" in
		1)
		clear
		map_selector
		check=1
		;;
		2)
		map_selector
		check=1
		;;
		q)
		exit
		;;
		*)
	esac
done


