#Write a shell script to replace all files with .txt extension with .text in the current di-
#rectory. This has to be done recursively i.e if the current folder contains a folder
#“OS” with abc.txt then it has to be changed to abc.text ( Hint: use find, mv )
#echo "Finding all .txt files to rename to .text..."

find . -name "*.txt" | while read file; do  # Find all .txt files and rename them
    if [ -f "$file" ]; then
        newfile="${file%.txt}.text"
        mv "$file" "$newfile"
        echo "Renamed: $file -> $newfile"
    fi
done

echo "All done!"


