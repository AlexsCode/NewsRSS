#! /bin/bash

echo "start"
cd /home/pi/NewsRSS/assets/
Curl http://feeds.bbci.co.uk/news/rss.xml > /home/pi/NewsRSS/assets/example.txt
cd /home/pi/NewsRSS/assets/
./parsetest
echo "latest rss"
echo "done"

