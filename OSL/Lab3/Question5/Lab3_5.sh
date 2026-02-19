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
