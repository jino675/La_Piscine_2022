#!/bin/sh

echo "========================================================="
tail -c 10 a q a
echo "******************"
./ft_tail -c 10 a q a
echo "========================================================="
tail -c 10 q a a
echo "******************"
./ft_tail -c 10 q a a
echo "========================================================="
tail -c 10 q q a q
echo "******************"
./ft_tail -c 10 q q a q
echo "========================================================="
tail -c 10 a a q a
echo "******************"
./ft_tail -c 10 a a q a
echo "========================================================="
tail -c 999999999999999999 a
echo "******************"
./ft_tail -c 999999999999999999 a
echo "========================================================="
echo "\n\n\n\n\r" | xargs tail -c 5
echo "******************"
echo "\n\n\n\n\r" | xargs ./ft_tail -c 5
echo "========================================================="
tail -c 999999999999999999
echo "******************"
./ft_tail -c 999999999999999999
echo "========================================================="
echo "dsfsdfds\n\r" | xargs tail -c 0
echo "******************"
echo "dsfsdfds\n\r" | xargs ./ft_tail -c 0
echo "========================================================="
echo "a\nbc\n\r" | xargs tail -c 5 
echo "******************"
echo "a\nbc\n\r" | xargs ./ft_tail -c 5
echo "========================================================="
echo "\n\n\n\n\n\n\n\n\n\n\r" | xargs tail -c 5 
echo "******************"
echo "\n\n\n\n\n\n\n\n\n\n\r" | xargs ./ft_tail -c 5
echo "========================================================="
