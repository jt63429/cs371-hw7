#!/bin/bash

output_file="error_counts.txt"

for file in /var/log/*.txt; do
    count=$(grep -ic "error" "$file")
    echo "$file: ${count:-0}" >> "$output_file"
done

echo "Script executed and output moved to $output_file."
