#This script replaces "ex:" with "Example:" in all files in current folder ONLY
#when "ex:" appears at start of line (^ex:) or after period (. Example:)
#Does NOT replace "ex:" in middle of sentences.


# Process all regular files in current directory only (no recursion)
for file in *; do
    if [ -f "$file" ]; then
        echo "Processing: $file"
        
        sed -i 's/^ex:/Example:/g' "$file" # Replaces "ex:" at start of line (^ex:)

        sed -i 's/\. Example:/\. Example:/g' "$file" # Replaces ". Example:" with ". Example:" (after period + space)
        
        echo "Updated: $file"
    fi
done

echo "All files processed!"
