#!/bin/bash
#Author: Bryce Hutton
#4/11/2018

if [ "$#" -lt 1 ]; then 
    echo "The usage of thiscommand is backup.sh [options] targetFileList"
    exit 0
fi

boolhelp=false
booll=false
booln=false

#Check to see if arguments contain commands
for var in "$@"
do
    if [ "$var" = "--help" ]; then
	boolhelp=true
    elif [ "$var" = "-l" ]; then
	booll=true
    elif [ "$var" = "-n" ]; then
	booln=true
    elif [ "$var" = "-ln" ]; then
	booln=true
	booll=true
    elif [ "$var" = "-nl" ]; then
	booln=true
	booll=true
    fi

done

for var in "$@"
do
	#if file
    if [ -f "$var" ] || [ -d "$var" ]; then
	mkdir -p ~/.backup && cp $var ~/.backup -r
    elif [ "$var" != "--help" ] || [ "$var" != "-n" ] || [ "$var" != "-l" ] || [ "$var" != "-ln" ] || [ "$var" != "-nl" ]; then
	echo "Must enter a valid filename."
    fi
    
done

if [ "$booll" = true ]; then
    echo "Files in backup:"
    ls ~/.backup -R
fi

if [ "booln" = true ]; then
    echo "Number of Files:"
    ls ~/.backup -R -p | grep -v / | wc -l
    echo "Number of Bytes:"
    ls ~/.backup -R | wc -c
fi

if [ "$boolhelp" = true ]; then
    echo "Backup.sh is used to back up files"
    echo "Format is: backup.sh [options] targetFileList"
    echo "Adding -l will display a list of files in backup"
    echo "Adding -n will display number of files in backup as well as memory in bytes"
    echo "Adding --help will display this screen again"
fi
