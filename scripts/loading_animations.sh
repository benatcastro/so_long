#!/bin/bash

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
