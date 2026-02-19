echo "Enter file name or directory name: "
read name
if [ -f "$name" ]; then
	echo "It is file"
elif [ -d "$name" ]; then
	echo "It is directory"
else
	echo "Neither file nor directory"
fi