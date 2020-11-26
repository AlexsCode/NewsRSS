#! /bin/bash
while true; do #Starts a constant while loop.
cd /home/pi/NewsRSS/assets # moves to the correct/assets directory.
curl http://feeds.bbci.co.uk/news/rss.xml > /home/pi/NewsRSS/assets/example.txt #curl saves from url into text file
./parsetest #runs the parser to shift through .txt file to look for headlines
cd /home/pi/NewsRSS/build/ #moves to the build directory
./NewsRSS & #launches the GUI as a background process
sleep 1800 #creates a 30 minute pause in the loop-allows for gui to display all headlines
pkill NewsRSS #kills the GUI process and prepares loop for re-entry

done #end loop
echo "exit" #shows loop has exited. this shouldn't be reached.
