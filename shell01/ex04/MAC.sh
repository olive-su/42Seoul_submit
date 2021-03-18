ifconfig -a | grep -w ether | awk -F " " '{print $2}'
