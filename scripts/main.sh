#!/bin/bash

BLA_so_long=(
					0.25
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

declare -a BLA_active_loading_animation

BLA::play_loading_animation_loop() {
  while true ; do
	for frame in "${BLA_active_loading_animation[@]}" ; do
		printf "\r\t    %s" "${frame}"
		sleep "${BLA_loading_animation_frame_interval}"
	done
  done
}

BLA::start_loading_animation() {
  BLA_active_loading_animation=( "${@}" )
  # Extract the delay between each frame from array BLA_active_loading_animation
  BLA_loading_animation_frame_interval="${BLA_active_loading_animation[0]}"
  unset "BLA_active_loading_animation[0]"
  tput civis # Hide the terminal cursor
  BLA::play_loading_animation_loop &
  BLA_loading_animation_pid="${!}"
}

BLA::stop_loading_animation() {
  kill "${BLA_loading_animation_pid}" &> /dev/null
  printf "\n"
  tput cnorm # Restore the terminal cursor
}

printf "%s\n\n" "${HEADER}"
printf "\t\t        LOADING\n"
BLA::start_loading_animation "${BLA_so_long[@]}"
sleep 7.75s
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
		make run
		check=1
		;;
		2)
		clear
		make run
		check=1
		;;
		q)
		exit
		;;
		*)
	esac
done
sleep 1m






