#!/bin/bash
build_application()
{
	printf "%s\n" "are you going to build application y/n"
	read ans

	if [ $ans =  y ]
	then 
		if (make clean -C ../application)
		then
			printf "%s\n" "earliar make cleaned"
		fi
		if (make -C ../application)
		then
			printf "%s\n" "Application build Succesfully"
			if (mv ../application/app ../ )
			then 
				printf "%s\n" "app moved from Parent Dir"
			fi
		else
			printf "%s\n" "Application build failed"
		fi
		
	elif [ $ans =  n ]
	then 
		printf "%s\n" "recevied no for build application"
		exit
	fi
}

