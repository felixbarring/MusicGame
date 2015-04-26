cd ..
cd ..
if [ -d $Eclipse];
then
	echo "Removing Folder: Eclipse"
	rm -r Eclipse
fi
cd Eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" ../MusicGame
cd ../MusciGame
