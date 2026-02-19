#4. Write a shell script to calculate the gross salary. GS=Basics + TA + 10% of Basics.
# Floating point calculations has to be performed.
echo "Enter Basic Salary: "
read basic

# Calculate using bc for floating point
ta=$(echo "$basic * 0.1" | bc -l)           # TA = 10% of Basic
gs=$(echo "$basic + $ta" | bc -l)          # GS = Basic + TA

echo "Basic Salary: $basic"
echo "Travel Allowance (TA): $ta"
echo "Gross Salary (GS): $gs"
