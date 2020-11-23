#! /bin/bash

echo "start"
#pkill NewsRSS
sleep "5"
cd /home/pi/NewsRSS/assets
curl http://feeds.bbci.co.uk/news/rss.xml > /home/pi/NewsRSS/assets/example.txt
cd /home/pi/NewsRSS/assets/
./parsetest
echo "latest rss"
cd /home/pi/NewsRSS/build/
./NewsRSS

echo "done"

