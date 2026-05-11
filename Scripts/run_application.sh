#!/bin/bash
run_application()
{

	printf "%s\n" "are you going to run application give y/n"
	read ans

	if [ $ans = y ]
	then
		mknod /dev/myDev c $1 0 
		if ( ../app )
		then
			printf "%s\n" "application_run successfully\n"
		else
			printf "%s\n" "application_run failed\n"
		fi
	elif [ $ans = n ]
	then 
		printf "%s\n" "received no for Application run"
	fi
}
