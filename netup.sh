#!/bin/bash

### BEGIN INIT INFO
# Provides:          netup.sh
# Required-Start:    $all
# Required-Stop:     $all
# Default-Start:
# Default-Stop:
# Short-Description: check that the network is up during boot up Ubuntu
# Description:       net is up or not
### END INIT INFO

now=$(date +"%T")

# check 1: Ping - when is not blocked by the firewall
if ping -q -c 1 -W 1 8.8.8.8 >/dev/null; then
    echo "The network is up //checked by ping - $now" >> ~/info_net_up.txt
else
    echo "The network is down //checked by ping - $now" >> ~/info_net_up.txt
fi

# check 2: 'Port scan' (443 -> HTTPS) - when the ping is blocked by the firewall
if nc -zw 1 8.8.8.8 443; then
    echo "The network is up //checked by port 443 scan -  $now" >> ~/info_net_up.txt
else
    echo "THe network is down //checked by port 443 scan - $now" >> ~/info_net_up.txt
fi

# status of the network after start up is placed in te info_net_up.txt file
# in the home directory
