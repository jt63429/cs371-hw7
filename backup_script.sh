#!/bin/bash

backup_dir="$1"
backup_destination="/backup"

if [ ! -d "$backup_dir" ]
then
	echo "Error: The directory '$backup_dir' does not exist."
	exit 1
fi

timestamp=$(date +"%Y%m%d%H%M")

backup_file="backup-$timestamp.tgz"

echo "Backing up $backup_dir to $backup_destination/$backup_file"
echo "Backup started at $(date)"
echo

tar czfP $backup_destination/$backup_file $backup_dir

echo
echo "Backup finished at $(date)"
echo "Backup saved to $backup_destination/$backup_file"

