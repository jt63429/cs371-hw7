#!/bin/bash

echo "System Health Report for $(date)"

echo "Disk Usage:"
df -h  # Provides disk usage statistics in human-readable format

echo "CPU Load:"
uptime # Shows the current CPU load

echo "Checking for high CPU load..."
cpu_load=$(uptime | awk -F '[a-z]:' '{ print $2 }' | awk '{ print $1 }' | sed 's/,//g') 
high_load=1.00

if (( $(echo "$cpu_load > $high_load" | bc -l) )); then
	echo "High CPU load detected: $cpu_load"
else
	echo "CPU load is normal: $cpu_load"
fi
