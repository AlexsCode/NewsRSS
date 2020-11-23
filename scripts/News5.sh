#! /bin/bash
while true; do
cd /home/pi/NewsRSS/assets
curl http://feeds.bbci.co.uk/news/rss.xml > /home/pi/NewsRSS/assets/example.txt
cd /home/pi/NewsRSS/assets/
./parsetest 
#echo "latest rss" > /home/pi/NewsRSS/o.txt
cd /home/pi/NewsRSS/build/
./NewsRSS &
sleep 1800
pkill NewsRSS
#echo "done"> /home/pi/NewsRSS/o.txt

done
echo "exit"
