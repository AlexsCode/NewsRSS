#! /bin/bash

echo "start"
#sudo startx &
#sleep 10
Curl http://feeds.bbci.co.uk/news/rss.xml > /home/pi/NewsRSS/assets/example.txt
cd /home/pi/NewsRSS/assets/
./parsetest
echo "latest rss"
cd /home/pi/NewsRSS/build/
./NewsRSS
sleep 20
echo "done"

