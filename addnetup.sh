#!/bin/bash

# add line to crontab for start script 'netup.sh' during boot up
newline="@reboot $(pwd)/netup.sh"
(crontab -l; echo "$newline") | crontab -

#made executable
sudo chmod u+x $(pwd)/netup.sh

