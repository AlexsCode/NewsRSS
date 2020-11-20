#! /bin/bash

echo "start"
sudo startx &
sleep 10
curl http://feeds.bbci.co.uk/news/rss.xml >example.txt
</home/pi/Newsroom>./parsetest
echo "latest rss"
#</home/pi/QT/build-NewsRSS-Desktop-Release>sudo ./NewsRSS
./NewsRSS
sleep 20
echo "done"

