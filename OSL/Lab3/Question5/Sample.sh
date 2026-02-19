echo "Enter value of a and b"
read a b
echo value of a is $a 
echo "value of b is $b"
echo "Enter operator (+,-,*,/.%)"
read op 
sol=$((a $op b))
echo "Result: $sol"

c=$(expr $a + $b)
echo $c 

d=$((a+b))
echo $d

result=$[c == d]
echo $result #1 is true, 0 is False -  Bracket basically a test condition

read char 
if [ "$char"="2" ]; then
	echo "You win"
fi

