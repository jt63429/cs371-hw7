#!/bin/bash
# Local variables
MY_VAR="Log File Count, Perms"
MY_COUNT=0
# Environmental variables
export MY_ENV_VAR="Environmental Variable"
export MY_LOG_DIR="/var/log"
# Initial message
echo "$MY_VAR"
echo "Environmental Variable: $MY_ENV_VAR"
# if statement to check if a log directory exists
if [ -d "$MY_LOG_DIR" ]; then
	echo "Directory $MY_LOG_DIR exists."
else
	echo "Directory $MY_LOG_DIR does not exist."
	exit 1
fi  #ends the if statement
# Outputs an organized list of all the files in /var/log and their permissions
echo -e "\nFiles in $MY_LOG_DIR with their permissions:\n"
# for loop to go over each item in the directory 
for file in "$MY_LOG_DIR"/*; do # do starts the commands that are to be executed for each item
	# if the item is a file...
	if [ -f "$file" ]; then
		perms=$(ls -l "$file" | awk '{print $1}') # get the perms of the file...
		echo "File: $file - Permissions: $perms" # and print the file name and its perms
		MY_COUNT=$((MY_COUNT + 1))
	fi
done # ends the for loop
# Printing the number of files
echo -e "\nTotal numbers of files in $MY_LOG_DIR: $MY_COUNT"
