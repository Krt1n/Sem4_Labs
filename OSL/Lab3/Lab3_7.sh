#7. Write a shell script which deletes all the even numbered lines in a text file.
echo "Enter filename: "
read -r filename

# Strip whitespace and check if file exists BEFORE sed
filename=$(echo "$filename" | xargs)

if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' not found."
    exit 1
fi

# Now safe to run sed
sed '0~2d' "$filename" > temp.txt && mv temp.txt "$filename"
echo "Even numbered lines deleted from $filename"

