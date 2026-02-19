#5. Write a program to copy all the files (having file extension input by the user) in the
#current folder to the new folder input by the user. ex: user enter .text TEXT then all
#files with .text should be moved to TEXT folder. This should be done only at single
#level. i.e if the current folder contains a folder name ABC which has .txt files then
#these files should not be copied to TEXT.
echo "Enter file extension (e.g., .text): "
read ext
echo "Enter destination folder name: "
read dest

# Create destination folder if it doesn't exist
mkdir -p "$dest"

# Copy all files with given extension from current directory only (no recursion)
for file in *"$ext"; do
    if [ -f "$file" ]; then
        cp "$file" "$dest/"
        echo "Copied: $file → $dest/"
    fi
done

echo "Done!"
