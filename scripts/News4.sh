#! /bin/bash
cd /home/pi/NewsRSS/build/
./NewsRSS &
sleep 30
pkill NewsRSS
