#2. Write a shell script to list all files (only file names) containing the input pattern
(string) in the folder entered by the user.
echo "Enter folder path: " 
read folder
echo "Enter pattern: "
read pattern
##if [ ! -d "$folder" ]; then
##	echo "Invalid dir"
##	exit 1
##fi
echo "Files containing '$pattern':"
grep -r -l -s "$pattern" "$folder"   
