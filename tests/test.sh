# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 16:17:43 by vketteni          #+#    #+#              #
#    Updated: 2023/12/22 13:31:44 by vketteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 	credits: 
#	https://github.com/Glagan/42-ft_printf/blob/master/test.sh 

make
# ft_printf test
printf "\e[1;32mCompile\n"
gcc -Wall -Wextra -Werror -D IS_FT -L. -I. tests/main.c -o ft_printf -lftprintf
./ft_printf > test_ft_printf 2> /dev/null &
printf "\e[1;33mLeaks ? "
leaks ft_printf > leaks.res 2> /dev/null
show_leaks=0
if grep "ROOT LEAK" < leaks.res > /dev/null 2> /dev/null ; then
	printf "\e[0;31mLEAKS\n\e[0m"
	show_leaks=1
else
	printf "\e[0;32mNO LEAKS\n\e[0m"
fi
pid=$( pgrep ft_printf )
kill -9 $pid
wait $pid 2>/dev/null
cat -e test_ft_printf > test_ft_printf.res
# printf test
gcc -Wall -Wextra -Werror tests/main.c -o printf
./printf > test_printf
cat -e test_printf > test_printf.res
# diff
printf "\e[1;36mResult\n\e[0;36m"
if [[ $1 = "f" ]] || [[ $1 = "full" ]]; then
	diff -y --text test_printf.res test_ft_printf.res
else
	diff -y --suppress-common --text test_printf.res test_ft_printf.res
	rm -f test_printf.res test_ft_printf.res
fi
rm -f ft_printf printf
rm -f test_printf test_ft_printf
# leaks result
if [[ $show_leaks = 1 ]]; then
	printf "\e[1;31mLeaks Result\ne[1;30m"
	cat leaks.res
fi
rm -f leaks.res
printf "\e[1;32mDone\n\e[0m"